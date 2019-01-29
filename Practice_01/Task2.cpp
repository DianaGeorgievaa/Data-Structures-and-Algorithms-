#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	int n;
	int k;
	int prices;
	cin >> n >> k;
		int count = n;
		vector<int>products;
		int sum = 0;
		while (count != 0)
		{
			   cin >> prices;
				products.push_back(prices);
				sum += prices;
				count--;
		}
		sort(products.begin(), products.end());
		int rem = n % k;
		while (rem < n)
		{
			sum -= products[rem];
			rem += k;
		}
		cout << sum << endl;
	
	system("pause");
	return 0;
}
