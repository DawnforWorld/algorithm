#include <cstdlib>

void count_sort(int arr[], int n, int limit);

void count_sort(int arr[], int n, int limit)
{
    int* count_nums = (int *)malloc(sizeof(int) * limit);
    for (int i = 0; i < limit; i++)
    {
        count_nums[i] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        count_nums[arr[i]]++;
    }

    int current = 0;
    for (int i = 0; i < limit; i++)
    {
        while (count_nums[i] != 0)
        {
            arr[current] = i;
            current++;
            count_nums[i]--;
        }
    }
    free(count_nums);
}