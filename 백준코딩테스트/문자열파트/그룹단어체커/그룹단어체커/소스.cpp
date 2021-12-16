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

int GetCount(char* S) { //for문으로 단어수n만큼 scanf써서 단어받고 그때그때 카운터갯수 처리 

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

	printf("단어수입력:");
	scanf_s("%d%*c", &input);

	for (int x = 0; x < input; x++) {
		scanf_s("%s%*c", S,sizeof(S));
		count = count + GetCount(S);

	}

	printf("%d", count);

	return 0;
}