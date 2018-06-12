#include <iostream>
int N, E, graph[1000],indegree[1000],outdegree[1000];
struct edge_ {
    int b, cost, next;
} edge[1000];

int main()
{
    std::cin >> N >> E;
    for (int a,b,c,e=1; e<=E; e++) {
        std::cin >> a >> b >> c;
        edge[e].next = graph[a];
        edge[e].b = b;
        edge[e].cost = c;
        graph[a] = e;
        indegree[b]++;
        outdegree[a]++;
    }

    // test
    for (int i=1; i<=N; i++) {
        std::cout << i << " indegree:" << indegree[i] << ", outdegree:" << outdegree[i] << std::endl;
        for (int ptr=graph[i]; ptr; ptr=edge[ptr].next) {
            std::cout << i << "->" << edge[ptr].b << " : " << edge[ptr].cost << std::endl;
        }
    }
}