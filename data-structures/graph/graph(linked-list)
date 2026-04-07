#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

// ==========================================
// 1. CẤU TRÚC NODE CỦA LINKED LIST
// ==========================================
struct Node {
    int vertex;     // Tên đỉnh kề
    int weight;     // Trọng số (dành cho Dijkstra)
    Node* next;     // Con trỏ trỏ đến Node tiếp theo
};

// ==========================================
// 2. CLASS GRAPH (ĐỒ THỊ)
// ==========================================
class Graph {
private:
    int V;          // Số lượng đỉnh
    Node** adj;     // Mảng chứa các con trỏ đầu (Head) của Linked List

    // Hàm đệ quy phụ trợ cho DFS
    void DFSHelper(int u, vector<bool>& visited) {
        visited[u] = true;
        cout << u << " ";

        // Duyệt các đỉnh kề bằng con trỏ
        Node* temp = adj[u];
        while (temp != nullptr) {
            int v = temp->vertex;
            if (!visited[v]) {
                DFSHelper(v, visited);
            }
            temp = temp->next;
        }
    }

public:
    // Khởi tạo đồ thị
    Graph(int vertices) {
        V = vertices;
        adj = new Node*[V];
        for (int i = 0; i < V; i++) {
            adj[i] = nullptr; // Ban đầu tất cả danh sách đều rỗng
        }
    }

    // Thêm cạnh nối (Kỹ thuật chèn vào đầu Linked List)
    // isUndirected = true nếu là đồ thị vô hướng
    void addEdge(int u, int v, int weight = 1, bool isUndirected = true) {
        // Thêm chiều từ u -> v
        Node* newNode1 = new Node{v, weight, adj[u]};
        adj[u] = newNode1;

        // Thêm chiều từ v -> u (Nếu là vô hướng)
        if (isUndirected) {
            Node* newNode2 = new Node{u, weight, adj[v]};
            adj[v] = newNode2;
        }
    }

    // ==========================================
    // THUẬT TOÁN 1: BFS (Vết dầu loang - Dùng Queue)
    // ==========================================
    void BFS(int start) {
        vector<bool> visited(V, false);
        queue<int> q;

        q.push(start);
        visited[start] = true;

        cout << "--- BFS (Tu dinh " << start << ") ---\nThứ tự: ";
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            cout << u << " ";

            Node* temp = adj[u];
            while (temp != nullptr) {
                int v = temp->vertex;
                if (!visited[v]) {
                    visited[v] = true; // Đánh dấu ngay khi đưa vào Queue
                    q.push(v);
                }
                temp = temp->next;
            }
        }
        cout << "\n\n";
    }

    // ==========================================
    // THUẬT TOÁN 2: DFS (Đi sâu - Dùng Đệ quy)
    // ==========================================
    void DFS(int start) {
        vector<bool> visited(V, false);
        cout << "--- DFS (Tu dinh " << start << ") ---\nThứ tự: ";
        DFSHelper(start, visited);
        cout << "\n\n";
    }

    // ==========================================
    // THUẬT TOÁN 3: DIJKSTRA (Đường đi ngắn nhất)
    // ==========================================
    void Dijkstra(int start) {
        vector<int> dist(V, INT_MAX);
        dist[start] = 0;

        // Min-Heap lưu trữ {khoảng_cách, đỉnh}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, start});

        while (!pq.empty()) {
            int d = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            if (d > dist[u]) continue; // Bỏ qua nếu dữ liệu đã cũ

            // Xét các hàng xóm
            Node* temp = adj[u];
            while (temp != nullptr) {
                int v = temp->vertex;
                int weight = temp->weight;

                // Relaxation (Cập nhật đường ngắn hơn)
                if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    pq.push({dist[v], v});
                }
                temp = temp->next;
            }
        }

        cout << "--- DIJKSTRA (Khoảng cách từ đỉnh " << start << ") ---\n";
        for (int i = 0; i < V; i++) {
            cout << " -> Den " << i << ": ";
            if (dist[i] == INT_MAX) cout << "Khong the toi!\n";
            else cout << dist[i] << "\n";
        }
    }

    // ==========================================
    // DỌN DẸP BỘ NHỚ (Destructor)
    // ==========================================
    ~Graph() {
        for (int i = 0; i < V; i++) {
            Node* temp = adj[i];
            while (temp != nullptr) {
                Node* toDelete = temp;
                temp = temp->next;
                delete toDelete;
            }
        }
        delete[] adj;
    }
};

// ==========================================
// HÀM MAIN ĐỂ CHẠY THỬ
// ==========================================
int main() {
    int V = 5; // Đồ thị có 5 đỉnh (từ 0 đến 4)
    Graph g(V);

    // Thêm các cạnh (u, v, weight, isUndirected)
    g.addEdge(0, 1, 4, true);
    g.addEdge(0, 2, 1, true);
    g.addEdge(2, 1, 2, true);
    g.addEdge(1, 3, 5, true);
    g.addEdge(2, 3, 8, true);
    g.addEdge(3, 4, 3, true);

    /* Hình dung đồ thị mẫu:
           (4)
        0 ------- 1
        |       / |
     (1)|    (2)  |(5)
        |  /      |
        2 ------- 3 --- (3) --- 4
           (8)
    */

    // Chạy các thuật toán
    g.BFS(0);
    g.DFS(0);
    g.Dijkstra(0);

    return 0;
}