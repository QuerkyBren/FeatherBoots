#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct stringArray
{
    char *string;

}stringArray;

const char delim[2] = " ";

int string_to_array(char *filecontents)
{
    char *token;
    token = strtok(filecontents, delim);

    int i;
    int dirtyContentsLength;
    stringArray newContents[100];

    for(i = 0; i < 100; i++)
    {
        newContents[i].string = "";
    }

    i = 0;

    while (token != NULL)
    {
        newContents[i].string = token;
        i++;
        token = strtok(NULL, delim);
    }

    return newContents;
}

int open_file(char filename[30])
{
    char *file_contents;
    long input_file_size;
    FILE *input_file = fopen(filename, "rb");
    fseek(input_file, 0, SEEK_END);
    input_file_size = ftell(input_file);
    rewind(input_file);
    file_contents = malloc(input_file_size * (sizeof(char)));
    fread(file_contents, sizeof(char), input_file_size, input_file);
    fclose(input_file);

    return file_contents;
}

int lex(char filecontents[30])
{
    char *tok = "";
    int state = 0;
    char *string = "";

}

int main(int argc, char *argv[] )
{
        const char *cleanContents;
        char *messyContents;
        char input[30];
        printf("What is the filename? ");
        scanf("%s", input);
        messyContents = open_file(input);
        cleanContents = string_to_array(messyContents);

        int contentsLength = sizeof(cleanContents) / sizeof(cleanContents[0]);
        int i;
        for(i = 0; i < contentsLength; i++)
        {
            printf("%s\n", cleanContents[i]);
        }

        printf("Done");
        return 0;


}
