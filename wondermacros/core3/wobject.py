#!/usr/bin/python3

import re
import sys
import enum
import os
import os.path


class Scanner:
    def __init__(self,fileName):
        self.lines = []
        f = open(fileName, "r")
        for line in f:
            self.lines.append(line)
        f.close()
        self.row = 0

    def peek(self):
        return self.lines[self.row]

    def next(self):
        self.row += 1
        while (len(self.lines) > self.row and self.lines[self.row].isspace()):
            self.row += 1

    def is_eof(self):
        return self.row >= len(self.lines)

class Property:
    def __init__(self,type,name,dims):
        self.type = type
        self.name = name
        self.dims = dims

    def write(self,f):
        klass = "NULL"
        keyClass = "NULL"
        klassArg = "NULL"
        # Check if pointer
        matchObj = re.match( r'(\w+)(\**)', self.type)
        if (matchObj):
            elemType = matchObj.group(1)
            starts = len(matchObj.group(2))
            if (starts == 1 and elemType in classes):
                klass = "&%s__class_instance" % (elemType)
        # Check if simple type
        if (self.type in simples):
            klass = "&%s__simple_instance" % (simples[self.type])
        # Check dimensions
        if (self.dims):
            dims = ""
            if (self.dims == "[dynamic]"):
                dims = "&((int[]) { W_CLASS_KIND_DYNAMIC_ARRAY })"
                self.dims = ""
                self.type += "*"
            elif (self.dims == "[stack]"):
                dims = "&((int[]) { W_CLASS_KIND_DYNAMIC_STACK })"
                self.dims = ""
                self.type += "*"
            elif (self.dims == "[deque]"):
                dims = "&((int[]) { W_CLASS_KIND_DEQUE })"
                self.dims = ""
                self.type += "*"
            elif (self.dims[:6] == "[hash:"):
                dims = "&((int[]) { W_CLASS_KIND_HASH })"
                self.dims = ""
                self.type += "*"
                keyClass = "&int__simple_instance" # FIXME
            else:
                matchObj = re.match( r'\[(\d+)\]\[(\d+)\]\[(\d+)\]', self.dims )
                if (matchObj):
                    dims = "&((int[]) { W_CLASS_KIND_STATIC_ARRAY, 3, %s, %s, %s })" % (matchObj.group(1),matchObj.group(2),matchObj.group(3))
                else:
                    matchObj = re.match( r'\[(\d+)\]\[(\d+)\]', self.dims )
                    if (matchObj):
                        dims = "&((int[]) { W_CLASS_KIND_STATIC_ARRAY, 2, %s, %s })" % (matchObj.group(1),matchObj.group(2))
                    else:
                        matchObj = re.match( r'\[(\d+)\]', self.dims )
                        if (matchObj):
                            dims = "&((int[]) { W_CLASS_KIND_STATIC_ARRAY, 1, %s })" % (matchObj.group(1))
            klassArg = dims
        # Print
        print("    VAR(%s, /* name */ \\\n"
                  "        %s, /* C type */ \\\n"
                  "        %s, /* Array dimensions */ \\\n"
                  "        %s, /* Class */ \\\n"
                  "        %s, /* Key class */ \\\n"
                  "        %s /* Class argument */) \\"
                % (self.name,self.type,self.dims,klass,keyClass,klassArg), file=f)

class Method:
    def __init__(self,isMember,type,name,args):
        self.isMember = isMember
        self.type = type
        self.name = name
        self.args = args.strip()

    def write(self,className,f):
        if (not self.args):
            print("    METHODV(%s, /* Class name */ \\\n"
                "        %d, /* Is member */ \\\n"
                "        %s, /* C return type */ \\\n"
                "        %s /* Name */) \\"
                % (className, self.isMember, self.type, self.name), file=f)
        else:
            print("    METHOD(%s, /* Class name */ \\\n"
                "        %d, /* Is member */ \\\n"
                "        %s, /* C return type */ \\\n"
                "        %s, /* Name */ \\\n"
                "        (%s)  /* Arguments */) \\"
                % (className, self.isMember, self.type, self.name, self.args), file=f)

class Signal:
    def __init__(self,name,args):
        self.name = name
        self.args = args

    def write(self,f):
        if (not self.args):
            print("    SIGNALV(%s) \\" % (self.name), file=f)
        else:
            print("    SIGNAL(%s,(%s)) \\" % (self.name,self.args), file=f)

class Klass:
    def __init__(self,name,kind,superName,interfaces):
        self.name = name
        self.kind = kind
        self.superName = superName
        self.interfaces = interfaces
        self.properties = []
        self.methods = []
        self.signals = []
        self.hasConstruct = False
        self.hasDestruct = False

    def writeClassH(self):
        f = open("build/" + self.name,"w")
        print("#define CLASS %s" % (self.name), file=f)
        print("#define KIND %s" % (self.kind), file=f)
        print("#define HAS_CONSTRUCT %d" % (1 if self.hasConstruct else 0), file=f)
        print("#define HAS_DESTRUCT %d" % (1 if self.hasDestruct else 0), file=f)
        print("\n#define %s__define \\" % (self.name), file=f)
        if (self.superName):
            print("    %s__define \\" % (self.superName), file=f)
        if (self.interfaces):
            for name in self.interfaces:
                print("    %s__define \\" % (name), file=f)
        print("    CLASS_NAME(%s) \\" % (self.name), file=f)

        for property in self.properties:
            property.write(f)

        for method in self.methods:
            method.write(self.name,f)

        for s in self.signals:
            s.write(f)

        print("    /**/", file=f)
        f.close()

    def writeH(self,mainName):
        upName = self.name.upper()
        f = open("build/" + self.name + ".h","w")
        print("#ifndef __%s_H" % (upName), file=f)
        print("#define __%s_H\n" % (upName), file=f)
        print("#include \"oo_api.h\"", file=f)
        print("#include \"%s.h\"\n" % (mainName), file=f)

        if (self.superName):
            print("/* Include superclass */", file=f)
            print("#include \"%s.h\"" % (self.superName), file=f)

        if (self.interfaces):
            print("/* Include interfaces */", file=f)
            for interface in self.interfaces:
                print("#include \"%s.h\"" % (interface), file=f)

        print("\n/* Expand header */", file=f)
        print("#define NAME %s" % (self.name), file=f)
        print("#include \"x/class_declare.h\"", file=f)

        print("\n#endif /* __%s_H */" % (upName), file=f)
        f.close()


class Parser:
    def __init__(self,Scanner):
        self.scanner = Scanner
        self.klass = None

    def parse_simple(self,line):
        matchObj = re.match( r'^simple\s+((const\s+)?[\w\*]+)\s*\:\s*(\w+)', line )
        if (matchObj):
            simples[ matchObj.group(1) ] = matchObj.group(3)
            return True
        return False

    def parse_include(self,line):
        matchObj = re.match( r'^\#include\s+(.*)', line )
        if (matchObj):
            includes.append(matchObj.group(1))
            return True
        return False

    def parse_method(self,line):
        matchObj = re.match( r'^\s+(static\s+)?((\w+\s+)*\w+\**)\s+(\w+)\s*\(([^\)]*)\)', line )
        if (matchObj):
            isMember = True
            if (matchObj.group(1)):
                isMember = False
            self.klass.methods.append(Method(isMember,matchObj.group(2),matchObj.group(4),matchObj.group(5)))
            return True
        else:
            return False

    def parse_property(self,line):
        matchObj = re.match( r'^\s+((const\s+)?[\w\*]+)\s+(\w+)(\[.*)?', line )
        if (matchObj):
            arr = ""
            if (matchObj.group(4)):
                arr = matchObj.group(4)
            self.klass.properties.append(Property(matchObj.group(1).rstrip(),matchObj.group(3),arr))
            return True
        return False

    def parse_construct(self,line):
        matchObj = re.match( r'^\s+construct', line )
        if (matchObj):
            self.klass.hasConstruct = True
            return True
        return False

    def parse_destruct(self,line):
        matchObj = re.match( r'^\s+destruct', line )
        if (matchObj):
            self.klass.hasDestruct = True
            return True
        return False

    def parse_signal(self,line):
        matchObj = re.match( r'^\s+signal\s+(\w+)\s*\(([^\)]*)\)', line )
        if (matchObj):
            self.klass.signals.append(Signal(matchObj.group(1),matchObj.group(2)))
            return True
        return False

    def parse_class(self,line):
        matchObj = re.match( r'^class\s+(\w+)\s*(\:\s*\w+)?(.*)', line )
        if (matchObj):
            className = matchObj.group(1)
            superName = matchObj.group(2)
            interfaces = matchObj.group(3)
            if (superName):
                superName = re.sub( r'\:\s*(\w+)', r'\1', superName)
            ifs = []
            if (interfaces):
                while True:
                    matchObj = re.match( r'^\s*\:\+\s*(\w+)(.*)', interfaces )
                    ifs.append(matchObj.group(1))
                    interfaces = matchObj.group(2)
                    if (not interfaces):
                        break
            self.klass = Klass(className,"W_KIND_CLASS", superName,ifs)
            classes[ className ] = self.klass
            return True
        return False

    def parse(self):
        while (not self.scanner.is_eof()):
            line = self.scanner.peek()
            if (self.parse_simple(line)
                or self.parse_construct(line)
                or self.parse_destruct(line)
                or self.parse_include(line)
                or self.parse_class(line)
                or self.parse_signal(line)
                or self.parse_method(line)
                or self.parse_property(line)):
                self.scanner.next()
                continue
            else:
                print ("Parse error: ", self.scanner.row)
                print (line)
                sys.exit(1)


class MainHeader:
    def __init__(self,name):
        self.writeMainHeader(name)

    def writeClassDeclares(self,f):
        print("\n\n/* Classes */\n", file=f)
        for name in classes:
            print("/* Class %s */" % (name), file=f)
            print("struct %s;" % (name), file=f)
            print("struct %s__class;" % (name), file=f)
            print("typedef struct %s %s;" % (name,name), file=f)
            print("typedef struct %s__class %s__class;" % (name,name), file=f)
            print("extern struct %s__class %s__class_instance;" % (name,name), file=f)

    def writeSimpleTypeDeclares(self,f):
        print("\n\n/* Simple types */", file=f)
        for name in simples:
            print("extern struct ClassSimple %s__class_instance;" % (simples[name]), file=f)

    def writeIncludes(self,f):
        for name in includes:
            print("#include %s" % (name), file=f)

    def writeMainHeader(self,name):
        upName = name.upper()
        f = open("build/" + name + ".h","w")
        print("#ifndef __%s_H" % (upName), file=f)
        print("#define __%s_H\n" % (upName), file=f)
        self.writeIncludes(f)
        self.writeClassDeclares(f)
        self.writeSimpleTypeDeclares(f)
        print("\n\n#endif /* __%s_H */" % (upName), file=f)
        f.close()

class Makefile:
    def __init__(self,name):
        self.write(name)

    def write(self,name):
        f = open("build/Makefile","w")
        print("CFLAGS=-g -I .. -I .", file=f)
        print("CLASSESS=\\", file=f)
        for klass in classes:
            print("\t%s \\" % (klass), file=f)
        print("\nOBJS = $(patsubst %,%.o,$(CLASSESS))", file=f)
        print("all : $(OBJS)", file=f)
        print("\tar rc lib%s.a $(OBJS)" % (name), file=f)
        print("\tranlib lib%s.a" % (name), file=f)
        for klass in classes:
            if not os.path.exists("build/%s.c" % (klass)) and os.path.exists("%s.c" % (klass)):
                os.system("ln -s ../%s.c build/%s.c" % (klass,klass))
            print("%s.o: %s.c" % (klass,klass), file=f)
            print("\t$(CC) $(CFLAGS) -c %s.c" % (klass), file=f)
        print("\nclean:", file=f)
        print("\trm -f $(OBJS)", file=f)
        f.close()

if (sys.argv[1][-8:] != ".wobject"):
    print("Error: Usage: wobject.py filename.wobject")
    sys.exit(1)

includes = []
simples = {}
classes = {"Object":None, "Variant":None, "Writer":None, "Reader":None}
scanner = Scanner(sys.argv[1])
parser = Parser(scanner)
parser.parse()
mainName = sys.argv[1].replace(".wobject", "")

if not os.path.exists('build'):
    os.makedirs('build')

mainHeader = MainHeader(mainName)
makefile = Makefile(mainName)

for name in classes:
    klass = classes[name]
    if (klass):
        klass.writeClassH()
        klass.writeH(mainName)
