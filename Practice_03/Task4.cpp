#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int sum(vector<int>b, vector<int>p);

int main()
{
	int n;
	cin >> n;
	vector<int>buildings;
	vector<int>prices;
	int b;
	int p;
	for (int i = 0; i < n; i++)
	{
		cin >> b;
		buildings.push_back(b);
	}
	for (int i = 0; i < n; i++)
	{
		cin >> p;
		prices.push_back(p);
	}

	cout << sum(buildings, prices) << endl;
	system("pause");
	return 0;
}

int sum(vector<int>b, vector<int>p)
{
	int s = 0;
	vector<int>allSums;
	for (int i = 0; i < b.size(); i++)
	{
		for (int j = 0; j < p.size(); j++)
		{
			if (i != j)
			{
				s += abs((b[j] - b[i]))* p[j];
			}

		}
		allSums.push_back(s);
		s = 0;
	}
	sort(allSums.begin(), allSums.end());
	return allSums[0];
}
