/**
 *  ���ĸ�����	(https://www.acmicpc.net/problem/2420)
 *  Author	��â�� (positoy@gmail.com)
 */

// 4����Ʈ ���� int�� +-20�� ����
// int �ִ밪 0x7fffffff
// int �ּҰ� -(0x7fffffff + 1)
// 0�� ������ ��� ���� = ���� ����

#include <iostream>
using namespace std;

int main()
{
	long long int a, b, result;

	// �Է�
	cin >> a >> b;
	
	// ���
	if (a > b) {
		result = a - b;
	} else {
		result = b - a;
	}

	// ���
	cout << result;
}
