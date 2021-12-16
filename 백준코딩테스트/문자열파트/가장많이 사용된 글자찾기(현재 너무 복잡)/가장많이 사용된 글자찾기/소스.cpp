#include <stdio.h>
#include <string>
#include <stdlib.h>

typedef struct Data {

	int x = 0;
	int count = 0;

}Data;

void Turn(char* W, int len) {

	for (int x = 0; x < len; x++) { //소문자 -> 대문자
		if ((int)W[x] >= 97)
			W[x] = W[x] - 32;
	}

}

int Getcount(char* W, int len, int x) {

	int count = 0;

	if (W[x] != 1)
	for (int y = x + 1; y < len; y++) {

		if (W[x] == W[y]) {
			count++;
			W[y] = { 1 };
		}

	}
	return count;

}

char Sort(Data *pD, int len, char* W) {

	Data temp;

	for (int x = 0; x < len-1; x++) {
		for (int y = x + 1; y < len; y++) {
			if(pD[y].x != 0 && pD[y].count != 0)
			if (pD[x].count < pD[y].count) {
				temp = pD[x];
				pD[x] = pD[y];
				pD[y] = temp;
			}
		}
	}
	if (pD[0].count == pD[1].count) 
		return '?';

	return (char)(W[pD[0].x]);
}

int main() {

	char W[1000000] = { 0 };
	int len = 0;
	char R;
	int count = 0;

	scanf_s("%s", W,sizeof(W));
	len = strlen(W);

	if (len > 1000000) return 0;

	Turn(W,len);
	//       65 65 76 82 82 65 82 82 -> x=0,count = 2;    // 65 1 76 82 1 82 82 82 -> x = 2,count = 0;     // 65 1 76 1 1 1 1 1 -> x=3, count = 3;
	Data* p = new Data[len];
		
	for (int x = 0; x < len-1; x++) {
		if (W[x] != 1) {
			count = Getcount(W, len, x);
			p[x] = { x,count }; // 0,2 // 2,0 // 3,3
		}
	}

	R = Sort(p,len,W);

	printf("%c", R);
		
	return 0;
}