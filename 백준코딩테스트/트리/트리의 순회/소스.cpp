#include<iostream>
#include <algorithm>

using namespace std;

typedef struct node {
	char right;
	char left;
}node;

node Node[27];

int n;
char root,l,r;

void pre(char tree) { // root - left - right ¼ø¼­
	if (tree == '.')
		return;
	else {
		cout << tree;
		pre(Node[tree].left);
		pre(Node[tree].right);
	}

}

void in(char tree) { // left - root - right
	if (tree == '.')
		return;
	else {
		in(Node[tree].left);
		cout << tree;
		in(Node[tree].right);
	}
}

void post(char tree) { // left - right - root
	if (tree == '.')
		return;
	else {
		post(Node[tree].left);
		post(Node[tree].right);
		cout << tree;
	}
}

int main() {

	cin >> n;

	for (int x = 0; x < n; x++) {
		cin >> root >>l>>r ;
		Node[root].left = l;
		Node[root].right = r;
	}

	pre('A'); cout << '\n';
	in('A'); cout << '\n';
	post('A'); 

	return 0;
}