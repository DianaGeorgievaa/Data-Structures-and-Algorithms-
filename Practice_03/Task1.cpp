#include <iostream>
using namespace std;
int days = 0;
void binarySearch(int* arr, int start, int end);
int main()
{
	int t;
	cin >> t;
	int n;
	int* results = new int[t];
	int indexForResults = 0;
	while (t > 0)
	{
		cin >> n;
		int*arr = new int[n];
		int index = 0;
		for (int i = 1; i <= n; i++)
		{
			arr[index] = i;
			index++;
		}
		t--;
		if (n == 0)
		{
			results[indexForResults] = 0;
			indexForResults++;
		}
		else
		{
			binarySearch(arr, n, n);
			results[indexForResults] = days;
			indexForResults++;
			days = 0;
		}
		delete[]arr;
	}
	for (int i = 0; i < indexForResults; i++)
	{
		cout << results[i] << endl;
	}
	delete[]results;

	system("pause");

	return 0;
}
void binarySearch(int* arr, int start, int end)
{
	int middle;
	if (start % 2 == 0)
	{
		middle = start / 2;
	}
	else
	{
		middle = (start / 2) + 1;
	}
	if (arr[middle - 1] == middle || arr[end - 1] == middle)
	{
		for (int i = middle; i <= end; i++)
		{
			if (arr[i - 1] - middle >= 0)
			{
				arr[i - 1] = arr[i - 1] - middle;
			}
		}
		days++;
		binarySearch(arr, middle, end);
	}
}