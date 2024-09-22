// Source: https://usaco.guide/general/io

// Moocast

#include <bits/stdc++.h>
using namespace std;

struct Cow
{
	int x;
	int y;
	int p;
};

int N;
vector<bool> visited;
vector<Cow> cows;

bool canReach (int from, int to, int p)
{
	long long sqDistance = ((cows[from].x - cows[to].x) * (cows[from].x - cows[to].x))  
	+  ((cows[from].y - cows[to].y) * (cows[from].y - cows[to].y));

	return sqDistance <= (p*p);
}

void bfs (int i)
{
	queue<int> q;
	visited[i] = true;
	q.push(i);

	while (!q.empty())
	{
		int j = q.front();
		q.pop();
		for (int k = 0; k < N; ++k)
		{
			if (!visited[k] && (canReach(j, k, cows[j].p)))
			{
				visited[k]=true;
				q.push(k);
			}
		}
	}
}

int main() {

    freopen("moocast.in", "r", stdin);
	freopen("moocast.out", "w", stdout);
	cin >> N;

	cows = vector<Cow>(N);
	for (int i = 0; i < N; ++i)
	{
		cin >> cows[i].x >> cows[i].y >> cows[i].p;
	}

	int maxSize = 0;
	for (int i = 0; i < N; ++i)
	{
		visited = vector<bool> (N, false);
		bfs(i);	

		int curSize = 0;
		for (int j = 0; j < N; ++j)
		{
			if (visited[j]) 
			{
				curSize++;
			}
        }

		if (curSize > maxSize)
		{
			maxSize = curSize;
		}
	}

	cout << maxSize;


}
