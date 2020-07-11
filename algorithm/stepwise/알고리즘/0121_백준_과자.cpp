#include <iostream>
using namespace std;

int main()
{
	int k,n,m,result;
	cin >> k >> n >> m;

	if (k*n > m)
		result = k*n - m;
	else
		result = 0;

	cout << result;
}
