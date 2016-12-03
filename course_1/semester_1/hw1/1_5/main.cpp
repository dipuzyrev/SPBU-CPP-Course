#include <stdio.h>

int main()
{
    char s[256] = {0};
    printf("Input text with brakets for checking: ");
    scanf("%s", &s);

    //1. If variable < 0 - brakets nesting are wrong
    //2. If variable > 0 - no balance
    bool isNasted = true;
    int openCount = 0, closeCount = 0;
    const char openBracket = '(';
    const char closeBracket = ')';

    for (int i = 0; i < strlen(s); i++)
    {
        char currentChar = s[i];

        if (currentChar == openBracket)
        {
            openCount++;
        }
        else if (currentChar == closeBracket)
        {
            closeCount++;
        }
        
        if (openCount < closeCount)
        {
            isNasted = false;
            break;
        }
    }

    if (isNasted)
    {
        if (closeCount == openCount)
        {
            printf("All right!");
        }
        else
        {
            printf("No balance");
        }
    }
    else
    {
        printf("No nesting");
    }
}