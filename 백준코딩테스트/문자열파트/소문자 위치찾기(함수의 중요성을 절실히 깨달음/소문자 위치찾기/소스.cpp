#include <iostream>
#include <string>

using namespace std;

int Find(const char* S,int k) {

	int len = strlen(S);

	for (int x = 0; x < len; x++) { // 1 0 4 10 9 14 14 13
		if (S[x] == k)
			return x;
	}

	return -1;
}

int main() {

	char S[100] = { 0 };

	printf("이름을 입력하세요: ");
	scanf_s("%s%*c", S, sizeof(S));

	for(int x=0; x<26;x++)
	printf("%d\t", Find(S, (int)'a'+x));

	return 0;
}