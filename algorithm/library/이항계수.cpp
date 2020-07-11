/**
 * 다이나믹 프로그래밍을 이용해서 '이항계수' 구하기.
 *
 * 기여1. nCk = n-1Ck-1 + n-1Ck
 * 기여2. nCk = nCn-k
  */

#include <iostream>
using namespace std;

int bin(int target_n, int target_k)
{
	if (target_k==0 || target_k==target_n)
		return 1;

	// nCk = nCn-k
	if (target_k > (target_n/2))
		target_k = target_n - target_k;

	int b[2][500];
	int *pre, *cur, *temp;

	pre =  &b[0][0];
	cur =  &b[1][0];

	int n,k;
	for (n=0; ; n++) {
		for (k=0; k<=n/2; k++) {
			if (k == 0 || k == n) {
				cur[k] = 1;
			} else {
				if (k > (n-1)/2)
					cur[k] = pre[k-1] + pre[n-k];
				else
					cur[k] = pre[k-1] + pre[k];
			}

			if (n==target_n && k==target_k)
				return cur[k];
		}
		temp = pre;
		pre = cur;
		cur = temp;
	}
}

int main()
{
	int n,k;
	cout << "enter n,k used in nCk:";
	cin >> n >> k;

	cout << "nCk is " << bin(n, k);

}
