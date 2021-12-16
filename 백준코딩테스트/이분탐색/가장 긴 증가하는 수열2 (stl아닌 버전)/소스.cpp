#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int arr[1000001];
int n;
int k;
vector <int> vec;

int lower(int start, int end, int key) {

	while (end > start) {

		int mid = (start + end) / 2;

		if (vec[mid] < key) {
			start = mid + 1;
		}
		else {
			end = mid;
		}

	}
		return end;

} //ã���� �ϴ� key ���� ������ index��ȯ , ������ �׺��� ū�� ���� ���� ������ index��ȯ

int find(int n) {

	for (int x = 1; x < vec.size(); x++) {
		if (vec[x] == n)
			return x;
	}
	return -1;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	vec.push_back(0);
	int k = 0;
	int max = 0;

	for (int x = 0; x < n; x++) {
		cin >> arr[x];
	}

	for(int x=0; x<n; x++){

		if (arr[x] > vec.back()) {
			vec.push_back(arr[x]);
			max++;
		}
		else
		{
			if (find(arr[x]) == -1) { // �ְ��� �ϴ� ���Ұ� ���࿡ ������� ���� ���ο� ���Ҷ��
		
				k = lower(1, vec.size(), arr[x]); // take the index from here
				vec[k] = arr[x];
			}
			else { //�ְ��� �ϴ� ���Ұ� �̹� �� �ִٸ�.
				continue;
			}
			
		}
		for (int x = 1; x < vec.size(); x++)
			cout << vec[x]<< ' ';
		cout << '\n';
	}

	cout << max;


	return 0;
}