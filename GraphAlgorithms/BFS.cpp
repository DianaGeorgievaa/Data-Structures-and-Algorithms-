#include<iostream>
#include<list>
#include<queue>
using namespace std;
class Graph
{
private:
	int v;
	list<int>*adj;
public:
	Graph(int v)
	{
		this->v = v;
		adj = new list<int>[v];
	}
	void AddEdge(int v, int u)
	{
		adj[v].push_back(u);
		adj[u].push_back(v);
	}
	void BFS(int s)
	{
		bool*visited = new bool[v];
		queue<int>q;
		for (int i = 0; i < v; i++)
		{
			visited[i] = false;
		}
		q.push(s);
		int element;
		visited[s] = true;
		list<int> ::iterator it;
		while (!q.empty())
		{
			element = q.front();
			cout << element << " ";
			q.pop();
			for (it=adj[element].begin(); it != adj[element].end();++it)
			{
				if (*it == 1 && visited[*it] == false)
				{
					visited[*it] = true;
					q.push(i);
				}
			}
		}
	}
};
int main()
{
	system("pause");
	return 0;
}