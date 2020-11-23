#include "Header.h"



void PrintSorted(struct LineInfo* Line, int SumString)
{
    int j = 0;
    for (j; j <= SumString; j++)
    {
        if (*Line[j].index != '\n')
        {
            printf("%s\n", Line[j].index);
        }
    }
}
int Compare(struct LineInfo line_1, struct LineInfo line_2)
{
    if (line_1.len == 1)    return  1;
    if (line_2.len == 1)    return -1;

    int differ = 0;

    int k = 0;

    int i = 0;
    int j = 0;

    for (k = 0; (i != line_1.len + 1) && (j != line_2.len + 1); k++)
    {
        while ((isalpha(*(line_1.index + i)) == 0) && (i < line_1.len)) i++;
        while ((isalpha(*(line_2.index + j)) == 0) && (j < line_2.len)) j++;
        
        differ = *(line_1.index + i) - *(line_2.index + j);

        i++;
        j++;

        if (differ != 0) return differ;
    }
    return 0;
}
int RevCompare(struct LineInfo line_1, struct LineInfo line_2)
{
    int differ = 0;

    if (line_1.len == 1)    return  1;
    if (line_2.len == 1)    return -1;

    int k = 0;

    int i = line_1.len;
    int j = line_2.len;

    for (k = 0; (i != -1) && (j != -1); k++)
    {
        while ((isalpha(*(line_1.index + i)) == 0) && (i > 0)) i--;
        while ((isalpha(*(line_2.index + j)) == 0) && (j > 0)) j--;

        differ = *(line_1.index + i) - *(line_2.index + j);

        i--;
        j--;

        if (differ != 0) return differ;
    }
    return 0;
}

void qsoRT(struct LineInfo* Line, int Begin, int End, int (*Comp) (struct LineInfo, struct LineInfo))
{
    int left = Begin;
    int right = End;

    struct LineInfo pivor;
    pivor.index = Line[(left + right) / 2].index;
    pivor.len = Line[(left + right) / 2].len;

    int change_len = 0;
    char* change_index = nullptr;

    while (left <= right)
    {
        while (Comp(Line[left], pivor) < 0)
        {
            left++;
        }
        while (Comp(pivor, Line[right]) < 0)
        {
            right--;
        }

        if (left <= right)
        {
            change_index = Line[left].index;
            Line[left].index = Line[right].index;
            Line[right].index = change_index;

            change_len = Line[left].len;
            Line[left].len = Line[right].len;
            Line[right].len = change_len;

            left++;
            right--;
        }
    }
    if (Begin < right)
        qsoRT(Line, Begin, right, Comp);



    if (End > left)
        qsoRT(Line, left, End, Comp);
}
