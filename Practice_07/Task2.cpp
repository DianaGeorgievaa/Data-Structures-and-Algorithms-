#include<iostream>
#include<vector>
using namespace std;

void MinHeapify(vector<int> &minHeap, int i)
{
	int r = 2 * i + 2;
	int l = 2 * i + 1;
	int smallest = i;


	if (r< minHeap.size() && minHeap[r] < minHeap[smallest])
	{
		smallest = r;
	}
	if (l < minHeap.size() && minHeap[l] < minHeap[smallest])
	{
		smallest = l;
	}

	if (smallest != i)
	{
		swap(minHeap[i], minHeap[smallest]);
		MinHeapify(minHeap, smallest);
	}
};

void MinHeap(std::vector<int> &minHeap)
{
	for (int i = (minHeap.size() - 1) / 2; i >= 0; i--)
	{
		MinHeapify(minHeap, i);
	}
};
void MaxHeapify(vector<int> &maxHeap, int i)
{
	int r = 2 * i + 2;
	int l = 2 * i + 1;
	int largest = i;

	if (r < maxHeap.size() && maxHeap[r] > maxHeap[largest])
	{
		largest = r;
	}
	if ( maxHeap[l] > maxHeap[largest]&& l < maxHeap.size())
	{
		largest = l;
	}

	if (largest != i)
	{
		swap(maxHeap[i], maxHeap[largest]);
		MaxHeapify(maxHeap, largest);
	}
};

void MaxHeap(vector<int> &maxHeap)
{

	for (int i = (maxHeap.size() - 1) / 2; i >= 0; i--)
	{
		MaxHeapify(maxHeap, i);
	}
};

void CalculateMedian(vector<int> &numbers, vector<int> &minHeap, vector<int> &maxHeap, double &median)
{
	if (numbers.back() < median)
	{
		maxHeap.push_back(numbers.back());
		if (maxHeap[maxHeap.size() - 1] > maxHeap[0])
		{
			swap(maxHeap[0], maxHeap[maxHeap.size() - 1]);
		}
	}
	else
	{
		minHeap.push_back(numbers.back());
		if (minHeap[minHeap.size() - 1] < minHeap[0])
		{
			swap(minHeap[0], minHeap[minHeap.size() - 1]);
		}
	}
	int diff = (maxHeap.size() - minHeap.size());
	if (abs(diff) > 1)
	{
		if (maxHeap.size() > minHeap.size()) {
			swap(maxHeap[0], maxHeap[maxHeap.size() - 1]);
			minHeap.push_back(maxHeap.back());
			maxHeap.pop_back();
			swap(minHeap[0], minHeap[minHeap.size() - 1]);
			MaxHeap(maxHeap);
		}
		else {
			swap(minHeap[0], minHeap[minHeap.size() - 1]);
			maxHeap.push_back(minHeap.back());
			minHeap.pop_back();
			std::swap(maxHeap[0], maxHeap[maxHeap.size() - 1]);
			MinHeap(minHeap);
		}
	}
	 
   if (maxHeap.size() > minHeap.size())
	{
		median = (double)maxHeap[0];
	}
   else if (maxHeap.size() == minHeap.size())
   {
	   median = (double)(minHeap[0] + maxHeap[0]) / 2.0;
   }
	else
	{
		median = (double)minHeap[0];
	}
	
}


int main()
{
	int n, value;
	double median = 0;
	vector<int> min;
	vector<int> max;
	vector<int> numbers;
	scanf("%d", &n);
	while (n > 0)
	{
		scanf("%d", &value);
		numbers.push_back(value);
		CalculateMedian(numbers, min, max, median);
		printf("%.1f \n", median);
		n--;
	}

	return 0;
	system("pause");
}
