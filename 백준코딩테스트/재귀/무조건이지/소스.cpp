#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;
char arr[3072][6143] = { '0' };
char unit[3][5] = { //�ﰢ�� ���� ������ �迭
    { 0, '��', 0 },
    { '��','��' },
    { '��','��'}
};
void print(int n, int x, int y) { //�迭�� �ﰢ�� ������ �����ϴ� �Լ�
    if (n == 1) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 5; j++) {
                arr[y + i][x + j] = unit[i][j];
            }
        }
    }
    else if (n > 1) { //����� ȣ��
        print(n / 2, x + 3 * (n / 2), y);
        print(n / 2, x, y + 3 * (n / 2));
        print(n / 2, x + 3 * n, y + 3 * (n / 2));
    }
}
int main() {
    int n;
    scanf_s("%d", &n); //N�� �Է�
    print(n / 3, 0, 0); //�Լ� ����
    for (int i = 0; i < n; i++) { //���
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