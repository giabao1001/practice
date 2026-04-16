#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 1e9; // Giá trị đại diện cho vô cực (không có cạnh nối)
int n, m;            // n: số đỉnh, m: số cạnh

// Ma trận kề: adj[u][v] lưu trọng số cạnh nối từ u đến v. 
// Nếu không có cạnh, adj[u][v] = INF.
vector<vector<int>> adj;
vector<bool> visited;

// 1. Duyệt theo chiều rộng (BFS)
void BFS(int start) {
    queue<int> q;
    q.push(start);
    visited[start] = true;
    
    cout << "Thứ tự duyệt BFS: ";
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        cout << u << " ";
        
        // Duyệt qua tất cả các đỉnh để tìm đỉnh kề
        for (int v = 1; v <= n; v++) {
            // Nếu có cạnh nối và đỉnh v chưa được thăm
            if (adj[u][v] != INF && !visited[v]) {
                visited[v] = true;
                q.push(v);
            }   
        }
    }
    cout << "\n";
}

// 2. Duyệt theo chiều sâu (DFS)
void DFS(int u) {
    visited[u] = true;
    cout << u << " ";
    
    for (int v = 1; v <= n; v++) {
        if (adj[u][v] != INF && !visited[v]) {
            DFS(v);
        }
    }
}

// 3. Thuật toán Dijkstra bản O(V^2) - Phù hợp nhất cho ma trận kề
void Dijkstra(int start) {
    vector<int> dist(n + 1, INF);
    vector<int> parent(n + 1, -1);
    vector<bool> processed(n + 1, false); // Đánh dấu đỉnh đã chốt khoảng cách ngắn nhất
    
    dist[start] = 0;
    
    for (int i = 1; i <= n; i++) {
        // Bước 1: Tìm đỉnh u chưa được xử lý có khoảng cách nhỏ nhất hiện tại
        int u = -1;
        for (int j = 1; j <= n; j++) {
            if (!processed[j] && (u == -1 || dist[j] < dist[u])) {
                u = j;
            }
        }
        
        // Nếu khoảng cách nhỏ nhất tìm được là INF, các đỉnh còn lại đều không thể tới được
        if (dist[u] == INF) break;
        
        // Chốt đỉnh u
        processed[u] = true;
        
        // Bước 2: Nới lỏng (Relaxation) các cạnh kề của u
        for (int v = 1; v <= n; v++) {
            // Nếu có cạnh nối u-v và đi qua u giúp tối ưu hơn
            if (adj[u][v] != INF && dist[v] > dist[u] + adj[u][v]) {
                dist[v] = dist[u] + adj[u][v];
                parent[v] = u;
            }
        }
    }
    
    // In kết quả
    cout << "--- Dijkstra từ đỉnh " << start << " ---\n";
    for (int i = 1; i <= n; i++) {
        if (dist[i] == INF) {
            cout << "Đỉnh " << i << ": INF (Không có đường đi)\n";
        } else {
            cout << "Đỉnh " << i << ": Chi phí = " << dist[i] << "\n";
        }
    }
}

int main() {
    // Khử đồng bộ I/O giúp tăng tốc độ đọc ghi (Rất quan trọng trong các bài test giới hạn thời gian)
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Giả sử nhận đầu vào từ file hoặc bàn phím
    /*
    cin >> n >> m;
    
    // Khởi tạo ma trận n+1 x n+1 với giá trị mặc định là INF (dùng chỉ số 1-based)
    adj.assign(n + 1, vector<int>(n + 1, INF));
    visited.assign(n + 1, false);
    
    // Khoảng cách từ một đỉnh đến chính nó bằng 0
    for(int i = 1; i <= n; i++) adj[i][i] = 0;
    
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        
        // Nếu có đa cạnh (multiple edges) giữa u và v, lấy cạnh có trọng số nhỏ nhất
        adj[u][v] = min(adj[u][v], w);
        
        // Bỏ comment dòng dưới nếu là đồ thị vô hướng
        // adj[v][u] = min(adj[v][u], w); 
    }
    
    // reset visited trước mỗi lần gọi thuật toán
    // BFS(1);
    
    // fill(visited.begin(), visited.end(), false);
    // cout << "Thứ tự duyệt DFS: ";
    // DFS(1); cout << "\n";
    
    // Dijkstra(1);
    */

    return 0;
}