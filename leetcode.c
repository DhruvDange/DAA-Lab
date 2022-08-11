#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int numDecodings(char *s)
{

    int len = strlen(s);

    if (len == 0 || s[0] == '0')
        return 0;

    if (len == 1)
        return 1;

    int count1 = 1, count2 = 1;
    for (int i = 1; i < len; i++)
    {
        int d = s[i] - '0';
        int dd = (s[i - 1] - '0') * 10 + d;
        int count = 0;

        if (d > 0)
            count = count2;
        if (dd >= 10 && dd <= 26)
            count += count1;

        count1 = count2;
        count2 = count;
    }
    return count2;
}

void main()
{
    char str[50];
    printf("Enter the string on integers: ");
    scanf("%s", str);
    int result = numDecodings(str);

    printf("The number of ways to decode the string is: %d", result);
}