#include <iostream>
using namespace std;

int main()
{
	int a,b,c;
	cin >> a >> b >> c;

	int h,m,carry;
	m = (b + (c % 60)) % 60;
	carry = (b + (c % 60)) / 60;
	h = (a + c/60 + carry) % 24;

	cout << h << ' ' << m;
}
