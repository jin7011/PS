#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;

int postorder[100001];
int inorder[100001];
int pos[1000001];

void func(int instart , int inend, int postart,int poend) {

	if (instart > inend || postart > poend) 
		return; // �������̸� return �ϰ� root -> left- > right -> return ������ �Լ�ȣ��

	int root = postorder[poend];

	cout << root << ' ';

	int idx = pos[root]; // root �� ����ִ� inorder�� idx�� ����

	int child = idx - instart; // idx - instart �� �ǹ̴� �ڽķ�Ʈ�� �����̱⵵�ϴ�.** index+1 = child�̰�

	func( instart , idx -1 , postart , postart + child-1 ); //left side
	func(idx+1, inend, postart + child , poend-1); //right side 
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	for (int x = 0; x < n; x++) {
		cin >> inorder[x];
	}
	
	for (int x = 0; x < n; x++) {
		cin >> postorder[x];
	}

	for (int x = 0; x < n; x++) {
		pos[inorder[x]] = x;
	}


	func(0, n-1, 0, n - 1);
	return 0;
}