#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Tự định nghĩa hàm tìm giá trị lớn nhất vì bị cấm <algorithm>
long long get_max(long long a, long long b) {
    return (a > b) ? a : b;
}

// Mảng điều hướng để duyệt 4 ô kề cạnh (Trên, Dưới, Trái, Phải)
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

void solve() {
    int n, m;
    cin >> n >> m;
    
    // Sử dụng vector 2 chiều để lưu lưới (hợp lệ theo danh sách cho phép)
    vector<vector<int> > a(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    
    long long max_volume = 0;
    
    // Duyệt qua từng ô của lưới
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            // Nếu phát hiện một ô có nước chưa được thăm
            if (a[i][j] > 0) {
                long long current_volume = 0;
                
                // Khởi tạo BFS dùng queue và pair
                queue<pair<int, int> > q;
                q.push(make_pair(i, j));
                
                // Cộng dồn thể tích và xóa ô nước đi (tương đương việc đánh dấu visited)
                current_volume += a[i][j];
                a[i][j] = 0; 
                
                while (!q.empty()) {
                    pair<int, int> curr = q.front();
                    q.pop();
                    
                    int r = curr.first;
                    int c = curr.second;
                    
                    // Thử loang ra 4 hướng
                    for (int k = 0; k < 4; k++) {
                        int nr = r + dx[k];
                        int nc = c + dy[k];
                        
                        // Kiểm tra biên và xem ô có nước không
                        if (nr >= 0 && nr < n && nc >= 0 && nc < m && a[nr][nc] > 0) {
                            current_volume += a[nr][nc];
                            a[nr][nc] = 0; // Đánh dấu ngay lúc push vào queue để tránh lặp
                            q.push(make_pair(nr, nc));
                        }
                    }
                }
                
                // Cập nhật kết quả lớn nhất
                max_volume = get_max(max_volume, current_volume);
            }
        }
    }
    
    cout << max_volume << "\n";
}

int main() {
    // Tối ưu I/O cho C++
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}