#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<int>elements;
	int element;
	for (int i = 0; i < n; i++)
	{
		cin >> element;
		elements.push_back(element);
	}
	bool isExist = false;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < n; k++)
			{
				if ((elements[i] + elements[j] == elements[k]) && i != j && j != k && k != i)
				{
					isExist = true;
				}
			}
		}
	}

	if (isExist == true)
	{
		std::cout << "true" << std::endl;
	}
	else
	{
		std::cout << "false" << std::endl;
	}

	return 0;
}
