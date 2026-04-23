#include <iostream>
#include <queue>
#include <iostream>
using namespace std;
const int maxn = 1000005;
int n; 
int m ;
const long long inf = 1e18;
vector<pair<int,int>> adj[maxn];

long long dijkstra (int start, int end){
    vector<int> previous(n+1,inf);
    vector<long long> dist (n+1);
    priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;
    dist[start] = 0;
    pq.push({0,start});
    while (!pq.empty()){
        pair<long long, int> Top = pq.top();
        pq.pop();
        int length = Top.first;
        int u = Top.second;
        if ( length > dist[u] ){
            continue;
        }
        else {
            for ( auto it: adj[u] ){
                int v = it.first;
                int w = it.second;
                if ( dist[v] > dist[u] + w ){
                    dist[v] = dist[u] + w;
                    pq.push({dist[v],v});
                    previous[v] = u;
                }
            }
        }
    }
    int curr = end;
    vector<int> path;
    while (true){
        path.push_back(curr);
        if (curr == start) break;
        curr = previous[curr];
    }   
    for (int i = path.size()-1 ; i >= 0; --i ){
        cout << path[i] << " ";
    }
    return dist[end];
}

int main() {
ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    return 0;
}