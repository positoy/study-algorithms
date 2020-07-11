#include <iostream>
using namespace std;

int count[10];
int main()
{
	int T;
	cin >> T;

	for (int t=1; t<=T; t++)
	{
		int A,B,C,M;
		cin >> A >> B >> C;
		M = A*B*C;

		count[0] = count[1] = count[2] = count[3] = count[4] = count[5] = count[6] = count[7] = count[8] = count[9] = 0;
		while (M)
		{
			count[M%10]++;
			M /= 10;
		}

		cout << "#testcase" << t << endl;
		cout << count[0] << endl
			<< count[1] << endl
			<< count[2] << endl
			<< count[3] << endl
			<< count[4] << endl
			<< count[5] << endl
			<< count[6] << endl
			<< count[7] << endl
			<< count[8] << endl
			<< count[9] << endl;
	}
}
