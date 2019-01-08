#!/usr/bin/perl

if (defined $ARGV[0]) {
    docs($ARGV[0]);
} else {
    @files = <*.h>;
    foreach $file (@files) {
      docs($file);
    }
}

sub docs {
    my $file = shift @_;
    open IN,$file;
    while (<IN>) {
        if (/\*\*\* Name:\s*(\w+)/) {
             $name = $1;
        } elsif (/\*\*\* Proto:\s*(\w+)(.*)/) {
             $proto_name = $1;
             $proto_args = $2;
             print "### $1$2\n";
        } elsif (/\*\*\* Arg:\s*([^\s]+)\s+(.*)/) {
             $arg_id = $1;
             $arg_description = $2;
        } elsif (/\*\*\* Returns:\s+(.*)/) {
        } elsif (/\*\*\* Notes:\s+(.*)/) {
        } elsif (/\*\*\* Example:\s+(.*)/) {
        } elsif (/\*\*\* Description:\s+(.*)/) {
             print "    $1\n";
        } elsif (/\*\*\*\s+(.*)/) {
             print "    $1\n";
        }
    }
    close IN;
}


