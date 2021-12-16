#include<iostream>
#include<vector>
#include <functional>
#include<algorithm>
#include<math.h>
#include <set>

using namespace std;
int n; // n개 입력
//vector <int> res;
set <int> res;
vector<int> arr;

int func() {
    int sum = 0;

    for (int x = 0; x < n-1; x++) {
        sum += abs(arr[x] - arr[x + 1]);
    }

    return sum;
}

int main()
{
    int a;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> a;
        arr.push_back(a); // 1~n 까지 삽입.. 
    }

    sort(arr.begin(), arr.end());

    do
    {
        res.insert(func());

    } while (next_permutation(arr.begin(), arr.end()));

    cout << *max_element(res.begin(),res.end());
}