#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"
#include <ctype.h>

//GREP_____________________________--------------------------------------------------------
int wordcomp(char s1[], char s2[])
{
    int i,j;
    char a,b;
    for (i = 0, j = 0; i<strlen(s1) && j<strlen(s2); i++)
    {
        a=s1[i];
        b=s2[j];

        a=tolower(a);
        b=tolower(b);

        if (a == b)
            j++;
        else
            j = 0;
    }
    if (j  == strlen(s2))
        return 1;
    else
        return 0;
}

void i(FILE *ptr, char pattern[])
{
    char line[10000], word[10000];
    int i=0,j=0,k,flag=0;
    while(fgets(line, 100, ptr) != NULL)
    {
	flag=0;
        while(line[i] !='\0' && i < 10000)
        {
            if(line[i] != ' ' || line[i] == '\n')
            {
                word[j] = line[i];
                j++;
            }
            else
            {
                if(wordcomp(word,pattern) == 1 && flag == 0)
                {
                    printf("%s\n", line);
                    flag=1;    
                }
                for(k=0;k<=j;k++)
                    word[k]='\0';
                j=0;
            }
            i++;
        }
    }
}

void w(FILE *ptr, char pattern[])
{
    char line[10000], word[10000];
    int i=0,j=0,k;
    while(fgets(line, 10000, ptr) != NULL)
    {
        while(line[i] !='\0' && i < 10000)
        {   
            if(line[i] != ' ' || line[i] == '\n')
            {
                word[j] = line[i];
                j++;
            }
            else
            {
                if(strcmp(pattern,word)== 0)
                    printf("%s\n", line);
                for(k=0;k<=j;k++)
                    word[k]='\0';
                j=0;
            }
            i++;
        }
    }
}

void v(FILE *ptr, char pattern[])
{
    char line[10000], *index;
    while(fgets(line, 10000, ptr) != NULL)
    {
        index = strstr(line, pattern);
        if (index == NULL)
        {
            printf("%s\n", line);
            continue;
        }
    }
}

void c(FILE *ptr, char pattern[])
{
    int count=0;
    char line[10000], *index;
    while(fgets(line, 10000, ptr) != NULL)
    {
        index = strstr(line, pattern);
        if (index != NULL)
        {
            count++;
            continue;
        }
    }
    printf("%d\n", count);
}

void q(FILE *ptr, char pattern[])
{
    char temp[10000];
     while(!feof(ptr))
        {
                fgets(temp,10000,ptr);
                if(strstr(temp, pattern) != NULL)
                    exit(1);
        }
}

void n(FILE *ptr, char pattern[])
{
    char line[10000], *index;
    int line_no=0;
    while(fgets(line, 10000, ptr) != NULL)
    {
        line_no++;
        index = strstr(line, pattern);
        if (index != NULL)
        {
            printf("%d:%s\n",line_no, line);
            continue;
        }
    }
}

void B(FILE *ptr, char pattern[],int n)
{
    int line_no=0,count=0;
    char line[10000], *index;
    while(fgets(line, 10000, ptr) != NULL)
    {
        line_no++;
        index = strstr(line, pattern);
        if (index != NULL)
            break;
    }
    printf("THE MATCHED LINE\n");
    printf("%d:%s\n",line_no, line);
    printf("LINES AFTER THE MATCHED LINE\n");
    while(fgets(line, 10000, ptr) != NULL)
    {
        line_no++;    
        if(count < n)
        {
            printf("%d:%s\n",line_no, line);
            count++;
        }
    }
}

void o(FILE *ptr, char pattern[])
{
    char line[10000], word[10000];
    int i=0,j=0,k;
    while(fgets(line, 10000, ptr) != NULL)
    {
        while(line[i] !='\0' && i < 10000)
        {       
            if(line[i] != ' ' || line[i] == '\n')
            {
                word[j] = line[i];
                j++;
            }
            else
            {
                if(strcmp(pattern,word)== 0)
                    printf("%s\n", word);   
                for(k=0;k<=j;k++)
                    word[k]='\0';
                j=0;
            }
            i++;
        }
    }
}


// REGEXXXX__________________________________--------------------------------------

void regexstarting(FILE *ptr, char pattern[])
{
    char line[10000];
    int i=0;
    while(fgets(line, 10000, ptr) != NULL)
    {  	
        while(i<strlen(pattern))
        {
            if(line[i] == pattern[i])
            	i++;	
            else
                break;
        }
	if (i == strlen(pattern))
        printf("%s\n", line);      
    i=0;
    }
}

/*void regexending(FILE *ptr, char pattern[])
{
    char line[10000];
    char *s;
    int i,j, flag=0;
    while(fgets(line, 10000, ptr) != NULL)
    {  	
        for(i = strlen(line) - strlen(pattern); i < strlen(line); i++)
        {
            if(line[i] != pattern[j])
            {
              flag = 1;
              break;
            }
            j++;
        }
    if (flag == 0)
      printf("%s\n", line); 
    j = 0;
    }
}*/

void regexending(FILE *ptr, char pattern[])
{   
    char line[10000];
    int i=0;
    strrev(pattern);
    //printf("%s", pattern);
    while(fgets(line, 10000, ptr) != NULL)
    {  	
        strrev(line);
        while(i<strlen(pattern))
        {
            //printf("%c",line[i]);
            //printf("%c", pattern[i]);
            if(line[i] == pattern[i])
            	i++;	
            else
                break;
        }
    //printf("%d", i);
	if (i == strlen(pattern))
        printf("%s\n", strrev(line));    
    i=0;
    }
}

void brac(FILE *fp, char pattern[])
{
    
}