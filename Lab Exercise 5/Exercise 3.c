#include <stdio.h>
#include <alg.h>
int main () {
    int n[ 5 ]; /* n is an array of 5 integers */
    int i,j;
/* initialize elements of array n */
    for ( i = 0; i < 5; i++ ) {
        n[ i ] = i ;
    }
/* output each array element's value */
    for (j = 0; j < 5; j++ ) {
        printf("Element n[%d] = %d\n", j, n[j] );
    }


    for (i = 0, j = 4; i < j; i++, j--) {
        /* swap n[i] and n[j] */
        int temp = n[i];
        n[i] = n[j];
        n[j] = temp;
    }

    printf("\nReversed array:\n");
    for (j = 0; j < 5; j++) {
        printf("Element n[%d] = %d\n", j, n[j]);
    }
}
