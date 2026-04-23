#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

void solve() {
    ifstream inFile("graph.txt");
    if (!inFile) {
        cerr << "Error opening file!\n";
        return;
    }

    int u, v;
    vector<pair<int, int>> edges;
    int maxNode = 0;

    // Bước 1: Đọc tất cả các cạnh và tìm node lớn nhất
    while (inFile >> u >> v) {
        edges.push_back({u, v});
        maxNode = max({maxNode, u, v});
    }
    inFile.close();

    // Bước 2: Khởi tạo danh sách kề
    vector<vector<int>> adj(maxNode + 1);
    for (auto &edge : edges) {
        adj[edge.first].push_back(edge.second);
        // adj[edge.second].push_back(edge.first); // Nếu là vô hướng
    }

    cout << "Graph loaded with " << maxNode + 1 << " vertices.\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}