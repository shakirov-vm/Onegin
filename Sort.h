#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

int Comparator(char* str1, char* str2)
{
    int i = 0;
    int differ = 0;

    for(i; (str1[i] != '\0') && (str2[i] != '\0') ; i++)
    {
        differ = 0;

        differ = str2[i] - str1[i];

        if (differ != 0)
            return differ;
    }

    return 0;
}
void qsoRT (struct LineInfo * Line, int b, int e)
{
    int l = b;
    int r = e;
    int change_len = 0;
    char* CHANGE = "";

    char* piv = Line[(l + r) / 2].index;

    while (l <= r)
    {
        while (Comparator(Line[l].index, piv) > 0)
        {
            l++;
        }
        while (Comparator(piv, Line[r].index) > 0)
        {
            r--;
        }

        if (l <= r)
        {
            CHANGE = Line[l].index;
            Line[l].index = Line[r].index;
            Line[r].index = CHANGE;

            change_len = Line[l].len;
            Line[l].len = Line[r].len;
            Line[r].len = change_len;

            l = l + 1;
            r = r - 1;
        }
    }
    if (b < r)
        qsoRT (Line, b, r);
    if (e > l)
        qsoRT (Line, l, e);
}
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




































#if 0

/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <ctype.h>

#if 1
int RevCompare (char* line_1, char* line_2, int len_1, int len_2)
{
    int k = 0;

    int i = len_1;
    int j = len_2;

    int differ = 0;

    for (k = 0; (i != 0) && (len_2 != 0); k++)
    {
        while (isalpha(line_1[i]) == 0) i--;
        while (isalpha(line_2[j]) == 0) j--;

        differ = line_1[i] - line_2[j];

        i--;
        j--;

        if (differ != 0) return differ;
    }
    return 0;
}
#endif
#if 0
void RevqsoRT (struct LineInfo * Line, int b, int e)
{
    int l = b;
    int r = e;
    int change = 0;
    char* CHANGE = "";

    char* piv_i = Line[(l + r) / 2].index;
    int piv_l = Line[(l + r) / 2].len;

    while (l <= r)
    {
        while (RevCompare(Line[l].index, piv_i, Line[l].len, piv_l) < 0)
        {
            l++;
        }
        while (RevCompare(piv_i, Line[r].index, piv_l, Line[r].len) < 0)
        {
            r--;
        }

        if (l <= r)
        {
            CHANGE = Line[l].index;
            Line[l].index = Line[r].index;
            Line[r].index = CHANGE;

            change = Line[l].len;
            Line[l].len = Line[r].len;
            Line[r].len = change;

            l = l + 1;
            r = r - 1;
        }
    }
    if (b < r)
        RevqsoRT (Line, b, r);
    if (e > l)
        RevqsoRT (Line, l, e);
}
#endif

void RevqsoRT (struct LineInfo * Line, int Begin, int End/*, int (*Comp) (char*, char*, int, int)*/)
{
    int left = Begin;
    int right = End;

    struct LineInfo pivor;
    pivor.index = Line[(left + right) / 2].index;
    pivor.len = Line[(left + right) / 2].len;

    int change_len = 0;
    char* change_index = "";

    while (left <= right)
    { ///      RevCompare заменить на Comp
        while (RevCompare(Line[left].index, pivor.index, Line[left].len, pivor.len) < 0)
        //while (RevCompare(Line[left], pivor) < 0)
        {
            left++;
        }
        while (RevCompare(pivor.index, Line[right].index, pivor.len, Line[left].len) < 0)
        //while (RevCompare(pivor, Line[right]) < 0)
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
        RevqsoRT (Line, Begin, right/*, Comp*/);
    if (End > left)
        RevqsoRT (Line, left, End/*, Comp*/);
}
#if 0
int RevCompare (struct LineInfo * line_1, struct LineInfo * line_2)
{
    int k = 0;

    int i = line_1->len;
    int j = line_2->len;

    int differ = 0;

    for (k = 0; (i != 0) && (j != 0); k++)
    {
        while (isalpha(line_1[i].index) == 0) i--;
        while (isalpha(*line_2[j].index) == 0) j--;

        differ = line_1[i].index - line_2[j].index;

        i--;
        j--;

        if (differ != 0) return differ;
    }
    return 0;
}
#endif

#endif
