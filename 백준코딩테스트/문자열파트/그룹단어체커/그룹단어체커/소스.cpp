#include<stdio.h>
#include<string>

int Compare(char* S, char C,int x,int len) {

	int y = x + 2;

	for (y = x+2; y < len; y++) {
		if (S[y] == C) 
			return 1;
	}

	return 0;

}

int GetCount(char* S) { //for������ �ܾ��n��ŭ scanf�Ἥ �ܾ�ް� �׶��׶� ī���Ͱ��� ó�� 

	int count = 0;
	char C;
	int len = 0;
	len = strlen(S);

	for (int x = 0; x < len; x++) {
		if (S[x] != S[x + 1]) {
			C = S[x];
			count = Compare(S, C, x, len);
			if (count == 1) return 0;
		}
	}
	return 1;
}

int main() {

	int input = 0;
	int count = 0;
	char S[1000001] = { 0 };

	printf("�ܾ���Է�:");
	scanf_s("%d%*c", &input);

	for (int x = 0; x < input; x++) {
		scanf_s("%s%*c", S,sizeof(S));
		count = count + GetCount(S);

	}

	printf("%d", count);

	return 0;
}