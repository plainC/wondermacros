#!/usr/bin/python3

import re
import sys
import enum
import os.path


simple = {
    'bool':     'bool',
    'int':      'int32',
    'int32_t':  'int32',
    'unsigned': 'uint32',
    'uint32_t': 'uint32',
    'int64_t':  'int64',
    'uint64_t': 'uint64',
    'float':    'float',
    'double':   'double',
    'char':     'char',
    'char*':    'cstring'
}

classes = {}

class ClassKind(enum.Enum):
    INTERFACE=1
    CLASS=2
    ABSTRACT=3
    SINGLETON=4


class Method:
    def __init__(self,scope,type,name,args=""):
        self.scope = scope
        self.type = type
        self.name = name
        self.args = args

    def print(self,name,f):
        if (self.args == ""):
            print ("    METHOD(%s,%s,%s,%s) \\" % (name,self.scope,self.type,self.name), file=f)
        else:
            print ("    METHOD(%s,%s,%s,%s,(%s)) \\" % (name,self.scope,self.type,self.name,self.args), file=f)

class Var:
    def __init__(self,scope,type,name):
        self.scope = scope
        self.type = type
        self.name = name

    def print(self,f):
        try:
            spec = ",SIMPLE(" + simple[self.type] + ")"
        except:
            spec = ""
        print ("    VAR(%s,%s,%s%s) \\" % (self.scope,self.type,self.name,spec), file=f)


class Class:
    def __init__(self,name,kind,Super,interfaces):
        self.name = name
        self.kind = kind
        self.super = Super
        self.interfaces = interfaces
        self.setting_name = ""
        self.methods = []
        self.vars = []
        self.has_constructor(False)
        self.has_destructor(False)

    def add_method(self,scope,type,name,args=""):
        self.methods.append(Method(scope,type,name,args))

    def add_var(self,scope,type,name):
        self.vars.append(Var(scope,type,name))

    def has_constructor(self,val):
        self.has_constructor = val

    def has_destructor(self,val):
        self.has_destructor = val

    def print_class(self):
        f = open(self.name + "__class.h","w")
        print ("#define CLASS %s" % (self.name), file=f)

        if (self.kind == ClassKind.INTERFACE):
            print ("#define INTERFACE", file=f)
        if (self.kind == ClassKind.ABSTRACT):
            print ("#define ABSTRACT", file=f)
        if (self.kind == ClassKind.SINGLETON):
            print ("#define SINGLETON", file=f)
        if (self.setting_name != ""):
            print ("#define NAME %s" % (self.setting_name), file=f)
        if (self.has_constructor):
            print ("#define HAS_CONSTRUCTOR", file=f)
        if (self.has_destructor):
            print ("#define HAS_DESTRUCTOR", file=f)
        print ("#define %s__define \\" % (self.name), file=f)
        if (self.super != ""):
            print ("    %s__define \\" % (self.super), file=f)
        if (self.interfaces):
            for interface in self.interfaces:
                if (interface != None):
                    print ("    %s__define \\" % (interface), file=f)
        if (self.kind == ClassKind.INTERFACE):
            print ("    INTERFACE_NAME(%s) \\" % (self.name), file=f)
        else:
            print ("    CLASS_NAME(%s) \\" % (self.name), file=f)
        for method in self.methods:
            method.print(self.name, f)
        for var in self.vars:
            var.print(f)
        print ("    /**/", file=f)
        print ("/* Aliases. */", file=f)
        print ("#define %s__private__define %s__define" % (self.name,self.name), file=f)
        for method in self.methods:
            print ("#define %s__%s %s__private__%s" % (self.name, method.name, self.name, method.name), file=f)
        f.close()

    def print_h(self):
        f = open(self.name + ".h","w")
        print("#ifndef __%s_H" % (self.name), file=f)
        print("#define __%s_H" % (self.name), file=f)
        print("#include \"oo_api.h\"", file=f)
        print("/*** Classes in this module */", file=f)
        for klassname in classes:
            print("struct %s; typedef struct %s %s;" % (klassname,klassname,klassname), file=f)
        print("/**/", file=f)
        if (self.super != ""):
            print("/*** Include superclass */", file=f)
            print("#include \"%s.h\"" % (self.super), file=f)
            print("/**/", file=f)
        if (self.interfaces != None):
            print("/*** Include interfaces */", file=f)
            for interface in self.interfaces:
                if (interface != None):
                    print("#include \"%s.h\"" % (interface), file=f)
            print("/**/", file=f)
        print("#include \"%s__class.h\"" % (self.name), file=f)
        print("#include \"oo_expand.h\"", file=f)
        print("#endif", file=f)
        f.close()

    def print_c(self):
        if (not os.path.isfile(self.name + ".c")):
            f = open(self.name + ".c","w")
            print("#define EXTERN", file=f)
            print("", file=f)
            print("#include \"oo_api.h\"", file=f)
            print("", file=f)
            if (self.super != ""):
                print("/*** Include superclass */", file=f)
                print("#include \"%s.h\"" % (self.super), file=f)
                print("/**/", file=f)
            print("/*** Expand %s */" % (self.name), file=f)
            print("#include \"%s__class.h\"" % (self.name), file=f)
            print("#define %s %s__private" % (self.name, self.name), file=f)
            print("#include \"oo_expand.h\"", file=f)
            print("/**/", file=f)
            print("", file=f)
            for method in self.methods:
                print("%s" % (method.type), file=f)
                print("METHOD(%s)(%s* self%s%s)" % (method.name, self.name, "," if (method.args != "") else "", method.args), file=f)
                print("{", file=f)
                print("}", file=f)
                print("", file=f)
            f.close()


    def print(self):
        self.print_class()
        self.print_h()
        self.print_c()


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


class Parser:
    def __init__(self,Scanner):
        self.scanner = Scanner
        self.klass = None

    def parse_interface(self,line):
        matchObj = re.match( r'^interface\s+(\w+)(\s*\:\s*(\w+))?(\s*(\w+))?', line )
        if (matchObj):
            if (not self.klass is None):
                self.klass.print()
            self.klass = Class(matchObj.group(1), ClassKind.INTERFACE, matchObj.group(3) if matchObj.group(3) else "", [matchObj.group(5)])
            classes[matchObj.group(1)] = self.klass
            return True
        else:
            return False

    def parse_class(self,line):
        matchObj = re.match( r'^((abstract)|(singleton)\s+)?class\s+(\w+)(\s*\:\s*(\w+))?((\s*(\w+))*)', line )
        if (matchObj):
            if (not self.klass is None):
                self.klass.print()
            kind = ClassKind.CLASS
            if (matchObj.group(2) == "abstract"):
                kind = ClassKind.ABSTRACT
            if (matchObj.group(3) == "singleton"):
                kind = ClassKind.SINGLETON
            if (matchObj.group(7)):
                interfaces = matchObj.group(7).split()
            else:
                interfaces = []
            self.klass = Class(matchObj.group(4), kind, matchObj.group(6) if matchObj.group(6) else "", interfaces)
            classes[matchObj.group(4)] = self.klass
            return True
        else:
            return False

    def parse_method(self,line):
        matchObj = re.match( r'^\s+((public)|(private))\s+((\w+\s+)*\w+\**)\s+(\w+)\s*\(([^\)]*)\)', line )
        if (matchObj):
            self.klass.add_method(matchObj.group(1),matchObj.group(4),matchObj.group(6),matchObj.group(7))
            return True
        else:
            return False

    def parse_var(self,line):
        matchObj = re.match( r'^\s+((public)|(private)|(readonly))\s+((\w+\s+)*\w+\**)\s+(\w+)', line )
        if (matchObj):
            self.klass.add_var(matchObj.group(1),matchObj.group(5),matchObj.group(7))
            return True
        else:
            return False

    def parse_constructor(self,line):
        matchObj = re.match( r'^\s+construct', line)
        if (matchObj):
            self.klass.has_constructor=True
            return True
        else:
            return False

    def parse_destructor(self,line):
        matchObj = re.match( r'^\s+destruct', line)
        if (matchObj):
            self.klass.has_destructor(True)
            return True
        else:
            return False

    def parse_setting(self,line):
        matchObj = re.match( r'^\s+\[(\w+)]', line )
        if (matchObj):
            self.klass.setting_name = matchObj.group(1)
            return True
        return False

    def parse(self):
        while (not self.scanner.is_eof()):
            line = self.scanner.peek()
            if (not self.klass is None):
                if (self.parse_method(line)):
                    self.scanner.next()
                    continue
                if (self.parse_var(line)):
                    self.scanner.next()
                    continue
                if (self.parse_constructor(line)):
                    self.scanner.next()
                    continue
                if (self.parse_destructor(line)):
                    self.scanner.next()
                    continue
                if (self.parse_setting(line)):
                    self.scanner.next()
                    continue

            if (self.parse_interface(line)):
                self.scanner.next()
                continue
            if (self.parse_class(line)):
                self.scanner.next()
                continue
            else:
                print ("Parse error: ", self.scanner.row)
                print (line)
                sys.exit(1)
        self.klass.print()


scanner = Scanner(sys.argv[1])
parser = Parser(scanner)
parser.parse()
