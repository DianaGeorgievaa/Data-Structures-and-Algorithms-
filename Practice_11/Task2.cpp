#include<iostream>
#include<vector>
#include <queue>
#include <climits>
#include<list>

const int NEGATIVE = -1;

using namespace std;

class Vertex
{
public:
	Vertex(int s, int d, long long c)
	{
		this->sorce = s;
		this->destination = d;
		this->cost = c;
	};
	int GetSorce() { return this->sorce; }
	int GetDestination() { return this->destination; }
	long long GetCost() { return this->cost; }

private:
	int sorce;
	int destination;
	long long cost;
};

class Graph
{
public:
	Graph(int v, int e)
	{
		this->sizeV = v + 1;
		this->sizeE = e;
	}
	void AddElement(int u, int v, long long w)
	{
		this->g.push_back(Vertex(u, v, w));
	}
	void BellmanFord(int source, int end)
	{
		vector<long long>distance(this->sizeV);
		for (int i = 0; i < this->sizeV; i++)
		{
			distance[i] = LLONG_MAX;
		}
		distance[source] = 0;
		for (int i = 1; i <= this->sizeV - 1; i++)
		{
			for (int j = 0; j < this->sizeE; j++)
			{
				int u;
				int v;
				long long w;
				u = g[j].GetSorce();
				v = g[j].GetDestination();
				w = g[j].GetCost();;
				if (distance[u] != LLONG_MAX && distance[u] + w < distance[v])
				{
					distance[v] = distance[u] + w;
				}
			}
		}
		for (int i = 1; i < distance.size(); i++)
		{
			if (distance[i] != 0 && distance[i] != LLONG_MAX && i == end)
			{
				cout << distance[i] * NEGATIVE << endl;
				break;
			}
			else if (distance[i] == LLONG_MAX && i >= end)
			{
				cout << NEGATIVE << endl;
				break;
			}
		}
	}
private:
	int sizeV;
	int sizeE;
	vector<Vertex> g;
};
int main()
{
	std::ios_base::sync_with_stdio(false);
	int n;
	int m;
	int s;
	int t;
	cin >> n;
	cin >> m;
	cin >> s;
	cin >> t;
	int firstVertex;
	int secondVertex;
	long long w;
	Graph g(n, m);
	while (m > 0)
	{
		cin >> firstVertex;
		cin >> secondVertex;
		cin >> w;
		g.AddElement(firstVertex, secondVertex, w*NEGATIVE);
		m--;
	}
	g.BellmanFord(s, t);

	return 0;
}