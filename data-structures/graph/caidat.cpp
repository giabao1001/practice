#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int inf = 1e9;

int n;
vector<vector<int>> adj;
vector <bool> visited;

void bfs(int start, int end){
    queue<int> q;
    vector<int> distance (n+1,-1);
    distance[start] = 0;
    vector<int> parent(n+1,-1);
    q.push(start);
    while (!q.empty()){
        int u = q.front();
        q.pop();
        if (u == end) break;
        for (int v = 1; v <= n ; ++ v){
            if (adj[u][v] == 1 && distance[v] == -1){
                q.push(v);
               distance[v] =distance[u] + 1;
               parent[v] = u;
            }
        }
    }

    if (distance[end] == -1){
        return;
    }

    vector<int> path;
    for (int i = end; i!= -1 ; i = parent[i]){
        path.push_back(i);
    }
    for (int i = path.size() - 1; i >= 0; --i){
        cout << path[i] << " ";
    }
}


int main() {
ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n;
    adj.assign(n+1,vector<int>(n+1,inf));
    visited.assign(n+1,false);
    for (int i = 1; i <= n; ++i){
        adj[i][i] = 0;
    }
    for (int i = 1; i <= n; ++i){
        int u,v;
        cin >> u >> v; 
        adj[u][v] = 1;
    }
    bfs(1,2);
    return 0;
}