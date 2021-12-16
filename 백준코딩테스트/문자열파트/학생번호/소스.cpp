#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string str[1001];
string cp[1001];

int t;

bool judge() {

	for (int i = 0; i < t-1; i++) {
		for (int j = i+1; j < t; j++) {
			if (cp[i] == cp[j]) 
				return 0;	
		}
	}
	
	return 1;
}

int main() {

	cin >> t;

	for (int x = 0; x < t; x++)
		cin >> str[x];

	while (1) {

		if (!str[0].size()) break; // 다 지웠는데도 답이 안나오면

		for (int x = 0; x < t; x++) {
			cp[x] += str[x].back(); // 뒤에껄 copy해서 다른곳에 저장하고 비교
			str[x].pop_back(); // copy한 내용을 지워서 정리한다.
		}

		if (judge()) // cp 에 들었는 정보가 사실이라면
			break;

	}

	cout << cp[0].size();

}