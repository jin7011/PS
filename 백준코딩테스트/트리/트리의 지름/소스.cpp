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

            pair<int, int> next = map[starter][i]; // 자식노드의 정보
            int nextPoint = next.first; // 3 //자식노드
            int distance = next.second; // 2 //루트노드와의 거리

            if (visited[nextPoint] == 0 && result[nextPoint] < distance + result[starter]) // 가보지않은 노드 그리고 간선치최대를 비교저장
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

    return maxPoint; // 처음 1부터 돌린 bfs로 지름노드를 구하고 그 지름노드를 다시 bfs로 돌린다. 
    //어떤 노드에서 가장 먼 거리에 있는 노드를 구하고 그 노드와 가장 멀리있는 노드의 거리는 전체 트리의 가장 긴 지름이 된다.
    // 2번의 bfs를 사용함으로써 다익스트라보다 메모리와 시간을 적게 사용 할 수 있다.
}

int main() {

    input();
    bfs(bfs(1));

    printf("%d", maxDistance);

}


