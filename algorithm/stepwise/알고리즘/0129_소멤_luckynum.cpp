#include <iostream>
#include <string.h>
using namespace std;

int main()
{
	int T;
	cin >> T;
	for (int t=1; t<=T; t++)
	{
		char number[5000] = {};
		int target = 0;

		// input;
		cin >> target;

		// process
		
		int num_length = 0;
		int adder = 1;
		int sum = 0;

		while (true)
		{
			num_length++;
			adder *= 2;
			sum += adder;

			if (sum > target)
				break;
		}

		num_length -= 2;
		
		
		
		int count = 0;
		while (true)
		{
			bool counted = false;
			int i = 0;
			// 한번 더 키우기
			while (counted == false)
			{
				switch (number[i])
				{
				case 0:
					number[i] = '4';
					count++;
					counted = true;
					break;
				case '4':
					number[i] = '7';
					count++;
					counted = true;
					break;
				case '7':
					number[i] = '4';
					i++;
					break;
				}
			}
			
			if (count == target)
				break;
		}

		// 문자열 길이 찾기
		int len = strlen(number);
		// output
		cout << "#testcase" << t << endl;
		for (int j=len-1; j>=0; j--)
			cout << number[j];
		cout << endl;
	}
}
