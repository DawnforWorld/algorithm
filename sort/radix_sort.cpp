#include <iostream>

void radix_sort(int arr[], int n, int N);

void radix_sort(int arr[], int n, int N)
{
    int** count = (int**)malloc(sizeof(int*) * 10);
    for (int i = 0; i < 10; i++)
    {
        count[i] = (int*)malloc(sizeof(int) * (n + 1));
        count[i][n] = 0;
    }

    int d = 1;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int num =  arr[j] / d % 10;
            count[num][count[num][n]++] = arr[j];
        }
        d = d * 10;

        int current = 0;
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < count[i][n]; j++)
            {
                arr[current++] = count[i][j];
            }
            count[i][n] = 0;
        }
    }

    for (int i = 0; i < 10; i++)
    {
        free(count[i]);
    }

    free(count);
}