#include<stdio.h>
#include <memory>

int Max(int* a,int len) {

    int max = 0;

    for (int x = 0; x < len; x++) {
        if (max < a[x])
            max = a[x];
    }

    return max;

}

void Csort(int* a,int len) {

    int* C = NULL;
    int max = 0;
    max = Max(a,len);
    int k = 0;

    C = (int*)calloc( max+1,sizeof(int) );
    

    for (int x = 0; x <= max; x++) //C에 카운트정렬채워넣기
    {
        k = a[x];
        C[k]++;
    }
    printf("\n");
    for(int x =0;x<=max;x++) //C 출력
        for (int y = 0; y < C[x]; y++) 
            printf("%d", x);
        
}

int main(void) {

    int T = 0; scanf_s("%d", &T);
    int* a = NULL;

    a = (int*)malloc(sizeof(int) * T);

    for (int x = 0; x < T; x++)
        scanf_s("%d", &a[x]);

    Csort(a,T);

    return 0;

}