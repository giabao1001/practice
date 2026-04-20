#include <iostream>
#include <queue> 
#include <vector>
using namespace std;
int m ;
const int inf = 1e18;
int V;
int previous[1000005];
vector < pair<int,int> > adj[1000005];
int dijkstra(int s, int e){
    vector<long long> dist(V+1,inf);
    dist[s] = 0;
    priority_queue< pair<long long,int>, vector<pair<long long,int>> , greater<pair<long long,int>>> pq;
    pq.push({0,s});
    while (!pq.empty()){
        pair<int,int> Top = pq.top();
        pq.pop();
        int u = Top.second;
        int length = Top.first;
        if ( length > dist[u] ){
            continue;
        }
        else {
            for ( auto it : adj[u] ){
                int v = it.first;
                int w = it.second;
                if (dist[v] > dist[u] + w){
                    dist[v] = dist[u] + w; 
                    pq.push({dist[v],v});
                    previous [v] = u;
                } 
            }

        }
    }
    if (dist[e] == inf){ return; }
    vector<int> path;
    int curr = e;
    while (1){
        path.push_back(curr);
        if (curr == s) break;
        curr = previous[curr];
    }
    for (int i = path.size() - 1; i >= 0; --i){
        cout << path[i] << " " << "\n";
    }
    return dist[e];
}

int main() {
ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    return 0;
}