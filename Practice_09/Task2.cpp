#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;
int equal(string*names,int n, string name)
{
	int max = -1;
	int counter = 0;
	for (int i = 0; i <n; i++)
	{
		for (int j = 0; j < name.length(); j++)
		{
			if (j >= names[i].length() || names[i][j] != name[j])
			{
				break;
			}
			counter++;
		}
		if (counter > max)
		{
			max = counter;
		}
		counter = 0;
	}
	if (counter> max)
	{
		max = counter;
	}
	return max;
}
void checkNumbers(int n)
{
	map<string, int> names;
	map<string, int> ::iterator it;
	string * newNames=new string[n];
	int counter = 0;
	string previous = "";
	string name;
	int size = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> name;
		it = names.find(name);
		if (it == names.end())
		{
			names.insert({ name, 1 });
			int index = equal(newNames,n, name);
			if (index == 0)
			{
				cout << name[0] << endl;
			}
			else
			{
				if (index != name.length())
				{
					previous = name.substr(0, index + 1);
					cout << previous << endl;
				}
				else
				{
					cout << name << endl;
				}
			}
			newNames[size] = name;
			size++;
		}
		else
		{
			counter = it->second;
			cout << name << " ";
			cout << counter + 1 << endl;
			it->second = counter + 1;
		}
	}
}
int main()
{
	std::ios::sync_with_stdio(false);
	int numberOfNames;
	cin >> numberOfNames;
	checkNumbers(numberOfNames);
	return 0;
}