#include <stdio.h>
#include <string.h>

int main() {

	char S[1000001];
	int count = 1;

	printf("문장을 입력:");
	gets_s(S, sizeof(S));

	for (int x = 0; S[x] != NULL; x++) {
		if (S[x] == ' ' && S[x + 1] != ' ' && S[x+1] != NULL)
			count++;
	}
	// ' 'the
	if (S[0] == ' ')
		count--;

	printf("단어의 수:%d", count);

	return 0;
}