/* The following code in C checks if the given array has any duplicates or not*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void merge(int *left, int *right, int *nums, int mid, int n)
{
    int i = 0, j = 0, k = 0;
    while (i < mid && j < n - mid)
    {
        if (left[i] < right[j])
        {
            nums[k++] = left[i++];
        }
        else
        {
            nums[k++] = right[j++];
        }
    }
    if (i == mid)
    {
        while (k != n)
        {
            nums[k++] = right[j++];
        }
    }
    else
    {
        while (k != n)
        {
            nums[k++] = left[i++];
        }
    }
}

void sort(int *nums, int n)
{
    if (n > 1)
    {
        int mid, i;
        if (n % 2 == 0)
            mid = n / 2;
        else
            mid = n / 2 + 1;
        int *left = (int *)malloc(mid * sizeof(int));
        int *right = (int *)malloc(mid * sizeof(int));
        for (i = 0; i < mid; i++)
            left[i] = nums[i];
        for (int j = 0; j < n - mid; j++)
        {
            right[j] = nums[i];
            i++;
        }
        sort(left, mid);
        sort(right, n - mid);
        merge(left, right, nums, mid, n);
    }
}

bool containsDuplicate(int *nums, int numsSize)
{
    sort(nums, numsSize);           // merge sort
    for (int i = 0; i < numsSize - 1; i++)
    {
        if (nums[i] == nums[i + 1])
            return true;
    }
    return false;
}

int main()
{
    int n, result;
    printf("Enter the no. of elements:\n");
    scanf("%d", &n);
    int *nums = (int *)malloc(n * sizeof(int));
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &nums[i]);
    result = containsDuplicate(nums, n);
    if(result==0)
    printf("There are no duplicates in the array");
    else 
    printf("There are duplicates in the array");
    return 0;
}