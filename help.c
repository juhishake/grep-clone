#include "help.h"
#include <stdio.h>
#include <stdlib.h>

void help()
{
    printf("\n");
    printf("  DSA-II PROJECT - GREP\n");
    printf("  Juhi Vijayanand Shekokar - 112003072\n");
    printf("\n");
    printf("  Use :  grep [OPTION...] PATTERNS [FILE...]\n");
    printf("  --help : output a usage message and exit\n");
    printf("\n");
    printf("  -w : Select only those lines containing matches that form  whole words.\n");
    printf("  -v : Invert the sense of matching, to select non-matching lines.\n");
    printf("  -i : Ignore case distinctions\n");
	//printf("  -h : Suppress  the  prefixing  of file names on output.\n");
    printf("  -n : Prefix each line of output with  the  1-based  line  number within its input file.\n");
	printf("  -c : print a count  of  matching lines  for  each  input  file.\n");
    //printf("  -H : Print the file name for each match. \n");
    printf("  -B : Prints all lines after matched line\n");
    printf("  -q : Quiet; do not write  anything  to  standard  output.\n");
    printf("  -o : Print only the matched parts of a matching line, with each such part on a separate output line\n");
    //printf("  -l :  Suppress  normal  output;  instead  print  the name of each input file from  which  output  would  normally  have  been printed.\n");
    printf("\n");
    printf("  Also use Regular Expressions - REGEX\n");
    printf("  ^[Pattern] : Print lines whihc start with pattern\n");
    printf("  [Pattern]$ : Print lines which end with pattern\n");
    printf("  .          : Matches any one character\n");
    printf("  *          : zero or more occurrences of the previous character\n");
}