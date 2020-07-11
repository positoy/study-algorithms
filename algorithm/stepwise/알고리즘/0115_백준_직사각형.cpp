#include <iostream>
using namespace std;
int x1,y1,p1,q1,x2,y2,p2,q2;

inline void process()
{
	bool solved;
	char result;

	cin>>x1>>y1>>p1>>q1;
	cin>>x2>>y2>>p2>>q2;

	// case d.
	if (x2>p1 || p2<x1 || y2>q1 || q2<y1) {
		result = 'd';
		solved = true;
	}
	else if (!solved&
		(x1 == p2 & y1 == q2) or
		(p1 == x2 & q1 == y2) or
		(p1 == x2 & y1 == q2) or
		(x1 == p2 & q1 == y2)) {
		result = 'c';
		solved = true;	
	}
	else if (!solved&
		(x1 == p2 & p1 != x2) or
		(x1 != p2 & p1 == x2) or
		(y1 == q2 & q1 != y2) or
		(y1 != q2 & q1 == y2)) {
		result = 'b';
		solved = true;	
	}
	else {
		result = 'a';
		solved = true;	
	}


	cout << result << endl;
}

int main()
{
	process();
	process();
	process();
	process();
}
