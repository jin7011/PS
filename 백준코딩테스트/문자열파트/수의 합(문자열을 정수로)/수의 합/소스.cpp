#include <stdio.h>
#include <memory>
#include<iostream>
#include <stdlib.h>


int C(int n) {

	int r = 0;
	int k = 0,total = 0;
	
	while (n != 0) {
		//321
		r = n % 10; //1 // 2 // 3
		k = n - r; //321 - 1 // 32 - 2 // 3 - 3
		n = n / 10; // 32 // 30 // 0

		total = total + r;

	}
	return total;

}

int main() {

	int input = 0;
	char List[32] = { 0 };
	int Ndata = 0;
	int total = 0;

	printf("�Է��� ���� ����:");
	scanf_s("%d%*c", &input); //3,  321

	printf("���� ���� %d������ŭ �Է��ϼ���:", input);
	scanf_s("%s%*c", List, sizeof(List));

	Ndata = atoi(List); //ascii to integer

	total = C(Ndata);

	printf("����:%d", total);

	return 0;

}