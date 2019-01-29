#include <iostream>
#include<vector>
#include<stack>
using namespace std;

int main()
{
	long long n;
	cin >> n;
	vector<long long>numbers;

	if (n <= 9)
	{
		for (int i = 1; i <= n; i++)
		{
			numbers.push_back(i);
		}
	}
	else
	{
		for (int i = 1; i <= 9; i++)
		{
			numbers.push_back(i);
		}

		long long first = 0;
		long long second = 0;
		for (long long i = 0; i <= numbers.size(); i++)
		{
			first = 10 * numbers[i] + numbers[i] % 10 - 2;
			second = 10 * numbers[i] + numbers[i] % 10 + 2;
			if (first > n && second > n)
			{
				break;
			}
			if (first <= n && (numbers[i] % 10) != 1 && (numbers[i] % 10) != 0)
			{
				numbers.push_back(first);
			}
			if (second <= n && (numbers[i] % 10) != 9 && (numbers[i] % 10) != 8)
			{
				numbers.push_back(second);
			}
		}
	}
	for (long long i = 0; i < numbers.size(); i++)
	{
		if (numbers[i] > 1000000)
		{
			break;
		}
		cout << numbers[i] << " ";
	}

	system("pause");
	return 0;
}