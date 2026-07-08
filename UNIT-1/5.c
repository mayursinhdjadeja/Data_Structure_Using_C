// Create an array of size 10, find the largest value from the array.

#include <stdio.h>
int main(){
    int arr[10] ;
    int i , largest_value ;
    //Enter the elements in the array
    printf("Enter the 10 numerical values for the array:-");
    for(i=0 ; i<10 ; i++){
        scanf("%d",&arr[i]);
    }
    //Largest value
    largest_value = arr[0] ;
    for(i=1 ; i<10 ; i++){
        if(arr[i] > largest_value){
            largest_value = arr[i];
        }
    }
    //Display the array
    printf("\nThe array:-");
    for(i=0 ; i<10 ; i++){
        printf("%d ",arr[i]);
    }
    //Display the largset value from the array
    printf("\nThe largest value of the array is:- %d",largest_value);
    return 0;
}