#include<bits/stdc++.h>
using namespace std;

int inf = 1e7 + 5;

struct edge
{
    int from;
    int to;
    int weight;
};

int main()
{
    int n, m; cin >> n >> m;

    vector<edge> edges(m);

    for(int i=0; i<m; i++)
    {
        int u, v, w; cin >> u >> v >> w;

        edges[i].from = u;
        edges[i].to = v;
        edges[i].weight = w;
    }

    vector<int> distance(n+2, inf);

    int source; cin >> source;
    distance[source] = 0;

    for(int i=1; i<n; i++){
        for(auto eg : edges)
        {
            distance[eg.to] = min(distance[eg.to], eg.weight + distance[eg.from]);
        }
    }

    for(int i=1; i<=n; i++)
        cout << distance[i] << " ";
    cout << endl;

    return 0;
}
