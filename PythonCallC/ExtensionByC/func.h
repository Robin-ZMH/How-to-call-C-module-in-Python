#include<stdio.h>
int multiply(int x, int y){
    printf("=============multiply=============\n");
    return x * y;
}
 
float divide(float x, float y){
    printf("=============divide=============\n");
    return x / y;
}

void helper(int *x){
    printf("old_arg=%d\n", *x);
    *x += 10;
}

int pointer(int x){
    printf("=============pointer=============\n");
    helper(&x);
    return x;
}

int mod(int x, int y, int *remainder){
    printf("=============mod=============\n");
    *remainder = x % y;
    return x / y;
}

double avg(int *arr, int size){
    double sum = 0.0;
    printf("=============avg=============\n");
    for(int i=0; i < size; i++){
        printf("%d, ", arr[i]);
        sum += arr[i];
    }
    printf("\n");
    return sum / size;
} 

int test(int x){
    int res = 0;
    for (int i = 0; i < x; i++){
        res += i;
    }
    return res;
}
