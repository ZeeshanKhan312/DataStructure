//ZIG-ZAG conversion of strings..!
#include<stdio.h>
#include<string.h>
char* convert(char* s, int numRows)
{
    int i, j;
    char* NewString = NULL;
    int size, CycleNum;
    size = strlen(s);
    CycleNum = (2 * numRows) - 2;
    NewString = malloc(100);
    int num = 0;
    for (i = 0; i < numRows; i++)
    {
        for (j = 0; i + j < size; j += CycleNum)
        {
            *(NewString + num) = *(s + i + j);
            num++;
            if (i != 0 && i != numRows - 1 && (j + CycleNum - i) < size)
            {
                *(NewString + num) = *(s + j + CycleNum - i);
                num++;
            }
        }
    }
    *(NewString + num) = '\0';
    return NewString;
}
void main()
{
    char* string;
    string = "paypalishiring";
    int rows;
    rows = 4;
    char* NewString;
    NewString = convert(string, rows);
    printf(" %s", NewString);
}