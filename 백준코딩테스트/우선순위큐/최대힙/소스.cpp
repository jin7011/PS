#include<iostream>
#include<queue>
using namespace std;

int main() {
   
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    int temp;
    priority_queue< int, vector<int>, less<int> > pq;
    
    cin >> N;

    for (int i = 0; i < N; i++) {

        cin >> temp;

        if (temp != 0) {
            pq.push(temp);
        }
        else if (pq.size() == 0)
            cout << 0 << '\n';
        else {
            cout << pq.top() << '\n';
            pq.pop();
        }

    }

    return 0;
}

