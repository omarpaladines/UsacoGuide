
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vll = vector<ll>;

int main() {

    int N, K;
    cin >> N >> K;
    vll diff(N+2, 0);

    for (int i = 0; i < K; ++i)
    {
        int a, b;
        cin >> a >> b;
        diff[a]++;
        diff[b+1]--;
    }

    vll stacks(N+1, 0);
    for (int i = 1; i <= N; ++i)
    {
        stacks[i] = stacks[i-1] + diff[i];
    }

    std::sort(stacks.begin(), stacks.end());
    cout << stacks[(N/2) + 1] << endl;
}
