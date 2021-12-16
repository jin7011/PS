#include <deque>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>>

using namespace std;

typedef struct Data {
	int a;
	bool b;
};

int n, m = 0 ;
deque <Data> dque;
int cnt = 0;

void first() { // deque.front() and pop
	dque.pop_front();
}

void second() { //dque.push_back(dque.front()) and  deque.front()_pop �������� ȸ��
	dque.push_back(dque.front());
	dque.pop_front();
	cnt++;
}

void third() { //dque.push_front(dque.back()) and  deque.back()_pop ���������� ȸ��
	dque.push_front(dque.back());
	dque.pop_back();
	cnt++;
}

int Findleft() {
	int middle = (dque.size() / 2) + 1;
	for (int x = dque.size() - 1; x >= middle; x--)
		if (dque[x].b == 1) 
			return x;

	return -1;
}

int Findright() {
	int middle = (dque.size() / 2) + 1;
	for (int p = 1; p < middle; p++) 
		if (dque[p].b == 1) 
			return p;

	return -1;

}

void Checkbool(int q) {

	for (int x = 0; x < dque.size(); x++) {
		if (dque[x].a == q) {
			dque[x].b = 1;
			return;
		}
	}

}

int main() {
	int t = 0;
	int k = 1;
	int pick = 0;
	cin >> n >> m;
	int o = m;
	int res = 0;

	while (k != n+1) {
		dque.push_back({ k,0 });
		k++;
	}

	while (o--) { // �̰��� �ϴ� �迭�� true���� �ִ´�. b�� 1�� index�� a�� ����

		cin >> t;
		Checkbool(t);
		pick = 0;
		cnt = 0;

		while (pick != 1) {

			int r = -1;
			int l = -1;

			if (dque.front().b == 1) {
				dque.front().b == 0;
				first();
				pick++;
				continue;
			}
			else { //middle �ڷ� true�� �ְ� middle������ true�� ���� ��, �� index���� n+2(���ֺ��� ��)�� ��, ������ ������ �����̴�.  // �����ʿ��� �Ѵ� �ִٴ� �����Ͽ�,

				l = Findleft(); //���� ���� üũ
				if(l == -1)
				r = Findright();//������ üũ

				if (r != -1) //�����ʿ� �ִٸ�,
				{
					second();
					continue;
				}
				else {
					third();
					continue;
				}

			}
		}

		res += cnt;
	}
	cout << res;
	return 0;
}