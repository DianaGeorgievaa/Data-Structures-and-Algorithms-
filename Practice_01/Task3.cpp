#include<iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include<vector>
#include <iomanip>

using namespace std;

const int MAX_SIZE = 1000;
void sort(char expression[]);
void result(char firstExpression[], char secondExpression[]);
int main() {

	char firstExpression[MAX_SIZE];
	char secondExpression[MAX_SIZE];
	fgets(firstExpression, MAX_SIZE, stdin);
	fgets(secondExpression, MAX_SIZE, stdin);

	sort(firstExpression);
	sort(secondExpression);
	result(firstExpression, secondExpression);
	
	system("pause");
	return 0;
}
void sort(char expression[])
{
	for (int i = 0; i < strlen(expression); i++)
	{
		for (int j = strlen(expression) - 1; j>i; j--)
			if (expression[j - 1] > expression[j])
			{
				int t = expression[j - 1];
				expression[j - 1] = expression[j];
				expression[j] = t;
			}
	}
}
void result(char firstExpression[], char secondExpression[])
{
	int lenOfFirstExpression = strlen(firstExpression);
	int lenOfSecondExpression = strlen(secondExpression);
	vector<char> theLongestSubstring;
	int index = 0;
	for (int i = 0; i < lenOfFirstExpression; i++)
	{
		for (int j = index; j < lenOfSecondExpression; j++)
		{
			if (firstExpression[i] == secondExpression[j])
			{
				theLongestSubstring.push_back(firstExpression[i]);
				index = j + 1;
				break;
			}
		}
	}
	for (int i = 0; i < theLongestSubstring.size(); i++)
	{
		cout << theLongestSubstring[i];
	}
	cout << endl;
}