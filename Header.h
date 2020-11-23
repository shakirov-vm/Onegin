#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <ctype.h>
#include <assert.h>

struct LineInfo
{
    int len;
    char* index;
};

int LenghtOfFile();
void InputText(char* Text, int lenght);
int SumString(char* onegin);
void FillStruct(struct LineInfo* Line, char* Text, int lenght, int sum_string);


void PrintSorted(struct LineInfo* Line, int SumString);
int Compare(struct LineInfo line_1, struct LineInfo line_2);
int RevCompare(struct LineInfo line_1, struct LineInfo line_2);
void qsoRT(struct LineInfo* Line, int Begin, int End, int (*Comp) (struct LineInfo, struct LineInfo));


void PrintSort(struct LineInfo* Line, char* Text, int sum_string);
void PrintRevSort(struct LineInfo* Line, char* Text, int lenght, int sum_string);
void TextPrintf(char* Text);
