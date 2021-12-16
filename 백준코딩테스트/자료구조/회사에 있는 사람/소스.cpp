//#include <iostream>
//#include <queue>
//#include <algorithm>
//#include <string>
//#include <functional>
//
//using namespace std;
//
//int t;
//
//typedef struct D {
//
//	string name;
//	string pos;
//
//}D;
//
//D* person;
//
//int add = 1;
//int index = 0;
//int q = 1;
//string n,p;
//string* str;
//int i = 0;
//
//struct compare {
//	bool operator() (const D& q, const D& w) {
//		/*if (q.name == w.name)
//			pq.
//		else*/
//			return q.name < w.name;
//	}
//};
//
//priority_queue <D, vector<D>, compare> pq;
//
//bool comp(string s1, string s2) {
//	return s1 > s2;	//string 사전 역순 
//}
//
//int findname(string str,int end) { //이름을 찾아서 인덱스를 리턴해줌.
//
//	for (int x = 0; x < end; x++) {
//		if (person[x].name == str)
//			return x;
//	}
//
//	return -1;
//}
//
//int main() {
//	
//	cin >> t;
//
//	person = new D[t + 1];
//	int k = 1;
//
//	while(t--){
//
//			cin >> n >> p;
//
//			//if (q == 1) {
//			//	person[0].name = n;
//			//	person[0].pos = p;
//			//	q--;
//			//}
//
//		 ////두번째부턴 서치하고 입력받음
//			//index = findname(n);
//
//			//if (index != -1) {
//			//	person[index].pos = p;
//			//}
//			//else {
//			
//				person[add].name = n;
//				person[add].pos = p;
//
//				//if (person[add].pos == "enter") 
//				//	pq.push(person[add]);
//				
//				add++;
//			//}	
//
//	}
//
//	for (int x = 0; x < add; x++) {
//		if (person[x].pos == "leave") {
//			index = findname(person[x].name,x);
//			person[index].pos = "leave";
//		}
//	}
//
//	for (int x = 0; x < add; x++) {
//		if (person[x].pos == "enter") {
//			pq.push(person[x]);
//		}
//	}
//
//	while (!pq.empty()) {
//		cout << pq.top().name << '\n';
//		pq.pop();
//	}
//	
//	return 0;
//}

#include<iostream>
#include<string>
#include <iterator>
#include<set>
#include <vector>

using namespace std;

int num;
set<string> logR;

int main() {
	cin >> num;
	for (int i = 0; i < num; i++) {
		string a, b;
		cin >> a >> b; // name,pos

		if (b == "enter") {
			logR.insert(a);
		}
		else if (b == "leave")
			logR.erase(a);
	}

	set<string>::reverse_iterator striter;
	for (striter = logR.rbegin(); striter != logR.rend(); striter++) {
		cout << *striter << '\n';
	}

	
	return 0;
}