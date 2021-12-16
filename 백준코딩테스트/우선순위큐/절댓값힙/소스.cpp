#include <iostream>
#include <vector>
#include <functional>
#include <math.h>
#include <algorithm>
#include <queue>

using namespace std;

typedef struct D {
	int x;
	int absx;
}D;

D a;

struct compare {
	bool operator() (const D& q, const D& w) {
		if (q.absx == w.absx)
			return q.x > w.x;
		else
			return q.absx > w.absx;
	}
};

long long n;
priority_queue< D, vector<D>, compare > pq;
int k;



int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	
	while (n--) {

		cin >> k;
		a.absx = abs(k);
		a.x = k;

		if (k != 0) {
			pq.push(a);
		}
		else {
			if (pq.size() != 0) {
				cout << pq.top().x<< '\n';
				pq.pop();
			}
			else {
				cout << 0 << '\n';
			}
		}

	}

	return 0;
}