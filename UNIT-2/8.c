// Write a program to find Minimum and Maximum numbers from the given array using Recursion.

#include <stdio.h>

int FindMin(int arr[], int n)
{
    if (n == 1)
    {
        return arr[0];
    }
    int min = FindMin(arr, n - 1);
    
    if (arr[n - 1] < min)
    {
        return arr[n - 1];
    }
    else
    {
        return min;
    }
}

int FindMax(int arr[], int n)
{
    if (n == 1)
    {
        return arr[0];
    }
    
    int max = FindMax(arr, n - 1);
    
    if (arr[n - 1] > max)
    {
        return arr[n - 1];
    }
    else
    {
        return max;
    }
}

int main()
{
    int arr[100], n, i;
    int min, max;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter array elements:\n");

    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    min = FindMin(arr, n);
    max = FindMax(arr, n);

    printf("Minimum = %d\n", min);
    printf("Maximum = %d\n", max);

    return 0;
}
