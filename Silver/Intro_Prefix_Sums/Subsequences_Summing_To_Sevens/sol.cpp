
#include <bits/stdc++.h>
#include <vector>
using namespace std;

using ll = long long;
using vll = vector<ll>;

int main() {

    freopen("div7.in", "r", stdin);
	freopen("div7.out", "w", stdout);

    int N;
    cin >> N;
    vll cows(N+1);

    for (int i = 1; i <= N; ++i)
    {
        cin >> cows[i];
    }

    vll sums(N+1);
    sums[0]=0;
    for (int i = 1; i <= N; ++i)
    {
        sums[i] = (sums[i-1] + cows[i]) % 7;
    }

    vll modFirstOcur(7,-1);
    vll modLastOcur(7,-1);
    for (int i = 1; i <= N; ++i)
    {
        if (modFirstOcur[sums[i]] == -1)
        {
            modFirstOcur[sums[i]] = i;
        }

        modLastOcur[sums[i]] = i;
    }

    ll maxSizeGroup = 0;
    for (int i = 0; i < 7; ++i)
    {
        if (modFirstOcur[i] != -1 && modLastOcur[i] != -1)
        {
            ll groupSize = modLastOcur[i] - modFirstOcur[i];
            if (groupSize > maxSizeGroup)
            {
                maxSizeGroup = groupSize;
            }
        } 
    }
    cout << maxSizeGroup;
}
