#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
void QuickSort(long long* arr, int n);
void findIndex(long long*arr, int n, int p, vector<int> &index);
int main()
{
	int n;
	cin >> n;
	int q;
	long long p;
	long long* numbers = new long long[n];
	int indexForResults = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> numbers[i];
	}
	QuickSort(numbers, n);
	vector<int> index;
	cin >> q;
	while (q > 0)
	{
		cin >> p;
		findIndex(numbers, n, p, index);
		q--;
	}
	for (int i = 0; i < index.size(); i += 2)
	{
		cout << index[i] << " " << index[i + 1] << endl;
	}
	delete[]numbers;
	system("pause");
	return 0;
}
void QuickSort(long long*arr, int n)
{
	if (n > 1)
	{
		int pivot = arr[rand() % n];
		int l = 0;
		for (int i = 0; i < n; i++)
		{
			if (arr[i] < pivot)
			{
				swap(arr[i], arr[l++]);
			}
		}
		QuickSort(arr, l);
		int r = n - 1;
		for (int i = n - 1; i >= l; i--)
		{
			if (pivot < arr[i])
			{
				swap(arr[i], arr[r--]);
			}
		}
		QuickSort(arr + r + 1, n - r - 1);
	}
}
void findIndex(long long *arr, int n, int p, vector<int> &index)
{
	int min = n;
	int max = -1;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] == p)
		{
			if (min > i)
			{
				min = i;
			}
			if (max < i)
			{
				max = i;
			}

		}
	}
	if (min == n && max == -1)
	{
		index.push_back(-1);
		index.push_back(-1);
	}
	else
	{
		index.push_back(min + 1);
		index.push_back(max + 1);
	}
}