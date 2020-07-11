/************************ 백준 - 저울 **
 https://www.acmicpc.net/problem/10159
 아래 풀이는 timelimit.
 ***************************************/
#include <iostream>
#include <vector>
#define DEBUG
using namespace std;

typedef struct _NODE {
	vector<int> bigger,smaller;
} NODE;

NODE node[101];

inline void travelBigger(int target, int value)
{
	int size = node[target].bigger.size();
	for (int i=0; i<size; i++) {
		int bigger = node[target].bigger[i];
		node[bigger].smaller.push_back(value);
		travelBigger(bigger, value);
	}
}

inline void travelSmaller(int target, int value)
{
	int size = node[target].smaller.size();
	for (int i=0; i<size; i++) {
		int smaller = node[target].smaller[i];
		node[smaller].bigger.push_back(value);
		travelBigger(smaller, value);
	}
}

int main()
{
	int N,M,A,B;
	cin >> N >> M;
	// 여기서 전부다 처리하면. o(n^2)
	for (int i=0; i<M; i++) {
		cin >> A >> B;
		// A>B라는 뜻.

		// A의 smaller에 B를 삽입하고,
		// A의 bigger를 재귀적으로 탐색하며 각 노드의 smaller에 B를 삽입한다.
		node[A].smaller.push_back(B);
		travelBigger(A, B);

		// B의 bigger에 A를 삽입하고,
		// B의 smaller를 재귀적으로 탐색하며 각 노드의 bigger에 A를 삽입한다.
		node[B].bigger.push_back(A);
		travelSmaller(B, A);

#ifdef DEBUG
		for(int j=1; j<=N; j++) {
			cout << j << " smaller: " << node[j].smaller.size() << endl;
			cout << j << " bigger: " << node[j].bigger.size() << endl;
		}
#endif
	}

	// 여기서 전부다 처리하면. o(2^n)
	for (int i=1; i<=N; i++) {
		cout << N-1-node[i].bigger.size()-node[i].smaller.size() << endl;
	}
}
