#include <iostream>
#include <ctime>
#include "quick_sort.cpp"
using namespace std;

void print_array(int arr[], int n);
int* random_array(int n, int limit);
bool compare(int arr[], int n);

int main(void)
{
    srand(unsigned(time(NULL)));
    
    const int n = 1000;

    int* nums = random_array(n, 100000);

    print_array(nums,n);

    quick_sort(nums,0,999);

    print_array(nums,n);

    cout << compare(nums, n) << endl;

    return 0;
}

void print_array(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << " " << arr[i] << " ";
    }
    cout << endl;
}

int* random_array(int n, int limit)
{
    int* nums = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
    {
        nums[i] = rand() % limit;
    }
    return nums;
}

bool compare(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] > arr[i+1])
        {
            cout << arr[i] << '>' << arr[i+1] << endl;
            return false;
        }
    }
    return true;
}
