#include <stdio.h>
#include <cstring>

bool checkInclusion(char str[], char subStr[], int strStartIndex)
{
    const int stringLength = strlen(subStr);
    for (int i = 0; i < stringLength; i++)
    {
        int currentIndex = strStartIndex + i;
        if ((currentIndex >= strlen(str)) || (subStr[i] != str[currentIndex]))
        {
            return false;
        }
    }

    return true;
}

int main()
{
    //Input needle and haystack
    char needle[256] = {0};
    char haystack[256] = {0};
    printf("Enter haystack: ");
    scanf("%s", &haystack);
    printf("Enter needle: ");
    scanf("%s", &needle);

    int countOfSubstrs = 0;

    int i = 0;
    while (i < strlen(haystack))
    {
        if (haystack[i] == needle[0])
        {
            int isSubStr = checkInclusion(haystack, needle, i);
            if (isSubStr)
            {
                countOfSubstrs++;
                i++;
                continue;
            }
        }

        i++;
    }

    printf("Count of \"%s\" in \"%s\": %i\n", needle, haystack, countOfSubstrs);

    return 0;
}