#include <iostream>
using namespace std;

int main()
{
	int list[5000];
	int p, current;

	cin >> list[0] >> p;
	current = 0;

	while (true) {
		// generate
		int gen = (list[current] * list[0]) % p;

		// check duplicate
		for (int i=0; i<=current; i++) {
			if (list[i] == gen) {
				// output
				cout << current - i + 1;
#ifdef	DEBUG
cout << "result : " << current - i + 1 << endl;
for (int j=0; j<=current; j++)
cout << list[j] << ' ';
#endif

				return 0;
			}
		}

		// passed the check
		current++;
		list[current] = gen;
	}
}
