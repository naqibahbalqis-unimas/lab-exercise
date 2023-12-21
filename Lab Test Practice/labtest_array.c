#include <stdio.h>


#define MAX_SIZE 100
int main(){

    int min, max, sum, avg;
    int i, n;
    int arr[MAX_SIZE];

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    printf("Enter %d elements in the array: ", n);
    for(i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }

    max = arr[0];
    min = arr[0];

    for(i=0 ; i<n; i++){
        if(arr[i] > max){
            max = arr[i];
        }
        if(arr[i] < min){
            min = arr[i];
        }
        sum += arr[i];
    }

    avg = sum / n;

    printf("Maximum element = %d\n", max);
    printf("Minimum element = %d\n", min);
    printf("Sum of the elements = %d\n", sum);
    printf("Average of the elements = %d\n", avg);




}
