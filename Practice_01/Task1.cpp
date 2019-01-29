#include <iostream>
#include <algorithm>
using namespace std;
int timeInMinutes(int startMin, int startHour, int arrivalMin, int arrivalHour);
int main()
{
	int firstStartHour, firstStartMin, firstArrivalHour, firstArrivalMin;
	int secondStartMin, secondStartHour, secondArrivalMin, secondArrivalHour;
    int thirdStartMin, thirdStartHour, thirdArrivalMin,thirdArrivalHour;

	cin >> firstStartHour >> firstStartMin >> firstArrivalHour >> firstArrivalMin;
    cin >> secondStartHour >> secondStartMin >> secondArrivalHour >> secondArrivalMin;
	cin >> thirdStartHour >> thirdStartMin >> thirdArrivalHour >> thirdArrivalMin;

	int firstTime = timeInMinutes(firstStartHour, firstStartMin, firstArrivalHour, firstArrivalMin);
	int secondTime = timeInMinutes(secondStartHour, secondStartMin, secondArrivalHour, secondArrivalMin);
	int thirdTime = timeInMinutes(thirdStartHour, thirdStartMin, thirdArrivalHour, thirdArrivalMin);

	int minT= min(firstTime, secondTime);
	int minTime= min(minT, thirdTime);
	int maxT = max(firstTime, secondTime);
	int maxTime = max(maxT, thirdTime);
	int maxHour = maxTime / 60;
	int maxMin = maxTime % 60;
	int minHour = minTime / 60;
	int minMin = minTime % 60;
	cout << minHour << ":";
	if (minMin < 10)
	{
		cout << "0" << minMin;
	}
	else if (minMin == 0)
	{
		cout << "00";
	}
	else if(minMin >= 10)
	{
		cout << minMin;
	}
	cout << endl;
	cout << maxHour << ":";
	if (maxMin < 10)
	{
		cout << "0" << maxMin;
	}
	else if (maxMin == 0)
	{
		cout << "00";
	}
	else if (maxMin >= 10)
	{
		cout << maxMin;
	}
	cout << endl;
	system("pause");
	return 0;
}
int timeInMinutes(int startHour, int startMin, int arrivalHour, int arrivalMin)
{
	int allTimeInMinutes = 0;
	if (startMin >= 0 && startMin < 60 && arrivalMin >= 0 && arrivalMin < 60 && startHour <= 24 && startHour >= 0 && arrivalHour <= 24 && arrivalHour >= 0)
	{
		if (arrivalHour < startHour)
		{
			int hours = 24 + arrivalHour - startHour;
			allTimeInMinutes += hours * 60 + (arrivalMin - startMin);
			return allTimeInMinutes;
		}
		else if (startHour==0 && arrivalHour==0 && arrivalMin<startMin)
		{
			allTimeInMinutes += 23 * 60 + arrivalMin + startMin;
			return allTimeInMinutes;
		}
		else
		{
			allTimeInMinutes += (arrivalHour - startHour) * 60 + (arrivalMin - startMin);
			return allTimeInMinutes;
		}

	}
		return 0;
}
