#include <stdio.h>
int main () {
/* an array with 5 rows and 2 columns*/
    int a[5][2] = {0, 0, 1, 2, 2, 4, 3, 6, 4, 8}; //first method
    int b[5][2] = {{0, 0},{1, 2},{2, 4},{3, 6},{4, 8}}; //second method
    int i, j;
/* output each array element's value */
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 2; j++) {
            printf("a[%d][%d] = %d\n", i, j, a[i][j]);
        }

    }printf("\n");
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 2; j++) {
            printf("b[%d][%d] = %d\n", i, j, b[i][j]);
        }

    }


    // Printing a[2][0]
    printf("Element a[2][0] = %d\n", a[2][0]);

    // Printing b[4][1]
    printf("Element b[4][1] = %d\n", b[4][1]);
    return 0;
}
