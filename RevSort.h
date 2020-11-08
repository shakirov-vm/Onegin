#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <ctype.h>


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
        {
            left++;
        }
        while (RevCompare(pivor.index, Line[right].index, pivor.len, Line[right].len) < 0)
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
        RevqsoRT (Line, Begin, right/*, Comp*/);
    if (End > left)
        RevqsoRT (Line, left, End/*, Comp*/);
}





/*
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
}*/
