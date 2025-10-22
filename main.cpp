// main.cpp
// MetroQuest Delhi
// Finds shortest path between two metro stations using Dijkstra's algorithm
// Compile: g++ -std=c++17 -O2 main.cpp -o metro
// Run: ./metro < input.txt

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (1LL<<60);

// Dijkstra (1-based)
pair<vector<ll>, vector<int>> dijkstra(int n, int src, const vector<vector<pair<int,int>>> &adj) {
    vector<ll> dist(n+1, INF);
    vector<int> parent(n+1, -1);
    dist[src] = 0;
    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pq;
    pq.push({0, src});
    while(!pq.empty()) {
        auto [d,u] = pq.top(); pq.pop();
        if (d != dist[u]) continue;
        for (auto &e : adj[u]) {
            int v = e.first;
            int w = e.second;
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                parent[v] = u;
                pq.push({dist[v], v});
            }
        }
    }
    return {dist, parent};
}

vector<int> reconstruct(int s, int t, const vector<int> &parent) {
    vector<int> path;
    for (int v = t; v != -1; v = parent[v]) path.push_back(v);
    reverse(path.begin(), path.end());
    if (path.empty() || path.front() != s) return {}; // no path
    return path;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    if (!(cin >> n >> m)) {
        cerr << "Invalid input. See README for input format.\n";
        return 0;
    }
    vector<vector<pair<int,int>>> adj(n+1);
    for (int i = 0; i < m; ++i) {
        int u, v, w; 
        cin >> u >> v >> w;
        // undirected graph (tracks both ways). Remove second push for directed edges.
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    int s, t;
    cin >> s >> t;
    auto [dist, parent] = dijkstra(n, s, adj);
    if (dist[t] >= INF) {
        cout << "No path from " << s << " to " << t << "\n";
        return 0;
    }
    vector<int> path = reconstruct(s, t, parent);
    cout << "Shortest distance from " << s << " to " << t << " is: " << dist[t] << "\n";
    cout << "Path length (nodes): " << path.size() << "\n";
    cout << "Path: ";
    for (size_t i = 0; i < path.size(); ++i) {
        if (i) cout << " -> ";
        cout << path[i];
    }
    cout << "\n";
    return 0;
}
