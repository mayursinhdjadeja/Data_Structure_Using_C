// Create arrays A, B of size 3, C of size 6, merge A and B into C.

#include <stdio.h>
int main(){
    int a[3] , b[3]  , c[6];
    int i ;
    //Enter the elements for the arrays
    printf("Enter the 3 numerical values for array A:-");
    for(i=0 ; i<3 ; i++){
        scanf("%d",&a[i]);
    }
    printf("\nEnter the 3 numerical values for array B:-");
    for(i=0 ; i<3 ; i++){
        scanf("%d",&b[i]);
    }
    //Merge A and B into C.
    for(i=0 ; i<3 ; i++){
        c[i] = a[i];
    }
    for(i=0 ; i<3 ; i++){
        c[i + 3] = b[i];
    }
    //Display all arrays
    printf("\nA:-");
    for(i=0 ; i<3 ; i++){
        printf("%d ",a[i]);
    }
    printf("\nB:-");
    for(i=0 ; i<3 ; i++){
        printf("%d ",b[i]);
    }
    printf("\nA and B merged in C:-");
    for(i=0 ; i<6 ; i++){
        printf("%d ",c[i]);
    }
    return 0;
}