#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

struct Node {
    int vertex;
    int weight;
    Node* next;
};

class Graph {
private:
    int V;
    Node** adj;

    void clear() {
        for (int i = 0; i < V; i++) {
            Node* current = adj[i];
            while (current) {
                Node* next = current->next;
                delete current;
                current = next;
            }
        }
        delete[] adj;
    }

public:
    Graph(int vertices) : V(vertices) {
        adj = new Node*[V];
        for (int i = 0; i < V; i++) adj[i] = nullptr;
    }

    ~Graph() { clear(); }

    void addEdge(int u, int v, int w = 1, bool undirected = true) {
        adj[u] = new Node{v, w, adj[u]};
        if (undirected) adj[v] = new Node{u, w, adj[v]};
    }

    void DFS(int u, vector<bool>& visited) {
        visited[u] = true;
        cout << u << " ";
        for (Node* temp = adj[u]; temp; temp = temp->next) {
            if (!visited[temp->vertex]) DFS(temp->vertex, visited);
        }
    }
    // Các hàm BFS và Dijkstra tương tự như trên nhưng thay vòng lặp vector bằng duyệt Node*
};