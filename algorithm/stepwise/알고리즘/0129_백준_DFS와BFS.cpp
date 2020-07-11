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

	// �Է�
	cin >> V >> E >> S;

	int a,b;
	for (int e=0; e<E; e++)
	{
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	// DFS ���
	int pop;
	bool visited_dfs[1001] = {};

	// ù��° ��� �Է�
	s.push(S);
	while (s.empty() == false)
	{
		// ���� �湮�� Ȯ��
		pop = s.top(); s.pop();
		if (visited_dfs[pop] == false)
			cout << pop << ' ';
	
		visited_dfs[S] = true;

		// ���� �湮������ �� �� �ִ� ��� �湮�� Ȯ��
		for (int i=0; i<graph[pop].size(); i++)
		{
			v.push_back(graph[pop][i]);
		}

		// ������������ ���� ; ���ÿ� ������ 4 3 2 ó�� ���Ƿ� 2���� �湮�ϰ� ��
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

		// ����
		v.clear();
	}



	// BFS ���






}