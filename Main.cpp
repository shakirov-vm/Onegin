#include "Header.h"

int main()
{
    int lenght = LenghtOfFile() + 1;

    char* Text = (char*) calloc (lenght + 1, sizeof(char));

    Text[0] = '\n';

    InputText (Text, lenght); 

    int sum_string = SumString(Text);

    struct LineInfo* Line = (struct LineInfo*)calloc(sum_string, sizeof(struct LineInfo));

    FillStruct(Line, Text, lenght, sum_string);
    
    qsoRT(Line, 0, sum_string, Compare);

    PrintSort(Line, Text, sum_string);
    
    qsoRT(Line, 0, sum_string, RevCompare);

    PrintRevSort(Line, Text, lenght, sum_string);

    TextPrintf(Text);
    
    free(Text);
    
    return 0;
}
