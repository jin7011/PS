#include <iostream>
#include <stdio.h>
#include <string>

// c= c- dz= lj nj �� �� ����
//�Է�:lj e s= nj a k ���: 6

int main() {

	char S[1000]; //9��
	//lj je es s= nj ja ak 7��
	//������ 6��

	printf("�Է��϶�:");
	scanf_s("%s%*c", S, sizeof(S));

	int len = 0;
	len = strlen(S);
	int count = 0;
	int x = 0;

	while(S[x] != NULL){
		if (S[x] == 'l' && S[x + 1] == 'j') {
			count++; x = x + 2;
		}
		else if (S[x] == 's' && S[x + 1] == '=') { count++; x = x + 2; }
		else if (S[x] == 'n' && S[x + 1] == 'j') { count++; x = x + 2; }
		else if (S[x] == 'c' && S[x + 1] == '=') { count++; x = x + 2; }
		else if (S[x] == 'd' && S[x + 1] == '-') { count++; x = x + 2; }
		else if (S[x] == 'z' && S[x + 1] == '=') { count++; x = x + 2; }
		else if (S[x] == 'c' && S[x + 1] == '-') { count++; x = x + 2; }
		else if (S[x] == 'd' && S[x + 1] == 'z' && S[x + 2] == '=') { count = count+2; x = x + 3; }
		else x++;
	}
	// dz=zz=
	printf("%d", len - count);

	return 0;
}