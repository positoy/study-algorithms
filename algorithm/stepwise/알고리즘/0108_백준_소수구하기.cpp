#include <iostream>
using namespace std;

bool check[1000002];
int m, n;

int main()
{
	cin >> m >> n;
	check[1] = true;
	int mul;
	for (int i = 2; i < n; i++) {
		for (int j = 2;; j++) {
			mul = i * j;
			if (mul > n || mul < 0)
				break;
			check[mul] = true;
		}
	}

	int k;
	for (int i = m; i <= n; i++) {
		if (check[i] == false)
			cout << i << endl;
	}
}
