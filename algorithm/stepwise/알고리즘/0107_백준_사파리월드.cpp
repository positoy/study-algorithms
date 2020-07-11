/**
 *  사파리월드	(https://www.acmicpc.net/problem/2420)
 *  Author	안창규 (positoy@gmail.com)
 */

// 4바이트 정수 int는 +-20억 범위
// int 최대값 0x7fffffff
// int 최소값 -(0x7fffffff + 1)
// 0을 포함한 양수 갯수 = 음수 갯수

#include <iostream>
using namespace std;

int main()
{
	long long int a, b, result;

	// 입력
	cin >> a >> b;
	
	// 계산
	if (a > b) {
		result = a - b;
	} else {
		result = b - a;
	}

	// 출력
	cout << result;
}
