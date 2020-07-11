#include <iostream>
#include <string>
using namespace std;

int main()
{
	int T;
	string A,B;
	int N;

	cin >> T;
	for (int i=1; i<=T; i++)
	{
		cin >> A >> B >> N;
		cout << "#testcase" << i << endl;
		cout << A << B << endl;
		cout << A.substr(0,N) + B.substr(N) << endl;
	}
}
