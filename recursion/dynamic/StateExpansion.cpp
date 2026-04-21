#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int inf = 1e9;

struct State{
    int dist;
    int u;
    int money;

};

struct compareState{
    bool operator()(State const &s1, State const &s2){
        return s1.dist > s2.dist;
    }
};

compareState compare;

int main() {
ios_base::sync_with_stdio(false); cin.tie(NULL);
    int N = 4; // Số đỉnh
    int M = 10; // Tiền ban đầu
    vector<int> cost = {0, 0, 5, 2, 3}; // Chi phí đi qua từng đỉnh

    // Đồ thị (danh sách kề)
    vector<vector<pair<int, int>>> adj(N + 1);
    adj[1].push_back({2, 10});
    adj[1].push_back({3, 2});
    adj[3].push_back({2, 3});
    adj[2].push_back({4, 5});
    adj[3].push_back({4, 20});


    vector<vector<int>> best(N+1,vector<int>(M+1,inf));

    priority_queue<State, vector<State> , compareState> pq;

    int startMoney = M - cost[1];
    if (startMoney >= 0){
        best[1][startMoney] = 0;
        pq.push({0,1,startMoney});
    }
    while (!pq.empty()){
        State top = pq.top();
        pq.pop();
        int d = top.dist;
        int u = top.u;
        int m = top.money;

        if (d > best[u][m]) continue;

        for (auto edge: adj[u] ){
            int vertice = edge.first;
            int distance = edge.second;
            int nextMoney = m - cost[vertice];
            int nextDist = distance + d;
            if (nextMoney >= 0 && nextDist < best[vertice][nextMoney]){
                best[vertice][nextMoney] = nextDist;
                pq.push({nextDist,vertice,nextMoney});
            }
        }
    }
    int ans = inf;
    int bestMoney = -1;
    for (int j = 0; j <= M; ++j) {
        if ( ans > best[4][j] ){
            ans = best[4][j];
            bestMoney = j;
        }
    }
    cout << "duong di ngan nhat: " << ans << "\n";
    cout << "so tien con lai: " << bestMoney << "\n";
    return 0;
}