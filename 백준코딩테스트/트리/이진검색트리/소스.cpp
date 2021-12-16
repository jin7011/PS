#include <iostream>
#include <algorithm>
#include <vector>
#define IFT 1e5;

using namespace std;

typedef struct Node {
	//Node* root;
	int left;
	int right;
}Node;

Node node[1000001];
int a[1000001]; // preorder 저장소
int n;

void func(int root,int start,int end) {
	int idx = end + 1;

	if (start > end) return;

	for (int x = start+1; x<=end; x++) {// root에 대한 첫번째 right의 인덱스 있으면 반환 or end+1 반환
		if (a[x] > root) {
			idx = x;
			break;
		}
	}
	
	if (start != end && root > a[start + 1]) {// 범위안에 있고, 더 작은값만을 left로 가진다.
		node[root].left = a[start + 1];
	}
	if (idx != end + 1 && root < a[idx]) {
		node[root].right =a[idx];
	}

	func(a[start+1],start+1,idx-1); // left
	func(a[idx],idx,end); // right

}

void printPost(int root) {

	if (root == 0) return;

	printPost(node[root].left);
	printPost(node[root].right);
	
	cout << root<<'\n';
}

int main() {

	int x;
	for ( x = 0; scanf_s("%d", &a[x]) > 0; x++);
	
	func(a[0],0,x-1);

	printPost(a[0]);

	return 0;
}