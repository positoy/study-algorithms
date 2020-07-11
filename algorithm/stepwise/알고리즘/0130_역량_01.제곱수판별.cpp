#include <iostream>
using namespace std;

int main()
{
	int T;
	cin >> T;

	for (int t=1; t<=T; t++)
	{
		bool prime = false;
		int n;
		// input
		cin >> n;

		// process
		for (int i=1; i*i<=n; i++)
		{
			if (i*i == n)
			{
				prime = true;
			}
		}

		// output
		cout << "#testcase" << t << endl;
		if (prime)
		{
			cout << "yes" << endl;
		}
		else
		{
			cout << "no" << endl;
		}
	}
}
