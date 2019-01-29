#include<iostream>

using namespace std;

int part(int* arr, int start, int end);
void sort(int* arr, int start, int end);
bool equal(int* arr, int n);

int main()
{
	int n;
	cin >> n;
	int k;
	cin >> k;
	int*toys = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> toys[i];
	}
	if (equal(toys, n) == false)
	{
		sort(toys, 0, n - 1);
	}
	if (k - toys[0] == 0 || (k - toys[0] > 0 && n == 1))
	{
		cout << 1 << endl;
	}
	else if (k - toys[0] < 0)
	{
		cout << 0 << endl;
	}
	else
	{
		int index = 0;
		for (int i = 0; i < n; i++)
		{
			k = k - toys[i];
			if (k >= 0)
			{
				index++;
			}
		}
		cout << index << endl;
	}
	delete[]toys;
	system("pause");
	return 0;

}
int part(int *arr, int start, int end)
{
	int pivot = arr[end];
	int j = start - 1;
	for (int i = start; i <= end - 1; i++)
	{
		if (arr[i] < pivot)
		{
			j++;
			swap(arr[j], arr[i]);
		}
	}
	swap(arr[j + 1], arr[end]);
	return j + 1;
}
void sort(int* arr, int start, int end)
{
	if (start < end)
	{
		int p = part(arr, start, end);
		int forStart = p - 1;
		int forEnd = p + 1;
		sort(arr, start, forStart);
		sort(arr, forEnd, end);
	}
}
bool equal(int* arr, int n)
{
	bool yes = true;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] != arr[i + 1])
		{
			yes = false;
		}
	}
	if (yes == false)
	{
		return false;
	}
	else
	{
		return false;
	}
}
