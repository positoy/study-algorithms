/**
 *  �ټ����	(https://www.acmicpc.net/problem/2605)
 *  Author	��â�� (positoy@gmail.com)
 */

#include <iostream>
#include <list>
using namespace std;

//void usingArray()
//{
//	int line[101] = {};
//	int n, input;
//	
//	// ��ü �л� �� �Է�
//	cin >> n;
//
//	// ù��° �л�
//	cin >> input;
//	line[1] = 1;
//	int currentSize = 1;
//	
//	// ������ �л�
//	for (int i = 2; i <= n; i++) {
//
//		cin >> input;
//		
//		for (int j = currentSize; j > currentSize-input; j--) {
//			line[j+1] = line[j];
//		}
//
//		line[currentSize-input+1] = i;
//		currentSize++;
//	}
//	
//	// ���
//	for (int i = 1; i <= n; i++) {
//		cout << line[i] << ' ';
//	}
//}

 //list�� ����ؼ� iterator�� �����ڸ� ����ϸ� �����ϴµ� ���� �ð��� �ɸ��°�?
 //line.rbegin() + input;
 //rbegin().base() ����

void usingList()
{
	list<int> line;

	int n, input;

	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> input;
		list<int>::reverse_iterator rit = line.rbegin();

		line.insert(rit.base(), i);
	}

	for(list<int>::iterator it = line.begin(); it != line.end(); it++) {
		cout << *it << ' ';
	}
}

int main()
{
	usingList();
	getchar();
}
