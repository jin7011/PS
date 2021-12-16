#include <stdio.h>
#include <stdlib.h>
#include <memory>
#include <iostream>
typedef struct Data {

	int x, y;

}Data;

void swap(Data& a, Data& b) { // swap(a[k],a[p]);

	Data temp;

	temp = a;
	a = b;
	b = temp;

}

void sortx(Data* a,int T) {

	Data temp = { 0 };

	for(int k=0;k<T-1;k++)
		for (int p = k+1; p < T; p++) {
			if (a[k].x >= a[p].x) {
				swap(a[k], a[p]);
			}
		}

}

int main() {

	int T = 0; 
	scanf_s("%d", &T);
	Data *a = NULL;

	a = (Data*)malloc(sizeof(Data) * T);

	for (int i = 0; i < T; i++)
		scanf_s("%d%d", &a[i].x, &a[i].y);

	sortx(a,T);

	for (int k = 0; k < T-1; k++) {

		if (a[k].x == a[k + 1].x && a[k].y > a[k + 1].y) 
			swap(a[k], a[k + 1]);
		
	}
	//print
	for (int k = 0; k < T; k++)
		printf("(%d, %d) ", a[k].x, a[k].y);

	
	return 0;
}

//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//int main(void)
//{
//	int n;
//	std::cin >> n;
//
//	std::vector<std::pair<int, int>> point;
//	int x, y;
//	for (int i = 0; i < n; i++)
//	{
//		std::cin >> x >> y;
//		point.push_back(std::pair<int, int>(x, y));
//	}
//	std::sort(point.begin(), point.end());
//
//	for (int i = 0; i < point.size(); i++)
//		std::cout << point.at(i).first << " " << point.at(i).second << "\n";
//}
//[출처] [백준] 11650번 문제 : 좌표 정렬하기 | 작성자 밍기적