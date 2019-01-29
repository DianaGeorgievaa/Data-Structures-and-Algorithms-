#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<map>
using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);
	map<int, int>m;
	map<int, int>::iterator it;
	int p = 0;
	int products = 0;
	int n;
	cin >> n;
	int id;
	int newN = n;
	while (n>0)
	{
		cin >> id;
		it = m.find(id);
		if (it != m.end())
		{
			it->second = it->second + 1;
		}
		else
		{
			m.insert({ id,1 });
		}
		n--;
	}
	for (it = m.begin(); it != m.end(); it++)
	{
		if (it->second >= 10)
		{
			while (it->second >= 10)
			{
				it->second = it->second - 10;
			}
			if (it->second>0)
			{
				products += it->second;
				p++;
			}
		}
		else
		{
			products += it->second;
			p++;
		}
	}
	cout << p << " " << products << endl;
	return 0;
}