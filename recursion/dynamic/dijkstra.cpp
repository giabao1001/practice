#include <iostream>
#include <vector>

using namespace std;

const int INF = 1e9;
int n, m;
int graph[1005][1005]; // Ma trận kề lưu trọng số cạnh
int d[1005];           // f[i] trong DP - khoảng cách ngắn nhất đến i
bool visited[1005];    // Đánh dấu đỉnh đã tối ưu xong
int trace[1005];       // Để in ra con đường đi

void dijkstra(int start) {
    // 1. Khởi tạo giống hệt bài đổi tiền
    for (int i = 1; i <= n; i++) {
        d[i] = INF;
        visited[i] = false;
        trace[i] = -1;
    }
    d[start] = 0;

    for (int i = 1; i <= n; i++) {
        // 2. Tìm đỉnh u chưa thăm có d[u] nhỏ nhất (Gợi ý trong ảnh)
        int u = -1;
        for (int j = 1; j <= n; j++) {
            if (!visited[j] && (u == -1 || d[j] < d[u]))
                u = j;
        }

        if (d[u] == INF) break; // Không còn đường đi nào nữa
        visited[u] = true;

        // 3. "Đẩy" giá trị đi (Push DP) để cập nhật các đỉnh kề v
        for (int v = 1; v <= n; v++) {
            if (graph[u][v] != INF) { // Nếu có cạnh nối u-v
                if (d[u] + graph[u][v] < d[v]) {
                    d[v] = d[u] + graph[u][v];
                    trace[v] = u; // Lưu lại: "Để đến v, tôi đi qua u"
                }
            }
        }
    }
}

int main() {
    // Giả sử n=5, m=6... (Nhập dữ liệu đồ thị ở đây)
    // ... code nhập graph ...

    dijkstra(1);

    // Truy vết đường đi từ 1 đến N
    if (d[n] == INF) cout << "Khong ton tai duong di";
    else {
        cout << "Do dai ngan nhat: " << d[n] << endl;
        vector<int> path;
        for (int v = n; v != -1; v = trace[v]) path.push_back(v);
        for (int i = path.size() - 1; i >= 0; i--) cout << path[i] << (i == 0 ? "" : " -> ");
    }
    return 0;
}