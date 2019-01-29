#include <vector>
#include <iostream>
using namespace std;
void SortSocks(vector<int> &shortSocks, vector<int> &longSocks);
int main()
{
	int n;
	int k;
	cin >> n >> k;
	vector<int> lengthOfSocks;
	vector<int> longSocks;
	vector<int> shortSocks;
	int index = 0;
	while (index < n)
	{
		int lenOfSocks;
		cin >> lenOfSocks;
		lengthOfSocks.push_back(lenOfSocks);
		index++;
	}
	for (int i = 0; i < lengthOfSocks.size(); i++)
	{
		for (int j = i + 1; j < lengthOfSocks.size(); j++)
		{
			shortSocks.push_back(lengthOfSocks[i]);
			longSocks.push_back(lengthOfSocks[j]);
		}
	}
	SortSocks(shortSocks, longSocks);
	cout << shortSocks[k - 1] << " " << longSocks[k - 1] << endl;

	return 0;
}

void SortSocks(vector<int> &shortSocks, vector<int> &longSocks)
{
	int min;
	int ind;

	for (int i = 0; i < shortSocks.size(); i++)
	{
		min = longSocks[i] - shortSocks[i];
		ind = i;
		for (int j = i + 1; j < longSocks.size(); j++)
		{
			if (j != i)
			{
				if (min > longSocks[j] - shortSocks[j])
				{
					ind = j;
					min = longSocks[j] - shortSocks[j];
				}
				else if (min == longSocks[j] - shortSocks[j])
				{
					if (shortSocks[i] > shortSocks[j])
					{
						ind = j;
					}
				}
			}
		}
		std::swap(shortSocks[i], shortSocks[ind]);
		std::swap(longSocks[i], longSocks[ind]);
	}
}