#include <iostream>
#include <vector>
#include <stack>
using namespace std;

bool contaminated[101];
vector<int> graph[101];
int n,p,a,b;
stack<int> st;

int main()
{
	int viruscount = 0;

	// input
	cin >> n >> p;
	for (int i=0; i<p; i++) {
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	// push computer 1
	st.push(1);
	contaminated[1] = true;
	viruscount = 1;

	int origin, size, target;

	// warm virus propagation
	while (!st.empty()) {
		// set origin
		origin = st.top();
		st.pop();
		size = graph[origin].size();

		// search surround computers
		for (int i=0; i<size; i++) {
			target = graph[origin][i];
			if (contaminated[target] == false) {
				st.push(target);
				contaminated[target] = true;
				viruscount++;
			}
		}
	}


	cout << viruscount -1 << endl;

}
