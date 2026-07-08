// Create an array of size 10 , input values and display sum and average of all elements in the array.

#include <stdio.h>
int main(){
    int arr[10] ;
    int addition = 0 ;
    float average ;
    int i ;
    //Input array elements , Calculate addition and average
    printf("Enter the 10 numerical value for your array:- ");
    for(i=0 ; i<10 ; i++){
        scanf("%d",&arr[i]);
        addition = addition + arr[i];
    }
    average = (float)addition/10 ;
    //Display array elements
    printf("\nThe elements of the array are:- ");
    for(i=0 ; i<10 ; i++){
        printf("%d ",arr[i]);
    }
    printf("\nAddition of array = %d", addition);
    printf("\nAverage of array = %f", average);
    return 0;
}