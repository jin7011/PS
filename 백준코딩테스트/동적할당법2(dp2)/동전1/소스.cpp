#include<iostream>

using namespace std;

int coin_cost[101];
int sum_of_cost[10001];

int main() {
    int N, K, count(0);
    std::cin >> N >> K;
    for (int i = 1; i <= N; i++) {
        std::cin >> coin_cost[i];
    }

    sum_of_cost[0] = 1;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= K; j++) {
            if (j >= coin_cost[i]) {
                sum_of_cost[j] += sum_of_cost[j - coin_cost[i]];
            }
        }
    }

        cout << sum_of_cost[K];
    

    //std::cout << sum_of_cost[K];
}
