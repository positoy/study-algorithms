#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> v;
int target_position;

bool comp(string a, string b)
{
	if (a.length() <= target_position || b.length() <= target_position)
		return false;

	char comp_a, comp_b;
	comp_a = a[target_position];
	comp_b = b[target_position];

	// lower case
	if (comp_a >= 'A' && comp_a <= 'Z')
		comp_a += ('a' - 'A');

	if (comp_b >= 'A' && comp_b <= 'Z');
		comp_b += ('a' - 'A');

	// compare
		if (comp_a < comp_b)
			return true;
		else
			return false;

	// case
	// 'abc' vs 'abcd'
	// 'abc'가 먼저 나와야 한다.
}

int main()
{
	int T;
	cin >> T;

	for (int t=0; t<T; t++)
	{
		int c;
		string s;
		int max_length = 0;

		// input
		cin >> c;
		for (int i=0; i<c; i++)
		{
			cin >> s;
			v.push_back(s);
			max_length = (max_length > s.length()) ? max_length : s.length();
		}

		// process
		for (target_position=0; target_position<max_length; target_position++)
		{
			sort(v.begin(), v.end(), comp);
		}

		// output
		cout << "#testcase" << t << endl;
		for (int i=0; i<v.size(); i++)
			cout << v[i] << endl;

		// clear string vector for next case
		v.clear();
	}
}
