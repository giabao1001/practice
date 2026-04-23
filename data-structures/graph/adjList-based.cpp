#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int INF = 1e9;

struct Edge {
    int to;
    int weight;
};

struct Graph {
    int V;
    vector<vector<Edge>> adj;

    void init(int vertices) {
        V = vertices;
        adj.assign(V + 1, vector<Edge>());
    }

    void addEdge(int u, int v, int w = 1) {
        adj[u].push_back({v, w});
    }
};

// BFS tìm đường đi ngắn nhất trên đồ thị không trọng số
void bfsPath(Graph &graph, int start, int end) {
    vector<int> parent(graph.V + 1, -1);
    vector<bool> visited(graph.V + 1, false);
    queue<int> q;

    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        if (u == end) break;

        for (auto &edge : graph.adj[u]) {
            if (!visited[edge.to]) {
                visited[edge.to] = true;
                parent[edge.to] = u;
                q.push(edge.to);
            }
        }
    }

    if (parent[end] == -1 && start != end) {
        cout << "No path found\n";
        return;
    }

    vector<int> path;
    for (int v = end; v != -1; v = parent[v]) path.push_back(v);
    reverse(path.begin(), path.end());

    cout << "BFS Path: ";
    for (int node : path) cout << node << " ";
    cout << "\n";
}

// Dijkstra dùng Priority Queue (O(E log V))
void dijkstra(Graph &graph, int start) {
    vector<int> dist(graph.V + 1, INF);
    dist[start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (d > dist[u]) continue;

        for (auto &edge : graph.adj[u]) {
            if (dist[u] + edge.weight < dist[edge.to]) {
                dist[edge.to] = dist[u] + edge.weight;
                pq.push({dist[edge.to], edge.to});
            }
        }
    }

    cout << "Dijkstra Distances:\n";
    for (int i = 1; i <= graph.V; ++i) {
        cout << "Node " << i << ": " << (dist[i] == INF ? -1 : dist[i]) << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    // Ví dụ sử dụng
    Graph g; g.init(5);
    g.addEdge(1, 2, 4); g.addEdge(1, 3, 1);
    g.addEdge(3, 2, 2); g.addEdge(2, 4, 5);
    
    bfsPath(g, 1, 4);
    dijkstra(g, 1);
    return 0;
}