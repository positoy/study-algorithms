#include <iostream>
#define DEBUG
using namespace std;

int T;
long long int M;
int D,W;
int x,line[10000],setline;
int offset;

int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a%b);
}

inline int ceilingDivide(int a, int b)
{
	if (a%b == 0)
		return a/b;
	else
		return a/b + 1;
}

int main()
{
	cin >> T;
	for (int i=1; i<=T; i++)
	{
		cin >> M >> D >> W;

		offset = D % W;
		int g = gcd(offset, W);
		int cycle = W / g; // lcm 나누기 offset

		setline = 0;
		for (int j=0; j<cycle; j++) {
			line[j] = ceilingDivide(M+(offset*j%W), W);
			setline += line[j];
		}
		
		int a,b;
		a = M/cycle;
		b = M%cycle;

#ifdef DEBUG
cout << '(' << a << ", " << b << ')' << endl;
#endif
		int result = setline*a;
		for (int j=0; j<b; j++)
			result += line[j];
		// output
		cout << "#testcase" << i << endl;
		cout << result << endl;
	}

}