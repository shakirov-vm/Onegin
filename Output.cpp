#include "Header.h"

const char output[] = "Output.txt";

void PrintSort (struct LineInfo* Line, char* Text, int sum_string)
{
    FILE* potok = NULL;

    if ((potok = fopen(output, "r+")) == NULL)
    {
        printf("Failed to open output file.\n");
        free(Text);
    }

    for (int i = 0; i <= sum_string; i++)
    {
        fprintf(potok, "%s\n", Line[i].index + 1);
    }
    fprintf(potok, "\n********************************************************************************\n");

    fclose(potok);
}
void PrintRevSort (struct LineInfo* Line, char* Text, int lenght, int sum_string)
{
    FILE* potok = NULL;

    if ((potok = fopen(output, "a")) == NULL)
    {
        printf("Failed to open output file.\n");
        free(Text);
    }

    for (int i = 0; i <= sum_string; i++)
    {
        fprintf(potok, "%s\n", Line[i].index + 1);
    }

    for (int i = 0; i < lenght; i++)
    {
        if (Text[i] == '\0') Text[i] = '\n';
    }

    fprintf(potok, "\n=========================================================================\n");

    fclose(potok);
}
void TextPrintf(char* Text)
{
    FILE* potok = NULL;

    if ((potok = fopen(output, "a")) == NULL)
    {
        printf("Failed to open output file.\n");
        free(Text);
    }

    fprintf(potok, "\n%s", Text);

    fclose(potok);
}