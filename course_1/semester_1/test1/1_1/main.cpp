#include <iostream>

using namespace std;

int main()
{
    // Сложность алгоритма: n1 + n2

    int length1 = 0;
    int length2 = 0;
    printf("Input count of items in first stack: ");
    scanf("%i", &length1);
    int *stack1 = new int[length1];
    for (int i = 0; i < length1; i++)
        stack1[i] = length1;
    for (int i = 0; i < length1; i++)
    {
        printf("Input %i value: ", i+1);
        scanf("%i", &stack1[i]);
    }

    printf("Input count of items in second stack: ");
    scanf("%i", &length2);
    int *stack2 = new int[length2];
    for (int i = 0; i < length2; i++)
        stack2[i] = length2;
    for (int i = 0; i < length2; i++)
    {
        printf("Input %i value: ", i+1);
        scanf("%i", &stack2[i]);
    }

    int *newStack = new int[length1 + length2];
    for (int i = 0; i < length1 + length2; i++)
        newStack[i] = 0;

    int index1 = 0;
    int index2 = 0;
    while (index1 < length1 || index2 < length2)
    {
        if (index1 < length1 && index2 < length2)
        {
            if (stack1[index1] > stack2[index2])
            {
                newStack[index1 + index2] = stack1[index1];
                index1++;
            }
            else
            {
                newStack[index1 + index2] = stack2[index2];
                index2++;
            }
        }
        else if (index1 == length1)
        {
            newStack[index1 + index2] = stack2[index2];
            index2++;
        }
        else
        {
            newStack[index1 + index2] = stack1[index1];
            index1++;
        }
    }

    printf("\nNew stack: ");
    for (int i = 0; i < length1 + length2; i++)
        printf("%i ", newStack[i]);

    delete[] stack1;
    delete[] stack2;
    delete[] newStack;

    return 0;
}