#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

const int inf = 1e9;


struct Graph{
    int V;
    vector<vector<int>> adj;

    void init(int vertices){
        V = vertices;
        adj.resize(vertices);
    }

    void addEdge(int u, int v,int w){
        adj[u].push_back(v);
    }
};

void dfs_recursive(Graph& graph, int u, vector<bool> &visited){
    visited[u] = true;
    cout << u << " ";
    for ( int i : graph.adj[u]){
        if (!visited[i]){
            dfs_recursive(graph,i,visited);
        }
    }
}

void dfs(Graph& graph, int start){
    vector<bool> visited (graph.V + 1,0);
    cout << "Traversal: ";
    dfs_recursive(graph,start,visited);
    cout << "\n";
}

void bfs(Graph &graph, int start, int end){
    int inf = 1e9;
    vector<bool> visited(graph.V+1,0);
    vector<int> parent(graph.V+1,0);
    queue<int> q;
    visited[start] = true;
    q.push(start);

    while (!q.empty()){
        int top = q.front();
        q.pop();
        
        if (top == end){
            break;
        }

        for (int i : graph.adj[top]){
            if (visited[i] == 0){
                visited[i] = 1;
                q.push(i);
                parent[i] = top;
            }
        }   
    }
    vector<int> path;
    int curr = end;
    while (curr != start){
        path.push_back(curr);
        curr = parent[curr];
    }
    path.push_back(start);
    for (int i = path.size()-1; i > 0; --i){
        cout << path[i] << " ";
    }
    cout << "\n";
}

// int dijsktra(Graph &graph,int start, int end){
//     vector <int> dist(graph.V+1,inf);
//     vector <bool> visited (graph.V,false);
//     vector <bool> parent(graph.V + 1,-1);

//     dist[start] = 0;

//     for (int i = 1; i <= graph.V; ++i){
//         int u = -1;

//         for (int j = 1; j<= graph.V; ++j){
//             if (!visited[u] && (u == -1 || dist[j] < dist[u])){
//                 u = j;
//             }
//         }

//         if ( u == -1 || dist[u] == inf) break;
//         visited[u] = true;

//         if (u == end) break;

//         for (int v = 1; v <= graph.V; ++v){
//             if (graph.adj[u][v]!= 0 && graph.adj[u][v]!= inf){
//                 if ( dist[v] > dist[u] + graph.adj[u][v] ){
//                     dist[v] = dist[u] + graph.adj[u][v];
//                     parent[v] = u;
//                 }
//             }
//         }
//     }
//     return dist[end];
// }


int dijsktra(Graph &graph, int start, int end){
    vector<int>dist(graph.V+1,inf);
    vector<int>parent(graph.V+1,-1);
    vector<bool>visited(graph.V+1,false);
    dist[start] = 0;
    for (int i = 1; i <= graph.V; ++i ){
        int u = -1;

        for (int j = 1; j <= graph.V; ++j){
            if ( !visited[j] && ( u == -1 || dist[j] < dist[u] ) ){
                u = j;
            }
        }

        if (u == -1) break;
        visited[u] = 1;

        if (u == end) break;

        for (int v = 1; v <= graph.V; ++v){
            if(graph.adj[u][v] != 0 && graph.adj[u][v]!= inf){
                if ()
            }
        }

    }
}

int main() {
ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    return 0;
}