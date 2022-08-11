#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <dirent.h>
#include "help.h"
#include "functions.h"

int main(int argc, char*argv[])
{       
	FILE *fp;
	DIR* FD;
    struct dirent* in_file;
    char temp[10000];
	char *word=(char*)malloc(sizeof(char)*1000);
	char *file=(char*)malloc(sizeof(char)*1000);
	if (argc == 2)
	{
		if (strcmp(argv[1], "--help") == 0)
		{
			help();
		    return 0;
        }

		else
		    printf("Invalid Input");
	}
	else if (argc>2)
	{
	word = strcpy(word, argv[argc-2]);
	file = strcpy(file, argv[argc-1]);
	fp=fopen(file,"r");
	}
	char ch;
	int grepi, grepw, grepv, greph, grepc, grepH, grepq, grepl, grepn, grepB, grepo, grepbrac= 0;
	 
 	if (argv[1][0]  == '-')
	{
		ch = argv[1][1];
		//printf("%c", ch);
		switch(ch)
		{
			case 'i':
				grepi = 1;
				break;
			case 'j':
			    grepbrac = 1;
				break;
			case 'w':
				grepw = 1;
				break;
			case 'v':
				grepv = 1;
				break;
			case 'h':
				greph = 1;
				break;
			case 'c':
				grepc = 1;
				break;
			case 'H':
				grepH = 1;
				break;
			case 'q':
				grepq = 1;
				break; 
			case 'l':
				grepl = 1;
				break;
			case 'n':
				grepn = 1;
				break;
			case 'B':
				grepB = 1;
				break;
			case 'o':
				grepo = 1;
				break;
			default:
				printf("Invalid input");
				exit(1);
		}
	}

	if (argc == 3)
	{
		int wend = strlen(argv[1]);
		if (argv[1][0] == '^')
		{
			char *words = word+1;
		    regexstarting(fp, words);
		}
		if (argv[1][wend-1] == '$')
		{
			word[strlen(word)-1] = '\0';
			//printf("%s", word);
		   regexending(fp, word);
		}
        while(!feof(fp))
        {
                fgets(temp,10000,fp);
                if(strstr(temp, word)!=NULL)
                        printf("%s",temp);
        }
	}

	if (grepi == 1){
		 i(fp, word);
		 grepi = 0;}
	if (grepw == 1){
		 w(fp, word);
		 grepw = 0;}
	if (grepv == 1){
	     v(fp, word);
		 grepv = 0;}
	//else if(greph == 1)
	  //   h(fp, word);
    if(grepc == 1){
	     c(fp, word);
		 grepc = 0;}
	//else if(grepH == 1)
	 //    H(fp, word);
	if(grepq == 1){
	     q(fp, word);
		 grepq = 0;}  
    if(grepn == 1){
		n(fp, word);
		grepn = 0; }
	//else if(grepl == 1)
	  //   l(fp, word);
	if(grepB == 1){
		B(fp, word, 100);
		grepB = 0;
	}
	if(grepo == 1){
		o(fp, word);
		grepo = 0;
	}
	if(grepbrac == 1)
	   // brac(fp, word);
fclose(fp);
}