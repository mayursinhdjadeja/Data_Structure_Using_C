// Create an array of size 10 , input values and print tha array , and search an element in the array.

#include <stdio.h>
int main(){
    int arr[10] ;
    int i , key , found = 0;
    //Input array elemnts
    printf("Enter the 10 numerical value for your array:- ");
    for(i=0 ; i<10 ; i++){
        scanf("%d",&arr[i]);
    }
    //Display array elements
    printf("The elements of the array are::- ");
    for(i=0 ; i<10 ; i++){
        printf("%d ",arr[i]);
    }
    // Search for an element
    printf("\nEnter the element you want to search in the array:- ");
    scanf("%d",&key);
    for(i=0 ; i < 10 ; i++){
        if (arr[i] == key){
            printf("The element %d found at Position %d (Index %d).", key , i+1 , i);
            found=1;
            break;
        }
    }
    if (found==0){
        printf("\nElement %d was not found in the array.", key);
    }
    return 0;
}
