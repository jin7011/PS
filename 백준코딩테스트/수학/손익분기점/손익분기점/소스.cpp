#include <stdio.h>

int BREAK_EVEN_POINT(int x, int y,int R) {

	if ((x - y) > 0)
		return R;

}

int main() {

	int A = 1000;
	int B = 70;
	int C = 170;
	int x = 1;

	int CostTotal = 0;
	int BenefitTotal = 0;
	int PureCost = -1;

	printf("��������� �Է�:");
	scanf_s("%d%*c", &A);
	printf("�������� �Է�:");
	scanf_s("%d%*c", &B);
	printf("�Ǹűݾ��� �Է�:");
	scanf_s("%d%*c", &C);

	while (PureCost <= 0) {

		CostTotal = A + B * x;
		BenefitTotal = C * x;
		PureCost = BenefitTotal - CostTotal;
		if (PureCost > 0) {
			printf("���ͺб���:%d��", x);
			break;
		}
		else
			x++;

	}
	return 0;
}