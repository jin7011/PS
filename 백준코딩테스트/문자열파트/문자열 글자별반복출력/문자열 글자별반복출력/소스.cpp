#include<iostream>
#include <stdio.h>
#include <string>

using namespace std;

int main() {

	char S[20] = { 0 };
	int R = 0;
	int len = 0;
	int r;

	printf("S�� ����:");
	gets_s(S, sizeof(S));

	len = strlen(S);

	printf("�ݺ� �� Ƚ��:");
	scanf_s("%d%*c", &R);

	if (R >= 1 && R <= 1000 && len >= 1 && len <= 20) 
		for (int x = 0; x < len; x++) {
			for (int y = 0; y < R; y++)
				printf("%c", S[x]);
		}
	else
		printf("R�� 1~1000�� S�� 1~20���� �Դϴ�.\n");

	return 0;
}