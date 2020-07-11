#include <iostream>

int T,N,K,G[20],indegree[20],outdegree[20],msg[40];
struct _edge {
    int b,next;
}E[35];

int queue[40] = {0}, top = -1;

void init() {
    top = -1;
    for (int i=1; i<=N; i++)
        indegree[i]=outdegree[i]=0;
}

int longestMsg()
{
    int msgLength = 0;
    top = -1;
    for (int i=1; i<=N; i++)
        if (indegree[i] == 0) queue[++top] = i;

    int adjIdx, idx = 0;
    while (top != -1) {
        idx = queue[top--];
        adjIdx = G[idx];
        while (adjIdx) {
            if(--indegree[E[adjIdx].b] == 0)
                queue[++top] = E[adjIdx].b;
            adjIdx = E[adjIdx].next;
        }
        msgLength++;
    }
    return msgLength;
}

int main()
{
    std::cin >> T;
    for (int i=1; i<=T; i++)
    {
        init();
        std::cin >> N >> K;
        for (int size,j=0; j<K; j++)
        {
            std::cin >> size;
            for (int k=0; k<size; k++)
            {
                std::cin >> msg[k];
                if (k != 0)
                {
                    E[k].b = msg[k];
                    E[k].next = G[msg[k-1]];
                    G[msg[k-1]] = k;
                    outdegree[msg[k-1]]++;
                    indegree[msg[k]]++;
                }
            }
        }
        std::cout << "#" << i << " " << std::flush;
        for (int x=1; x<=N; x++)
            std::cout << outdegree[x] << ' ';
        std::cout << std::flush;
        std::cout << longestMsg() << std::endl;
    }
}
