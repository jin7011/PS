#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <functional>
#include <iterator>
#include <string>

using namespace std;

set <string> res;
vector <string> vec[55];
string str;

int n;

using namespace std;

int main(){

	cin >> n;

	for(int x=0; x<n; x++) {
		cin >> str;
		vec[str.size()].push_back(str);
	}

	//cout << '\n';
	
	for (int x =1; x <= 50; x++) { // 글자수대로 저장 1~50자

		if (vec[x].size() == 0) continue; // 글자수에 대한 저장된 내용이 없으면 패스

		else { // 있다면 가지고 있는 단어 모두 중복없이 set에 저장해서 사전순으로 출력
			for (int i = 0; i < vec[x].size(); i++)
				res.insert(vec[x][i]); // set에 해당 글자수에 대한 자료를 옮긴다
		}

		for (auto iter = res.begin(); iter != res.end(); iter++) {  //set 출력
			cout << *iter << '\n';
		}

		res.clear(); // 출력후에 set는 다음글자를 위해 비워준다

	}

	return 0;
}