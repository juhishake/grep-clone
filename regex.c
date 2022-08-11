#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "help.c"

static int regex_match(const char *input, const char *word, const char ***endp);
static const char *search(const char *input, const char *word, const char **endp)
{
	for (int i = 0; input[i] != '\0'; i++)
    { 
	    if (*word == '^')
        {
            if (regex_match(input + i, word + 1, &endp) == 0)
                return input + i;
            else
                break; 
        }
        if (regex_match(input + i, word, &endp) == 0) 
			return input + i; 
	}
	return NULL; 
}

static int regex_match(const char *input, const char *word, const char ***endp) {

    if (*word == '\0')
    { 
        **endp = input;
        return 0;
    }
    else if (*input == '\0' && *word == '$')
    { 
         **endp = input;
        return 0;
    }
    else if (*(word + 1) == '*')
    { 
        if (*word == *input || *word == '.') 
        { 
            if (*input == '\0') 
                return regex_match(input, word + 2, endp); 
            else if (regex_match(input + 1, word, endp) == 0)
                return 0;
            else 
            {
                if(regex_match(input + 1, word + 2, endp) == 0)
                    return 0;
                else
                    return regex_match(input, word + 2, endp); 
            }
        }
        else
            return regex_match(input, word + 2, endp); 
    }
    else if (*word == '.')
    { 
        if (*input == '\0') 
            return -1;
        else
            return regex_match(input + 1, word + 1, endp); 
    }
    else if (*input != *word) 
        return -1;
    else 
        return regex_match(input + 1, word + 1, endp); 
}

static void print(const char *cur, const char *start, const char *end)
{
	int nbefore = start - cur; 
	int nmatched = end - start;
	printf("%.*s%.*s", nbefore, cur, nmatched, start);
}

static void print_match(const char *line, const char *word, const char *filename)
{
  
    const char *end = NULL;
    const char *start = search(line, word, &end);
	    if (start != NULL)
        {
		    if (filename != NULL)
                printf("%s: ", filename);
		    print(line, start, end);
		    print_match(end, word, filename); 
            if (search(end, word, &end) == NULL)
                printf("%s\n", end);
        }
}

static void grep_file(FILE *fp, const char *word, const char *filename)
{
	char line[10000];
	while (fgets(line, sizeof(line), fp) != NULL)
    {
		if (line[strlen(line)-1] == '\n')
            line[strlen(line)-1] = '\0'; 
		print_match(line, word, filename);
	}
}

int main(int argc, char *argv[])
{
	const char *word = argv[1];
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
		for (int i = 2; i < argc; i++)
        {
	    	FILE *fp = fopen(argv[i], "r");
	    	grep_file(fp,word, argc > 3 ? argv[i] : NULL);
	    	fclose(fp);
	    }
    return 0;
}
