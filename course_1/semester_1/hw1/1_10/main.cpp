#include <stdio.h>
#include <cstring>

int main()
{
    char s[256] = {0};
    printf("Input string: ");
    scanf("%s", &s);

    bool isPalindrome = true;
    int middleIndex = strlen(s) / 2;
    for (int i = 0; i < middleIndex; i++)
    {
        if (s[i] != s[strlen(s) - i - 1])
        {
            isPalindrome = false;
        }
    }

    if (isPalindrome)
    {
        printf("Yes, it is a palindrome!");
    }
    else
    {
        printf("No, it isn't a palindrome!");
    }

    return 0;
}