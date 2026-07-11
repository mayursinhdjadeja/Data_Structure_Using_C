// Sort the array into ascending order.

#include <stdio.h>
int main() {
    int arr[50], n, i, j, temp;
    // Input size
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    // Input array
    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    // Bubble Sort
    for(i = 0; i < n - 1; i++) {
        for(j = 0; j < n - 1 - i; j++) {
            if(arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    // Display sorted array
    printf("Array in Ascending Order:\n");
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}