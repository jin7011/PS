#include <iostream>
#include <algorithm>

using namespace std;

int h, m;

int main() {

	cin >> h >> m;

	if (m - 45 < 0) { // �׻� h--�� �Ͼ�� m�� 45���� ������
		m = (m + 60) - 45;
		if (h == 0)
			h = h + 24;
		h--;
	}
	else {
		m = m - 45;
	}

	cout << h << ' ' << m;

	return 0;
}