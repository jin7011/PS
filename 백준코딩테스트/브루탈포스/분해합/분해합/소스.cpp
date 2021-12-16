#include <stdio.h>

int Get(int n) {

	int sum =  0 ;

		sum = sum + (n % 10); // 8 //9 //1
		n = n - (n % 10); // 190 // 10 // 0
		if (n >= 10) n = n / 10; // 19 // 1 // pass(n==0)
		if(n!=0)
		sum = sum+Get(n);

	return sum;
}

int GetN(int n) {

	if (n <= 10) return 0;

	for (int x = 11; x <= n; x++) 
		if (x + Get(x) == n) return x;
	
	return 0;
}

int main() {

	int m, n, output=0;

	scanf_s("%d", &n);

		output = GetN(n);

	printf("%d", output);

	return 0;
}