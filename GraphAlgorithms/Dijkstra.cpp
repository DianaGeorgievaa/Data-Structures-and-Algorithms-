#include<iostream>
#include<vector>
#include <queue>
#include <climits>

const int NEGATIVE = -1;

using namespace std;

class Graph
{
public:
	Graph(int n)
	{
		this->size = n + 1;
		this->g = new vector<pair<int, long long>>[this->size];
	}
	void Add(int u, int v, long long w)
	{
		this->g[u].push_back({ v,w });
		this->g[v].push_back({ u,w });
	}
	void Dijkstra(int source)
	{
		priority_queue<pair<int, long long>>q;
		vector<long long>distance(this->size, LLONG_MAX);
		for (int i = 0; i < this->size; i++)
		{
			distance[i] = LLONG_MAX;
		}
		distance[source] = 0;
		q.push({ 0,source });
		while (q.empty() == false)
		{
			int u;
			u = q.top().second;
			q.pop();
			for (auto &it : g[u])
			{
				int v;
				long long w;
				v = it.first;
				w = it.second;
				if (distance[u] + w < distance[v])
				{
					distance[v] = distance[u] + w;
					q.push({ distance[v],v });
				}
			}
		}
		for (int i = 1; i < distance.size(); i++)
		{
			if (distance[i] != 0 && distance[i] != LLONG_MAX)
			{
				cout << distance[i] << " ";
			}
			else if (distance[i] == LLONG_MAX)
			{
				cout << NEGATIVE << " ";
			}
		}
	}
private:
	int size;
	vector<pair<int, long long>>*g;
};
int main()
{
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	int n;
	int m;
	long long u;
	long long v;
	long long w;
	int s;
	while (t > 0)
	{
		cin >> n;
		cin >> m;
		Graph g(n);
		for (int i = 0; i < m; i++)
		{
			cin >> u;
			cin >> v;
			cin >> w;
			g.Add(u, v, w);
		}
		cin >> s;
		g.Dijkstra(s);
		cout << endl;
		t--;
	}

	return 0;
}