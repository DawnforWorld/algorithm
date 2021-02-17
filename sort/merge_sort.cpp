#include <iostream>
using namespace std;

void sort(int arr[], int left, int mid, int right);
void merge_sort(int arr[], int left, int right);

void merge_sort(int arr[], int left, int right)
{
    if (left >= right) return;

    int mid = left + (right - left) / 2;
    merge_sort(arr, left, mid);
    merge_sort(arr, mid + 1, right);
    sort(arr, left, mid, right);
}

void sort(int arr[], int left, int mid, int right)
{
    int i = left;
    int j = mid + 1;
    int k = 0;

    int* temp = (int *)malloc((right - left + 1) * sizeof(int));

    while (i <= mid && j <= right)
    {
        if (arr[i] <= arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
        }
    }

    while (i <= mid) temp[k++] = arr[i++];
    while (j <= right) temp[k++] = arr[j++];

    for (int m = left; m <= right; m++)
    {
        arr[m] = temp[m - left];
    }
    free(temp);
}