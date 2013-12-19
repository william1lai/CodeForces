#include <iostream>
#include <string>

using namespace std;

int main()
{
	string number;
	getline(cin, number);

	unsigned long long count = 1;
	for (int i = 0; i < number.length(); i++)
	{
		if (i < number.length() - 1)
		{
			unsigned long long runningcount = 0;
			if (number[i] - '0' + number[i+1] - '0' == 9)
			{
				runningcount = 2;
				i++;
				while (i < number.length() - 1 && number[i] - '0' + number[i+1] - '0' == 9)
				{
					runningcount++;
					i++;
				}
				if (runningcount % 2 == 1)
					count = count*2;
				i--;
			}
		}
	}
	cout << count << "\n";
	return 0;
}