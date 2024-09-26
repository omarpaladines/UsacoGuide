#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

struct Holes
{
    int w;
	int x;
	int y;
};

bool compareByW(const Holes& p1, const Holes& p2)
{
    return p1.w < p2.w;
}

vector<int> origPos;
vector<Holes> holes;
vector<vector<int>> adj;
vector<bool> visited;
vector<int> compNumber;

void dfs(int current_node, int compNumber) {
	if (visited[current_node]) { return; }
	visited[current_node] = true;
    compNumber[current_node] = compNumber;

	for (int neighbor : adj[current_node]) { dfs(neighbor, compNumber); }
}

// Forms the graph with holes of width at least W and checks if each node can reach
// the position
bool isConnected(int N, int M, int W)
{
    adj = vector<vector<int>>(N+1);
    for (int i = 0; i < M; ++i)
    {
        if (holes[i].w >= W)
        {
            adj[holes[i].x].push_back(holes[i].y);
            adj[holes[i].y].push_back(holes[i].x);
        }
    }

    bool canReach = true;
    visited = vector<bool>(N+1, false);
    compNumber = vector<int>(N+1, -1);
    int compCount = 0;
    for (int i = 1; i <= N; ++i)
    {
        if (visited[i]) continue;
        compCount++;
        dfs(i, compCount);

        // if the node is not in position, check that the dfs reaches the position.
        if (i != origPos[i])
        {
            if (compNumber[i] != compNumber[origPos[i]])
            {
                canReach = false;
                break;
            }
        }
    }

    return canReach;
}

void solve(int N, int M)
{
    int lo = 0; 
    int hi = M;
    while (lo < hi) 
    {
		// find the middle of the current range (rounding up)
		int mid = lo + (hi - lo + 1) / 2;
		if (isConnected(N, M, holes[mid].w)) {
			// if mid works, then all numbers smaller than mid also work
			lo = mid;
		} else {
			// if mid does not work, greater values would not work either
			hi = mid - 1;
		}
	}
	cout << holes[lo].w << endl;
}

int main() {

    freopen("wormsort.in", "r", stdin);
	freopen("wormsort.out", "w", stdout);
    int N, M;
    cin >> N >> M;

    origPos = vector<int>(N+1);
    for (int i = 1; i <= N; ++i)
    {  
        cin >> origPos[i];
    }

    holes = vector<Holes>(M);
    for (int i = 0; i < M; ++i)
    {
        cin >> holes[i].x;
        cin >> holes[i].y;
        cin >> holes[i].w;
    }
    sort(holes.begin(), holes.end(), compareByW);

    bool areAllInPlace = true;
    for (int i = 1; i <= N; ++i)
    {
        if (origPos[i] != i)
        {
            areAllInPlace = false;
        }
    }

    if (areAllInPlace)
    {
        cout << -1 << endl;
    }
    else
    {
       solve(N, M);
    }
}
