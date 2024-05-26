#include <stdio.h>

void swap2(int *a, int *b){
        int t = *a;
        *a = *b;
        *b = t;
}
void swap3(int *a, int *b, int *c){
    int t;
    if(*a > *b){ swap2(a, b); }
    if(*b > *c){ swap2(c, b); }
    if(*a > *b){ swap2(a, b); }
}

int unused(int*p[], int length){
    int count = 0;
    for(int i=0; i<length; i++){
        if(p[i]==NULL) count++;
    }
    return count;
}

int printArray(int a[], size_t n){
    int*p = a;
    while (p<a+n){
        printf("%d", *p);
        p++;
    }
    return p-a;
}

int findFirstNonZero(int a[], size_t n){
    int*p = a;
    while (p<a+n && *p==0) p++;
    return p-a;   
}
// a better option: 
int findFirstNonZero2(int a[], size_t n){
    int i=0;
    while(i<n && a[i]==0) i++;
    return i;
}

int main(){
    char arr[5];
    int i=0;
    char c;
    while(c != 'q'){
        arr[i] = c;
        i++;
        if(i == 5) i = 0;
        printf("enter number. to quit press q. ");
        scanf("%c", &c);
    }
    i = 0;
    while(arr[i]){
        printf("%c", arr[i++]);
    }

    // for(int i=0; i<10; i++){
    //     printf("%d, ", i);
    // }
    // printf("pizza\n");
    // int a=12;
    // int b=4;
    // int c=9;
    // scanf("%d",&a);
    // scanf("%d",&b);
    // scanf("%d",&c);
    // printf("%d, %d, %d\n", a, b, c);
    // swap3(&a, &b, &c);
    // printf("%d, %d, %d\n", a, b, c);
    // int *arr [10];
    // arr[5] = &a;
    // printf("%d\n", unused(arr, 10));
    // printf("%d\n", *arr[5]);

    // int j=8;
    // void* p;
    // p = &j; // adress of j
    // int k = *((int*)p); // casts p to a pointer of type (int*), and sets k to be the value of what p is pointing at.
    // printf("k=%d\n", k);
    // int*q = &j;
    // int**q2 = &q;
    // printf("%p\n", &q2);
    printf("-----END-----\n");
    return 0;
}