#include <iostream>
#include<vector>
using namespace std;
const long long INF = 4000000000;
class Graph
{
private:
	int size;
	int**matrix;
public:
	Graph(int size)
	{
		this->size = size + 1;
		matrix = new int *[this->size];
		for (int i = 0; i < this->size; i++)
		{
			matrix[i] = new int[this->size];
		}
		for (int i = 0; i < this->size; i++)
		{
			for (int j = 0; j < this->size; j++)
			{
				matrix[i][j] = -1;
			}
		}
	}
	void Add(long long from, long long to, long long w)
	{
		matrix[from][to] = w;
		matrix[to][from] = w;
	}
	int minDistance(vector<long long>distance, bool visited[])
	{
		long long min = INF;
		int index;
		for (int i = 0; i < size; i++)
		{
			if (visited[i] == false && distance[i] <= min)
			{
				min = distance[i];
				index = i;
			}
		}
		return index;
	}
	void print(vector<long long>distance)
	{
		for (int i = 1; i < distance.size(); i++)
		{
			if (distance[i] == INF)
			{
				cout << -1 << " ";
			}
			else if (distance[i] != 0 && distance[i] != INF)
			{
				cout << distance[i] << " ";
			}
		}
	}
	void Dijkstra(int element)
	{
		vector<long long>distance(size);
		bool*visited = new bool[size];
		for (int i = 0; i < size; i++)
		{
			distance[i] = INF;
			visited[i] = false;
		}
		distance[element] = 0;
		for (int i = 0; i < size - 1; i++)
		{
			long long u = minDistance(distance, visited);
			visited[u] = true;
			for (int i = 0; i < size; i++)
			{
				if (!visited[i] && matrix[u][i] && distance[u] != INF && matrix[u][i] != -1 && distance[u] + matrix[u][i] < distance[i])
				{
					distance[i] = distance[u] + matrix[u][i];
				}
			}
		}
		print(distance);
	}
};

int main()
{
	std::ios_base::sync_with_stdio(false);
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
	system("pause");
	return 0;
}