#include <iostream>
#include<string>
using namespace std;
int max(string s);
int main()
{
	string s;
	cin >> s;
	int count = max(s);
	int len = s.length();
	int withoutRep = len - count;
	if (len == 1 || count==1)
	{
		cout << "Yes";
	}
	else if (withoutRep == 0)
	{
		cout << "No";

	}
	else if (count-1 > len - count)
	{
		cout <<"No";
	}
	else
	{
		cout <<"Yes";
	}
	
	system("pause");
	return 0;

}
int max(string s)
{
	int maxFreq = s[0];
	int frequency = 1;
	for (int i = 0; i < s.length(); i++)
	{
		int count = 0;
		for (int j = 0; j < s.length(); j++)
		{
			if (s[i] == s[j]) {
				count++;
			}
		}
		if (count > frequency) {
			frequency = count;
			maxFreq = s[i];
		}
	}
	return frequency;
}
