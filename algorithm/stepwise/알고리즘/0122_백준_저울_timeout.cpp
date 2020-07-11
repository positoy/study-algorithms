/************************ 백준 - 저울 **
 https://www.acmicpc.net/problem/10159
 아래 풀이는 timelimit.
 ***************************************/
#include <iostream>
#include <vector>
using namespace std;

typedef struct _NODE {
	vector<int> bigger,smaller;
} NODE;

NODE node[101];

inline int countSmall(int start, int count)
{
	int size = node[start].smaller.size();
	for (int i=0; i<size; i++) {
		count = countSmall(node[start].smaller[i], ++count);
	}

	return count;
}

inline int countBig(int start, int count)
{
	int size = node[start].bigger.size();
	for (int i=0; i<size; i++) {
		count = countBig(node[start].bigger[i], ++count);
	}

	return count;
}

int main()
{
	int N,M,A,B;
	cin >> N >> M;
	// 여기서 전부다 처리하면. o(n^2)
	for (int i=0; i<M; i++) {
		cin >> A >> B;
		node[A].smaller.push_back(B);
		node[B].bigger.push_back(A);
	}

	// 여기서 전부다 처리하면. o(2^n)
	for (int i=1; i<=N; i++) {
		int small, big;
		// 큰 것 세기
		small = countSmall(i, 0);
		// 작은 것 세기
		big = countBig(i, 0);
		// 출력
		cout << N-1-small-big << endl;
	}
}
#include <iostream>
#include <vector>
using namespace std;

typedef struct _NODE {
	vector<int> bigger,smaller;
} NODE;

NODE node[101];

inline int countSmall(int start, int count)
{
	int size = node[start].smaller.size();
	for (int i=0; i<size; i++) {
		count = countSmall(node[start].smaller[i], ++count);
	}

	return count;
}

inline int countBig(int start, int count)
{
	int size = node[start].bigger.size();
	for (int i=0; i<size; i++) {
		count = countBig(node[start].bigger[i], ++count);
	}

	return count;
}

int main()
{
	int N,M,A,B;
	cin >> N >> M;
	// 여기서 전부다 처리하면. o(n^2)
	for (int i=0; i<M; i++) {
		cin >> A >> B;
		node[A].smaller.push_back(B);
		node[B].bigger.push_back(A);
	}

	// 여기서 전부다 처리하면. o(2^n)
	for (int i=1; i<=N; i++) {
		int small, big;
		// 큰 것 세기
		small = countSmall(i, 0);
		// 작은 것 세기
		big = countBig(i, 0);
		// 출력
		cout << N-1-small-big << endl;
	}
}
