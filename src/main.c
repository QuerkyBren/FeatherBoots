#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int string_to_array(char *filecontents, char target[10][20])
{
    int n=0,i,j=0;

    for(i=0;TRUE;i++)
    {
        if(filecontents[i]!=' '){
            target[n][j++]=filecontents[i];
        }
        else{
            target[n][j++]="\0";
            n++;
            j=0;
        }
        if(filecontents[i]=='\0'){
            break;
        }
    }
    return n;
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
       int n;
        int i;
        char *messyContents;
        char input[30];

        printf("What is the filename? ");
        scanf("%s\n", input);
        printf("Reading Contents...");
        messyContents = open_file(input);
        printf("The original contents are: %s", messyContents);
        printf("Contents Read!");
        printf("Running Lexer...");
        char cleanContents[10][20];
        printf("    Splitting up File Contents...");
        n = string_to_array(messyContents,cleanContents);
        printf("    File Contents Split!")
        printf("    Comparing Words to Dictionary...")
        lex()

        /*printf("The new contents are: \n");
        for(i=0;i<=n;i++){
            printf("%s ",cleanContents[i]);
        }*/

        return 0;

}
