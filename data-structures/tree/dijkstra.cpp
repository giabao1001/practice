#include <iostream>
#include <vector>
using namespace std;

const int inf = 999;
int V;
vector<vector<int>> cost (V,vector<int>(V,inf));
vector <bool> visited (V);
vector <int> dist (V);

int getNearest(){
    int minVal = inf;
    int minnode = 0;
    for (int i = 0; i < V; ++i){
        if ( !visited[i] && dist[i] < minVal){
            minVal = dist[i];
            minnode = i;
        }
    }
    return minnode;
}

int dijkstra(){
    for (int i = 0; i < V; ++i){
        int nearest = getNearest();
        visited[nearest] = 1;
    }
}

int main() {
ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> V;
    int start;
    cin >> start;
    return 0;
}