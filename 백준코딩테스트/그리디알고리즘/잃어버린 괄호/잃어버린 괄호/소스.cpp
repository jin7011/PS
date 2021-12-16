#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int n = 0;
int flag = 0;
int res = 0;
char num[51] = { 0 };


int func() {

	int x = 0;
	while (num[x] != NULL) {

		if ((int)num[x] >= '0' && (int)num[x] <= '9') {
			n *= 10;
			n += (int)num[x]-'0';
		}
		else {

			if (flag == 0)
				res += n;
			else
				res -= n;

			if (num[x] == '-') //- ÀÏ¶§,
			{
				flag = 1;
			}

			n = 0;
		}
		x++;

	}
	if (flag == 0)
		res += n;
	else
		res -= n;

	return res;
}

int main() {

	cin >> num;

	cout <<func();

	return 0;
}