#include <iostream>
#include<stack>
#include <string>
using namespace std;
long long max(long long*arr, long long n);
int main()
{
	long long n;
	cin >> n;
	stack<long long>s;
	string input;
	long long sum = 0;
	long long maxElement = 0;
	long long* arrayForMax = new long long[n];
	long long index = 0;
	string k;
	while (n >= 0)
	{
		getline(cin, input);
		if (input[0] == 'w')
		{
			long long newInput = stoi(input.substr(6, input.size()));
			s.push(newInput);
		}
		else if (input[0] == 'g')
		{
			k = input.substr(6, input.size());
			long long newK = stoi(k);
			while (newK > 0)
			{
				sum = sum + s.top();
				s.pop();
				newK--;
			}
			s.push(sum);
			sum = 0;
		}
		else if (input[0] == 'b')
		{
			k = input.substr(5, input.size());
			long long newK = stoi(k);
			while (newK > 0)
			{
				arrayForMax[index] = s.top();
				index++;
				s.pop();
				newK--;
			}
			maxElement = max(arrayForMax, index);
			s.push(maxElement);
			index = 0;
		}
		n--;
	}
	long long size = s.size();
	long long *arrPrint = new long long[size];
	long long ind = 0;
	while (!s.empty())
	{
		long long value;
		value = s.top();
		arrPrint[ind] = value;
		s.pop();
		ind++;
	}

	for (int i = ind - 1; i >= 0; i--)
	{
		cout << arrPrint[i] << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}

long long max(long long*arr, long long n)
{
	long long m = arr[0];
	for (int i = 0; i < n; i++)
	{
		if (m < arr[i])
		{
			m = arr[i];
		}
	}
	return m;
}