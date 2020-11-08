#include "Input.h"
#include "Revsort.h"
#include "Sort.h"

int main(int argc, char** argv)  // argc argv
{
    int i = 0;

    char* file_name = argv[0];
 /*   for(i; i < argc; i++)
    {

    } */

    struct stat buff;
    stat("Dig.txt", &buff);
    unsigned long lenght = buff.st_size;

    char* Onegin = (char*) calloc(lenght + 1, sizeof(char));

    FILE* potok;

    potok = fopen("Dig.txt","r+");

    fread(Onegin, sizeof(char), lenght, potok);
    fclose(potok);

    int sum_string = 0;

    for (i = 0; Onegin[i] != '\0'; i++)
    {
        if (Onegin[i] == '\n')
        {
            sum_string++;
        }
    }

    printf("%s\n", Onegin);

    for (i = 0; i < lenght; i++)    {}

    struct LineInfo* Line = (struct LineInfo*) calloc(sum_string, sizeof (Line[0]));

    int j = 1;

    Line[0].index = Onegin;

    for (i = 0; i < lenght; i++)
    {
        if (Onegin[i] == '\n')
        {
            Onegin[i]  = '\0';
            Line[j].index = &Onegin[i+1];

            j++;
        }
    }

    for (i = 0; i <= sum_string; i++)
    {
        for (j = 0; *(Line[i].index + j) != '\0'; j++)  {}
        Line[i].len = j - 1;
    }

    printf("\n================================================================================\n");

    qsoRT(Line, 0, sum_string);

    PrintSorted(Line, sum_string);

    printf("\n********************************************************************************\n");


    RevqsoRT(Line, 0, sum_string);
    //RevqsoRT(Line, 0, sum_string, RevCompare(" ", " ", 0, 0));

    PrintSorted(Line, sum_string);
}
