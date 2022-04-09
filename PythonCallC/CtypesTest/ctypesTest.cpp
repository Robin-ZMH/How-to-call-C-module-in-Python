// -fPIC ignore posion
// -c = Compile, -o = output, -shared = .so
// g++ -g -fPIC nima.cpp -c -o nima.o
// g++ fPIC-shared nima.cpp -o libnima.so
#include<stdio.h>
#include<math.h>
#include<iostream>
#define C extern "C"
C float testCBaseType(int x, float y, char z, bool isNum){
    printf("===============testCBaseType===============\n");
    printf("%d, %f, %c, %d\n", x, y, z, isNum);
    if(isNum){
        printf("true\n");
    }else{
        printf("false\n");
    }
    return 100.0;
}


C const char *testCstring(const char *x){
    printf("===============testCstring===============\n");
    printf("%s\n", x);
    return "Hello Robin";
}

// 返回字符串要用 wchar_t *函数名
C const wchar_t *testCWideString(const wchar_t *str){
    printf("===============testCWideString===============\n");
    printf("%ls\n", str);
    return L"Hello Robin,this is Lisa";
}


C int testPointer(int *x){
    printf("===============TestPointer===============\n");
    printf("old_arg=%d\n", *x);
    int ret = *x;
    *x += 10;
    return ret; 
}


C int *testReturnPointer(int *x){
    printf("===============TestReturnPointer===============\n");
    printf("old_arg=%d\n", *x);
    *x += 10;
    return x; 
}


C double testArray(int *arr, int size){
    printf("===============TestArray================\n");
    double total = 0.0;
    for(int i=0;i < size; i++){
        printf("%d", arr[i]);
        total += arr[i];
    }
    printf("\n");
    return total / size;
}


C typedef struct Point{
    double x, y;
}Point;


C double distance(Point *p1, Point *p2){
    printf("===============distance===============\n");
    return hypot(p1->x - p2->x, p1->y - p2->y);
}


C int testTime(int x){
    int res = 0;
    for(int i = 0; i < x; i++){
        res += i;
    }
    return res;
}