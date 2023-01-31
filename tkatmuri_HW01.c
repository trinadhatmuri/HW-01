#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
void intro332532();
int UABNumber();
int reverseNum(int);
int smallerThanIndex(int *numbers, int);
float *arrayDetails(float *arr, int);

int main() {
    //UABNumber
    int uabnum = UABNumber();
    printf("%d",uabnum);

    //
    int n;
    printf("\nEnter a number for intro332532: ");
    scanf("%d", &n);
    intro332532(n);

    int n3;
    printf("\nEnter a number for number reversal: ");
    scanf("%d", &n3);
    int rev = reverseNum(n3);
    printf("\nThe reverse of the number %d is %d", n3, rev);

    int size;
    printf("\nEnter the size of the array: ");
    scanf("%d", &size);
    int *ptr = (int*)malloc(sizeof(int)*size);
    printf("\nEnter the array elements: ");
    for (int i=0; i<size; i++) {
        scanf("%d", &ptr[i]);
    }
    int numsSmaller = smallerThanIndex(ptr, size);
    printf("The number of elements that are smaller than their index are %d\n",numsSmaller);

    int arrSize;
    printf("\nEnter the array size for arrayDetails: ");
    scanf("%d", &arrSize);
    float *arrPtr = (float*)malloc(sizeof(float)*arrSize);
    printf("Enter the array elements for arrayDetatils: ");
    for (int i=0; i<arrSize; i++) {
        scanf("%f", &arrPtr[i]);
    }
    float *arrDetails = arrayDetails(arrPtr, arrSize);
    printf("\n[");
    printf("%.f,", arrDetails[0]);
    printf("%.f,", arrDetails[1]);
    printf("%.f,", arrDetails[2]);
    printf("%.2f,", arrDetails[3]);
    printf("%.f,", arrDetails[4]);
    printf("%.f", arrDetails[5]);
    printf("]");
    

    return 0;
}

void intro332532 (int n) {
    int isPrime = 1;
    for(int i=2; i<=n/2; i++) {
        if(n%i == 0) {
            isPrime = 0;
            break;
        }
    }
    if( isPrime == 1 && n != 3 && n != 5) {
        printf("Go Blazers\n");
    }
    else if ( n%3 == 0 && n%5 == 0) {
        printf("UAB CS 332&532\n");
    }
    else if(n%5 == 0) {
        printf("UAB\n");
    }
    else if( n%3 == 0){
        printf("CS\n");
    }
    else {
        printf("%d\n", n*n*n);
    }
}

int UABNumber() {
    int n2, sum = 1;
    printf("Enter a number to check if it is UAB Number: ");
    scanf("%d", &n2);
    for( int i=2; i<=n2/2; i++) {
        if(n2 % i == 0) {
            sum += i;
        }
    }
    if(n2 == sum) {
        return 1;
    }
    else {
        return 0;
    }
    
}

int reverseNum(int n3) {
    int dummy = n3,num, sum=0;

    while (dummy != 0) {
        num = dummy % 10;
        sum = sum * 10 + num;
        dummy = dummy / 10;
    }
    return sum;
    
}

int smallerThanIndex(int *numbers, int size) {
    int numsSmaller=0;
    for (int i=0; i<size; i++) {
        if(numbers[i] < i) {
            numsSmaller += 1;
        }
    }
    return numsSmaller;
}

float *arrayDetails(float *arr, int size) {
    float *retArr = malloc(sizeof(float)*size);
    // float arr = {0}*6;
    retArr[0] = size;
    int minVal=INT_MAX, maxVal=INT_MIN, minValIndex=0, maxValIndex=0;
    float sum=0;
    for (int i=0; i<size; i++) {
        sum += arr[i];
        if(arr[i] < minVal) {
            minVal = arr[i];
            minValIndex = i;
        }
        if(arr[i] > maxVal) {
            maxVal = arr[i];
            maxValIndex = i;
        } 
    }
    retArr[1] = minVal;
    retArr[2] = minValIndex;
    retArr[3] = (sum/size);
    retArr[4] = maxVal;
    retArr[5] = maxValIndex;
    return retArr;
}