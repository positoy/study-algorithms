#include <iostream>
using namespace std;

int main()
{
	int t,n;
	cin >> t;

	for (int i=1; i<=t; i++)
	{
		bool prime = true;
		cin >> n;

		// 2를 제외한 짝수판별
		if (n == 2) {
			prime = true;
	
		} else if (n%2 == 0) {
			prime = false;
	
		} else {
		// 전부 테스트
			for (int j=3; j*j <= n; j=j+2) {
				if (n%j == 0)
					prime = false;
			}
		}

		cout << "#testcase" << i << "." << endl;
		if (prime)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
}
