
int sort(int nums[], int low, int high)
{
    int pivot = nums[low];
    while (low < high)
    {
        while (low < high)
        {
            if (nums[high] < pivot)
            {
                nums[low] = nums[high];
                low++;
                break;
            }
            else
            {
                high--;
            }
        }
        while (low < high)
        {
            if (nums[low] > pivot)
            {
                nums[high] = nums[low];
                high--;
                break;
            }
            else
            {
                low++;
            }
        }
    }
    nums[low] = pivot;
    return low;
}

void quick_sort(int nums[], int low, int high)
{
    if (low < high)
    {
        int mid = sort(nums, low, high);
        quick_sort(nums, low, mid);
        quick_sort(nums, mid + 1, high);
    }
}

