#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

long long mergeS(int*arr, int* temp, int l, int r);
long long merge(int*arr, int* temp, int l, int m, int r);
long long mergeSort(int * arr, int n);

int main()
{
	int q;
	cin >> q;
	int n;
	int newQ = q;
	vector<long long>answers;
	int height;
	for (int i = 0; i < q; i++)
	{
		cin >> n;
		int* soldiers = new int[n];
		int index = 0;
		int newN = n;
		while (newN>0)
		{
			cin >> height;
			soldiers[index] = height;
			index++;
			newN--;
		}
		answers.push_back(mergeSort(soldiers, n));
		newQ--;
		delete[]soldiers;
	}
	for (int i = 0; i <answers.size(); i++)
	{
		cout << answers[i] << endl;
	}
	system("pause");
	return 0;
}
long long mergeSort(int * arr, int n)
{
	int *temp = (int*)malloc(sizeof(int)*n);
	return mergeS(arr, temp, 0, n - 1);
}
long long mergeS(int*arr, int* temp, int l, int r)
{
	int m;
    long long inversions = 0;
	if (r > l)
	{
		m = (r + l) / 2;
		inversions = mergeS(arr, temp, l, m);
		inversions += mergeS(arr, temp, m + 1, r);
		inversions += merge(arr, temp, l, m + 1, r);
	}
	return inversions;
}
long long merge(int*arr, int * temp, int l, int m, int r)
{
	long long inversions = 0;
	int i = l;
	int j = m;
	int k = l;
	while ((i <= m - 1) && (j <= r))
	{
		if (arr[i] <= arr[j])
		{
			temp[k++] = arr[i++];
			
		}
		else 
		{
			temp[k++] = arr[j++];
       inversions = inversions + (m - i);
		}
	}
	while (i <= m - 1)
	{
		temp[k++] = arr[i++];
	}
	while (j <= r)
	{
		temp[k++] = arr[j++];
	}
	for (i = l; i <= r; i++)
	{
		arr[i] = temp[i];
	}
	return inversions;
}