#include <iostream>
#include <vector>
#include <queue>

using namespace std;
const int INF = 1e9;

vector<int> dijkstra(int start, vector<vector<pair<int, int>>> &g)
{
    int n = (int)g.size() - 1;
    vector<int> dist(n + 1, INF);
    priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;

    dist[start] = 0;
    pq.push({ 0, start });

    while ( !pq.empty() )
    {
        auto [d, u] = pq.top();
        pq.pop();
        if ( d != dist[u] ) continue;

        for ( auto [v, w] : g[u] )
        {
            if ( dist[v] > d + w )
            {
                dist[v] = d + w;
                pq.push({ dist[v], v });
            }
        }
    }
    return dist;
}

int main()
{
    
    int n, m, x;
    cin >> n >> m >> x;

    vector<vector<pair<int, int>>> g(n + 1), rg(n + 1);

    for ( int i = 0; i < m; i++ )
    {
        int a, b, t;
        cin >> a >> b >> t;
        g[a].push_back({ b, t });
        rg[b].push_back({ a, t }); 
    }

    vector<int> distFromX = dijkstra(x, g);   
    vector<int> distToX = dijkstra(x, rg);  

    int ans = 0;
    for ( int i = 1; i <= n; i++ )
    {
        ans = max(ans, distToX[i] + distFromX[i]);
    }

    cout << ans << "\n";
    return 0;
}
