#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std; 

vector <pair<int, int> > map[100002];
queue <int> qu;

int N;
int maxDistance; 

void input() {

    int starter, end, distance;

    scanf_s("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf_s("%d", &starter);

        for (;;)
        {
            scanf_s("%d", &end);

            if (end == -1) break;

            scanf_s("%d", &distance);

            map[starter].push_back(make_pair(end, distance));
            map[end].push_back(make_pair(starter, distance));
        }
    }
}

int bfs(int index) {

    qu.push(index);

    int visited[100002] = { 0, };
    int result[100002] = { 0, };
    int maxPoint = 0; 
    int max = 0;

    while (!qu.empty()) {

        int starter = qu.front();
        qu.pop();

        visited[starter] = 1;

        for (int i = 0; i < map[starter].size(); i++) {

            pair<int, int> next = map[starter][i]; // �ڽĳ���� ����
            int nextPoint = next.first; // 3 //�ڽĳ��
            int distance = next.second; // 2 //��Ʈ������ �Ÿ�

            if (visited[nextPoint] == 0 && result[nextPoint] < distance + result[starter]) // ���������� ��� �׸��� ����ġ�ִ븦 ������
            {
                result[nextPoint] = distance + result[starter];
                qu.push(nextPoint);

                if (max < result[nextPoint])
                {
                    maxPoint = nextPoint;
                    max = result[nextPoint];
                }
            }
        }
    }

    maxDistance = max;

    return maxPoint; // ó�� 1���� ���� bfs�� ������带 ���ϰ� �� ������带 �ٽ� bfs�� ������. 
    //� ��忡�� ���� �� �Ÿ��� �ִ� ��带 ���ϰ� �� ���� ���� �ָ��ִ� ����� �Ÿ��� ��ü Ʈ���� ���� �� ������ �ȴ�.
    // 2���� bfs�� ��������ν� ���ͽ�Ʈ�󺸴� �޸𸮿� �ð��� ���� ��� �� �� �ִ�.
}

int main() {

    input();
    bfs(bfs(1));

    printf("%d", maxDistance);

}


