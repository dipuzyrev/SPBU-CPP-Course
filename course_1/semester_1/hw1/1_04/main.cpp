#include <stdio.h>

int main()
{
    //array with different sums (from 0 to 27)
    const int numberOfSums = 28;
    int sums[numberOfSums] = { 0 };

    for (int i = 0; i <= 9; i++)
    {
        for (int j = 0; j <= 9; j++)
        {
            for (int k = 0; k <= 9; k++)
            {
                int sum = i + j + k;
                sums[sum]++;
            }
        }
    }

    int countOfGoodTickets = 0;
    for (int i = 0; i < numberOfSums; i++)
    {
        countOfGoodTickets += sums[i] * sums[i];
    }

    printf("Count of good tickets: %i", countOfGoodTickets);

    return 0;
}