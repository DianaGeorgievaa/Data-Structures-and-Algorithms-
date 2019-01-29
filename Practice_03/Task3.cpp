#include <iostream>
#include<vector>
#include <algorithm>
using namespace std;
vector<int>results;
vector<int>middleForResult;
int binarySearch(vector<int>clothes, int start, int end, long long k);
int main()
{
	int n;
	cin >> n;
	long long k;
	cin >> k;
	vector<int>clothes;
	int c;
	for (int i = 0; i < n; i++)
	{
		cin >> c;
		clothes.push_back(c);
	}
	sort(clothes.begin(), clothes.end());
	if (binarySearch(clothes, 0, clothes[clothes.size() - 1], k) == - 1)
	{
		int min = results[0];
		int ind = 0;
		for (int i = 1; i < results.size(); i++)
		{
			if (min > results[i])
			{
				min = results[i];
				ind = i;
			}
		}
		cout << middleForResult[ind] << endl;
	}
	else
	{
		cout << binarySearch(clothes, 0, clothes[clothes.size() - 1], k) << endl;
	}
	system("pause");
	return 0;
}
int binarySearch(vector<int>clothes, int start, int end, long long k)
{
	int middle;
	int t = 0;
	if (start <= end)
	{
		middle = (start + end) / 2;
		for (int i = 0; i < clothes.size(); i++)
		{
			if (k != 1)
			{
				if ((clothes[i] - middle) > 0)
				{
					t += (clothes[i] - middle) / (k - 1);
				}
				if (clothes[i] - middle > 0 && (clothes[i] - middle) % (k - 1) != 0)
				{
					t++;
				}
			}
			else
			{
				return clothes[clothes.size() - 1];
			}
		}
		t--;
		if (middle == t)
		{
			return middle;
		}
		else if (middle - t > 0)
		{
			int result = middle - t;
			results.push_back(result);
			middleForResult.push_back(middle);
			binarySearch(clothes, start, middle - 1, k);
		}
		else
		{
			binarySearch(clothes, middle + 1, end, k);
		}
	}
	return -1;
}