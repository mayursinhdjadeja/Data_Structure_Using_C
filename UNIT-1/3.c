// Create arrays A, B and C of size 3, perform C = A + B.

#include <stdio.h>
int main(){
    int a[3] , b[3] , c[3];
    int i ;
    //Enter the elements in the arrays.
    printf("Enter the 3 numerical values for the array A:- ");
    for(i=0 ; i<3 ; i++){
        scanf("%d",&a[i]);
    }
    printf("\nEnter the 3 numerical values for the array B:- ");
    for(i=0 ; i<3 ; i++){
        scanf("%d",&b[i]);
    }
    //A + B = C
    for(i=0 ; i<3 ; i++){
        c[i]= a[i] + b[i];
    }
    //Display all the arrays
    printf("\nA:-");
    for(i=0 ; i<3 ; i++){
        printf(" %d",a[i]);
    }
    printf("\nB:-");
    for(i=0 ; i<3 ; i++){
        printf(" %d",b[i]);
    }
    //A + B = C
    printf("\nC (A + B = C):-");
    for(i=0 ; i<3 ; i++){
        printf(" %d",c[i]);
    }
    return 0;
}