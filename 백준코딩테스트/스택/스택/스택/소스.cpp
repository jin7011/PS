#include <iostream>
#include <algorithm>
#include <memory>

using namespace std;

//push X : ���� X�� ���ÿ� �ִ� �����̴�.
//pop : ���ÿ��� ���� ���� �ִ� ������ ����, �� ���� ����Ѵ�.���� ���ÿ� ����ִ� ������ ���� ��쿡�� - 1�� ����Ѵ�.
//size : ���ÿ� ����ִ� ������ ������ ����Ѵ�.
//empty : ������ ��������� 1, �ƴϸ� 0�� ����Ѵ�.
//top : ������ ���� ���� �ִ� ������ ����Ѵ�.���� ���ÿ� ����ִ� ������ ���� ��쿡�� - 1�� ����Ѵ�.

typedef struct Node {
	int num;
	Node* Next;
}Node;

typedef struct listStack {
	int size;
	Node* peak;
}listStack;

void createStack(listStack** Stack) {

	(*Stack) = new listStack;
	(*Stack)->peak = NULL;
	(*Stack)->size = 0;

}

void NewNode(int n) {

	Node* NewNode = new Node;
	NewNode->num = n;

}

void deleteNode(Node* rmNode) {
	free(rmNode);
}

void deleteStack(listStack* Stack) {

	Node* tempNode;

	for (int x = 0; x < Stack->size; x++) {
		tempNode = Pop(Stack);
		deleteNode(tempNode);
	}
	free(Stack);
}

void Push(listStack* Stack, Node* newNode) {

	//when stack is empty
	if (Stack->size == 0) {
		Stack->peak = newNode;
	}
	//when stack is not empty
	else {
		newNode->Next = Stack->peak;
		Stack->peak = newNode;
	}
	Stack->size++;

}

Node* Pop(listStack* Stack) {

	Node* tempNode;

	//when stack is empty
	if (Stack->size == 0) tempNode = NULL ;

	//when stack is not empty
	else {
		tempNode = Stack->peak;
		Stack->peak = Stack->peak->Next;
		Stack->size--;
	}
	return tempNode;

}

int main() {



	return 0;
}