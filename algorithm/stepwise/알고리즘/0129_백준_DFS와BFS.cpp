#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

int main()
{
	int V,E,S;
	vector<int> graph[1001];
	stack<int> s;
	queue<int> q;
	vector<int> v;

	// 입력
	cin >> V >> E >> S;

	int a,b;
	for (int e=0; e<E; e++)
	{
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	// DFS 출력
	int pop;
	bool visited_dfs[1001] = {};

	// 첫번째 노드 입력
	s.push(S);
	while (s.empty() == false)
	{
		// 다음 방문지 확인
		pop = s.top(); s.pop();
		if (visited_dfs[pop] == false)
			cout << pop << ' ';
	
		visited_dfs[S] = true;

		// 다음 방문지에서 갈 수 있는 모든 방문지 확인
		for (int i=0; i<graph[pop].size(); i++)
		{
			v.push_back(graph[pop][i]);
		}

		// 내림차순으로 정렬 ; 스택에 넣으면 4 3 2 처럼 들어가므로 2부터 방문하게 됨
		sort(v.rbegin(), v.rend());
		for (int i=0; i<v.size(); i++)
		{
			int next = v[i];
			if (visited_dfs[next] == false)
			{
				if (visited_dfs[next] == false);
				s.push(next);
			}
		}

		// 비우기
		v.clear();
	}



	// BFS 출력






}