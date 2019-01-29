#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<functional>
#include<queue>
#include<climits>
using namespace std;

class Graph
{
private:
	int size;
	vector<pair<int, int>>*g;
public:
	Graph(int n)
	{
		this->size = n + 1;
		this->g = new vector<pair<int, int>>[size];
	}
	void Add(int u, int v, int w)
	{
		this->g[u].push_back({ v,w });
		this->g[v].push_back({ u,w });

	}
	void Dijkstra(int source)
	{
		vector<long long >distance(size,LLONG_MAX);
		priority_queue<pair<int, int>, vector<pair<int, int>>, std::greater<pair<int, int>>>q;
		distance[source] = 0;
		q.push({ 0,source });
		while (!q.empty())
		{
			int u = q.top().second;
			q.pop();
			for (auto & it : g[u])
			{
				int v = it.first;
				int w = it.second;
				if (distance[u] + w < distance[v])
				{
					distance[v] = distance[u] + w;
					q.push({ distance[v],v });
				}
			}
		}
		for (int i = 1; i<distance.size(); i++)
		{
			if (distance[i] != LLONG_MAX && distance[i] != 0)
			{
				cout << distance[i] << " ";
			}
		}
	}
};

int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	int m;
	cin >> n;
	cin >> m;
	int u, v, w;
	Graph g(m);
	for (int i = 0; i<m; i++)
	{
		cin >> u;
		cin >> v;
		cin >> w;
		g.Add(u, v, w);
	}
	int s;
	cin >> s;
	g.Dijkstra(s);
	return 0;
}




