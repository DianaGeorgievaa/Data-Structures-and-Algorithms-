#include <vector>
#include <iostream>
#include <deque>

using namespace std;
vector<vector<int>> adjacency(vector<int> &firstElements, vector<int> &secondElements);
void solution(vector<vector<int>> &adj);

int main()
{
	vector<int> firstElements;
	vector<int>secondElements;
	int n;
	cin >> n;

	int first;
	int second;
	while (n>0)
	{

		cin >> first;
		cin >> second;
		firstElements.push_back(first - 1);
		secondElements.push_back(second - 1);
		n--;
	}
	auto adj = adjacency(firstElements, secondElements);
	solution(adj);
}
vector<vector<int>> adjacency(vector<int> &firstElements, vector<int> &secondElements)
{

	vector<vector<int>> adj(2 * firstElements.size(), vector<int>());
	for (int i = 0; i<firstElements.size(); ++i)
	{
		adj[firstElements[i]].push_back(secondElements[i]);
		adj[secondElements[i]].push_back(firstElements[i]);
	}
	return adj;
}
void solution(vector<vector<int>> &adj)
{

	vector<bool> visited(adj.size(), false);
	deque<int> q;
	int i = 0;
	int min = 0;
	int max = adj.size();
	while (i != adj.size())
	{
		q.push_back(i);
		visited[i] = true;
		int counter = 0;
		while (!q.empty())
		{
			int top = q.front();
			q.pop_front();
			++counter;
			for (auto k : adj[top])
			{
				if (!visited[k])
				{
					visited[k] = true;
					q.push_back(k);
				}
			}
		}
		if (counter>max)
		{
			max = counter;
		}
		if (counter != 1 && counter<min)
		{
			min = counter;
		}
		while (i != adj.size() && visited[i])
			++i;
	}
	cout << min << " " << max;
}
