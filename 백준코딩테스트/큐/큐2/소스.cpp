#include <iostream>
#include <algorithm>
#include <queue>
#include <memory>

using namespace std;
int n = 0;
string str;

queue <int> que;

int main() {
	cin >> n;
	
	while (n--) {
		int t;
		cin >> str;

		if (str[0] == 'p') {
			if (str[1] == 'u') {
				scanf_s("%d", &t);
				que.push(t);
			}
			if (str[1] == 'o') {
				if (que.size() == 0)
					cout << "-1\n";
				else
					que.pop();
			}

		}
		if (str[0] == 's') {
			printf("%d", que.size());
		}
		if (str[0] == 'e') {
			if (que.size() == 0)
				cout << "-1\n";
			else
				cout <<	que.empty();
		}
		if (str[0] == 'f') {
			if (que.size() == 0)
				cout << "-1\n";
			else
				cout << que.front();
		}
		if (str[0] == 'b') {
			if(que.size() == 0)
				cout << "-1\n";
			else
				cout << que.back();
		}

	}

	return 0;
}