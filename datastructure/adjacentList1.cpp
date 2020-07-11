#include <iostream>
int N, E, graph[1000][1000],cost[1000][1000],indegree[1000],outdegree[1000];

int main()
{
    std::cin >> N >> E;
    for (int a,b,c,e=0; e<E; e++) {
        std::cin >> a >> b >> c;
        graph[a][++graph[a][0]] = b;
        cost[a][b] = c;
        indegree[b]++;
        outdegree[a]++;
    }

    // test
    for (int i=1; i<=N; i++) {
        std::cout << i << " indegree:" << indegree[i] << ", outdegree:" << outdegree[i] << std::endl;
        for (int j=1; j<=graph[i][0]; j++) {
            std::cout << i << "->" << graph[i][j] << " : " << cost[i][graph[i][j]] << std::endl;
        }
    }
}