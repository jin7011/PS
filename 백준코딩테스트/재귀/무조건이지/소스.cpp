#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;
char arr[3072][6143] = { '0' };
char unit[3][5] = { //삼각형 단위 패턴의 배열
    { 0, '무', 0 },
    { '조','건' },
    { '이','지'}
};
void print(int n, int x, int y) { //배열에 삼각형 패턴을 복사하는 함수
    if (n == 1) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 5; j++) {
                arr[y + i][x + j] = unit[i][j];
            }
        }
    }
    else if (n > 1) { //재귀적 호출
        print(n / 2, x + 3 * (n / 2), y);
        print(n / 2, x, y + 3 * (n / 2));
        print(n / 2, x + 3 * n, y + 3 * (n / 2));
    }
}
int main() {
    int n;
    scanf_s("%d", &n); //N값 입력
    print(n / 3, 0, 0); //함수 실행
    for (int i = 0; i < n; i++) { //출력
        for (int j = 0; j < (2 * n) - 1; j++) {
            if (arr[i][j] == 0) {
                printf(" ");
            }
            else {
                cout << arr[i][j];
            }
        }
        printf("\n");
    }
    return 0;
}