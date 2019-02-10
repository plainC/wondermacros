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
    my $in_args = 0;
    while (<IN>) {
        if (/\*\*\* Name:\s*(\w+)/) {
             $name = $1;
        } elsif (/\*\*\* Proto:\s*(\w+)(.*)/) {
             $proto_name = $1;
             $proto_args = $2;
             print "### $1$2\n";
        } elsif (/\*\*\* Arg:\s*([^\s]+)\s+(.*)/) {
             if (not $in_args) {
                 $in_args = 1;
                 print "#### Arguments\n";
                 print "```C\n";
             }
             $arg_id = $1;
             $arg_description = $2;
             printf "%-20s %s\n", $arg_id, $arg_description;
        } elsif (/\*\*\* Returns:\s+(.*)/) {
             print "#### Return Value\n";
             print "$1\n";
        } elsif (/\*\*\* Notes:\s+(.*)/) {
             print "#### Notes\n";
             print "$1\n";
        } elsif (/\*\*\* Example:\s+(.*)/) {
             print "#### Example\n";
             print "```C\n";
             print "$1\n";
             print "```\n";
        } elsif (/\*\*\* Description:\s+(.*)/) {
             if ($in_args) {
                 $in_args = 0;
                 print "```\n";
             }
             print "#### Description\n";
             print "    $1\n";
        } elsif (/\*\*\*\s+(.*)/) {
             print "    $1\n";
        }
    }
    close IN;
}


