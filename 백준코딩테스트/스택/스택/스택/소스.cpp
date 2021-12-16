#include <iostream>
#include <algorithm>
#include <memory>

using namespace std;

//push X : 정수 X를 스택에 넣는 연산이다.
//pop : 스택에서 가장 위에 있는 정수를 빼고, 그 수를 출력한다.만약 스택에 들어있는 정수가 없는 경우에는 - 1을 출력한다.
//size : 스택에 들어있는 정수의 개수를 출력한다.
//empty : 스택이 비어있으면 1, 아니면 0을 출력한다.
//top : 스택의 가장 위에 있는 정수를 출력한다.만약 스택에 들어있는 정수가 없는 경우에는 - 1을 출력한다.

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