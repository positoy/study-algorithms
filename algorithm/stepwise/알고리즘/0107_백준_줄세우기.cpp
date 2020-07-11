/**
 *  줄세우기	(https://www.acmicpc.net/problem/2605)
 *  Author	안창규 (positoy@gmail.com)
 */

#include <iostream>
#include <list>
using namespace std;

//void usingArray()
//{
//	int line[101] = {};
//	int n, input;
//	
//	// 전체 학생 수 입력
//	cin >> n;
//
//	// 첫번째 학생
//	cin >> input;
//	line[1] = 1;
//	int currentSize = 1;
//	
//	// 나머지 학생
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
//	// 출력
//	for (int i = 1; i <= n; i++) {
//		cout << line[i] << ' ';
//	}
//}

 //list를 사용해서 iterator에 연산자를 사용하면 접근하는데 얼마의 시간이 걸리는가?
 //line.rbegin() + input;
 //rbegin().base() 오류

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
