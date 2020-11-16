#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <ctype.h>
#include <assert.h>

void PrintSorted(struct LineInfo *Line, int SumString)
{
    int j = 0;
    for(j; j <= SumString; j++)
    {
        if (*Line[j].index != '\n')
        {
            printf("%s\n", Line[j].index);
        }
    }
}
int Compare (struct LineInfo line_1, struct LineInfo line_2)
{
    //printf("Line_1 - <%s>, len_1 - <%d>\n", line_1, len_1);
    //printf("Line_2 - <%s>, len_2 - <%d>\n", line_2, len_2);

    if (line_1.len == -1)    return  1;
    if (line_2.len == -1)    return -1;

    int differ = 0;

    int k = 0;

    int i = 0;
    int j = 0;

    ///while (isalpha(line_1[i]) == 0) i++;
    ///while (isalpha(line_2[j]) == 0) j++;
///                        +1?
    for (k = 0; (i != line_1.len) && (j != line_2.len); k++)
    {
        while ((isalpha(*(line_1.index + i)) == 0)) i++;
        while ((isalpha(*(line_2.index + j)) == 0)) j++;

        if(i > line_1.len) break;
        if(j > line_2.len) break;

        differ = *(line_1.index + i) - *(line_2.index + j);

        i++;
        j++;

        if (differ != 0) return differ;
    }
    return 0;
}
int RevCompare (struct LineInfo line_1, struct LineInfo line_2)
{
    //printf("Line_1 - <%s>, len_1 - <%d>\n", line_1, len_1);
    //printf("Line_2 - <%s>, len_2 - <%d>\n", line_2, len_2);

    int differ = 0;

    if (line_1.len == -1)    return  1;
    if (line_2.len == -1)    return -1;

    int k = 0;

    int i = line_1.len;
    int j = line_2.len;

    while (isalpha(*(line_1.index + i)) == 0) i--;
    while (isalpha(*(line_2.index + j)) == 0) j--;

    for (k = 0; (i != -1) && (j != -1); k++)
    {
        while (isalpha(*(line_1.index + i)) == 0) i--;
        while (isalpha(*(line_2.index + j)) == 0) j--;

        if(i < 0) break;
        if(j < 0) break;

        differ = *(line_1.index + i) - *(line_2.index + j);

        i--;
        j--;

        if (differ != 0) return differ;
    }
    return 0;
}

void qsoRT (struct LineInfo * Line, int Begin, int End, int (*Comp) (struct LineInfo, struct LineInfo))
{
    int left = Begin;
    int right = End;

    struct LineInfo pivor;
    pivor.index = Line[(left + right) / 2].index;
    pivor.len = Line[(left + right) / 2].len;

    int change_len = 0;
    char* change_index = "";

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
            Line[left].len = Line[ right].len;
            Line[right].len = change_len;

            left++;
            right--;
        }
    }
    if (Begin < right)
        qsoRT (Line, Begin, right, Comp);



    if (End > left)
        qsoRT (Line, left, End, Comp);
}



#if 0
int RevCompare (char* line_1, char* line_2, int len_1, int len_2)
{
    //printf("Line_1 - <%s>, len_1 - <%d>\n", line_1, len_1);
    //printf("Line_2 - <%s>, len_2 - <%d>\n", line_2, len_2);

    int differ = 0;

    if (len_1 == -1)    return  1;
    if (len_2 == -1)    return -1;

    int k = 0;

    int i = len_1;
    int j = len_2;

    while (isalpha(line_1[i]) == 0) i--;
    while (isalpha(line_2[j]) == 0) j--;

    for (k = 0; (i != -1) && (j != -1); k++)
    {
        while (isalpha(line_1[i]) == 0) i--;
        while (isalpha(line_2[j]) == 0) j--;

        if(i < 0) break;
        if(j < 0) break;

        differ = line_1[i] - line_2[j];

        i--;
        j--;

        if (differ != 0) return differ;
    }
    return 0;
}

void qsoRT (struct LineInfo * Line, int Begin, int End, int (*Comp) (char*, char*, int, int))
{
    int left = Begin;
    int right = End;

    struct LineInfo pivor;
    pivor.index = Line[(left + right) / 2].index;
    pivor.len = Line[(left + right) / 2].len;

    int change_len = 0;
    char* change_index = "";

    while (left <= right)
    {
        while (Comp(Line[left].index, pivor.index, Line[left].len, pivor.len) < 0)
        {
            left++;
        }
        while (Comp(pivor.index, Line[right].index, pivor.len, Line[right].len) < 0)
        {
            right--;
        }

        if (left <= right)
        {
            change_index = Line[left].index;
            Line[left].index = Line[right].index;
            Line[right].index = change_index;

            change_len = Line[left].len;
            Line[left].len = Line[ right].len;
            Line[right].len = change_len;

            left++;
            right--;
        }
    }
    if (Begin < right)
        qsoRT (Line, Begin, right, Comp);



    if (End > left)
        qsoRT (Line, left, End, Comp);
}
int Compare (char* line_1, char* line_2, int len_1, int len_2)
{
    //printf("Line_1 - <%s>, len_1 - <%d>\n", line_1, len_1);
    //printf("Line_2 - <%s>, len_2 - <%d>\n", line_2, len_2);

    if (len_1 == -1)    return  1;
    if (len_2 == -1)    return -1;

    int differ = 0;

    int k = 0;

    int i = 0;
    int j = 0;

    ///while (isalpha(line_1[i]) == 0) i++;
    ///while (isalpha(line_2[j]) == 0) j++;
///                        +1?
    for (k = 0; (i != len_1) && (j != len_2); k++)
    {
        while ((isalpha(line_1[i]) == 0)) i++;
        while ((isalpha(line_2[j]) == 0)) j++;

        if(i > len_1) break;
        if(j > len_2) break;

        differ = line_1[i] - line_2[j];

        i++;
        j++;

        if (differ != 0) return differ;
    }
    return 0;
}
#endif
