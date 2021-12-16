#include <stdio.h>

int P(int n) {

		if (n < 2 && n >=0) //n=0,n=1
			return n;
		else if (n >= 2) 
			return P(n - 1) + P(n - 2);

}

int main()
{
	int input = 0;

	printf("input:");
	scanf_s("%d", &input);

	printf("%d", P(input));

	return 0;
}