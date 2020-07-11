/**
 * 9계단 - 유클리드호제법 - euclid
 *
 * - a,b의 범위 때문에 long long int 를 사용해야 함.
 * - 하지만 주어진 테스트케이스는 lcm의 연산 순서를 수정하는 것만으로도 통과 가능.
 */
#include <stdio.h>

long long gcd(long long a, long long b)
{
	if (b == 0)
		return a;
	else
		return gcd(b, a%b);
}

long long lcm(long long a, long long b)
{
	return a / gcd(a,b) * b;
}

int main()
{
	long long a,b;
	scanf("%lld %lld", &a, &b);

	printf("%lld %lld", gcd(a,b), lcm(a,b));
}
