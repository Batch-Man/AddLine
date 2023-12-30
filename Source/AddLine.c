#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define BUFFER_SIZE 16384

void Help()
{
    printf("\nWrite/Add a line in a text file...\nv1.0 Created by Kvc - www.batch-man.com\n");
    printf("\n");
    printf("\nSyntax:");
    printf("\nCall AddLine [File] [LineNumber] [NewLineContent]\n");
    printf("\n");
    return;
}

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        fprintf(stderr, "Error: missing arguments\n");
        Help();
        return 1;
    }
    char *file_open = argv[1];
    if (!strcmp(file_open, "/?"))
    {
        Help();
        return 0;
    }

    /* File pointer to hold reference of input file */
    FILE *fTemp, *fOut;
    int i = 0, j = 0;

    char buffer[BUFFER_SIZE];
    fTemp = fopen(file_open, "r");
    if (fTemp == NULL)
    {
        fprintf(stderr, "%s: %s", file_open, strerror(errno));
        return errno;
    }
    fOut = fopen(".temp", "w");

    /* fopen() return NULL if unable to open file in given mode. */

    int count = 0;

    while ((fgets(buffer, BUFFER_SIZE, fTemp)) != NULL)
    {
        /* If current line is line to read */
        if (++count == atoi(argv[2]))
        {
            int len = strlen(argv[3]);
            argv[3][len] = '\n';
            argv[3][len + 1] = '\0';
            argv[3][len + 2] = '\0';
            fputs(argv[3], fOut);
            fputs(buffer, fOut);
        }
        else
        {
            fputs(buffer, fOut);
        }
    }

    fclose(fTemp);
    fclose(fOut);

    remove(file_open);
    rename(".temp", file_open);

    return 0;
}
