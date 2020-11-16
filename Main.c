#include "Input.h"
#include "Revsort.h"
#include "Sort.h"

int main(int argc, char** argv)  // argc argv
{
    const char enter_file = "Dig.txt";

    int i = 0;

    char* file_name = argv[1];
 /*   for(i; i < argc; i++)
    {
    } */

    struct stat buff;
    stat("Dig.txt", &buff);
    unsigned long lenght = buff.st_size;

    char* Onegin = (char*) calloc(lenght + 1, sizeof(char));
    if (Onegin == NULL)
    {
        printf ("Fadim snova oblajalsua\n");
        return -1;
    }

    FILE* potok = NULL;
    if ((potok = fopen ("Dig.txt","r+")) == NULL) {
        printf ("Failed to open Dig.txt. LINE: %d\n", __LINE__);
        free (Onegin);
        return -1;
    }

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
        //if (Onegin[i] == '\r') printf("AAAAA!\n");//Onegin[i] = ' '; /// ???????????????????????????/
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

    qsoRT(Line, 0, sum_string, Compare);

    PrintSorted(Line, sum_string);

    if ((potok = fopen("Bury.txt", "w")) == NULL)
    {
        printf ("Failed to open Bury.txt\n");
        free (Onegin);
        return -1;
    }

    const char buf[] = "Lol\n";
    fwrite (buf, sizeof (char), sizeof (buf), potok);

//printf("1");
    //for(i = 0; i <= sum_string / 1000; i++)
    //{
//printf("2");
        //fprintf (potok, "asd");
//printf("3");
    //}

    fclose(potok);

    printf("\n********************************************************************************\n");

    qsoRT(Line, 0, sum_string, RevCompare);

    PrintSorted(Line, sum_string);


}

#if 0
void PrekrasniyPrintF(struct LineInfo* Line, int sum_string)
{
    int i, j;

    for (i = 0; i < sum_string; i++)
    {
        for(j = 0; j <= Line[i].len; j++)
        {
            printf("<%d>", *(Line[i].index + j));
        }
        printf("\tlen - %d\n", Line[i].len);

    }
}
Enter two Sentinels-[first,] Francisco, [who paces up and down at his post; then] Bernardo, [who approaches him].
#endif
