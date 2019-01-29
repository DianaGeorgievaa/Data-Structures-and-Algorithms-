#include <iostream>
#include<stack>
#include <string>
using namespace std;
int main()
{
	stack<char>s;
	string input;
	cin >> input;
	for (int i = 0; i < input.size(); i++)
	if (input[i] == '(' || input[i] == '[' || input[i] == '{' || input[i] == '<')
	{
		s.push(input[i]);
	}
	else if (input[i] == ')' || input[i] == ']' || input[i] == '}' || input[i] == '>')
	{
		char top = s.top();
		if (top == 0)
		{
			return false;
		}
		switch (input[i])
		{
		case ')': if (top != '(') return false; break;
		case ']': if (top != '[') return false; break;
		case '}': if (top != '{') return false; break;
		case '>': if (top != '<') return false; break;
		}
		s.pop();
	}
	cout << s.empty() << endl;

	system("pause");
	return 0;

}