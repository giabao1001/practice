#include <iostream>
#include <vector>
using namespace std;

int n = 8; 
int Count = 0;
bool coll[20], diag1[40], diag2[40]; // Dùng mảng tĩnh cho nhanh
char board[9][9];

void solve(int row) {
    if (row == n) {
        Count++;
        return;
    }
    for (int col = 0; col < n; ++col) {
        // Kiểm tra: ô không cấm VÀ cột/đường chéo chưa bị chiếm
        if (board[row][col] == '.' && !coll[col] && !diag1[row + col] && !diag2[row - col + n]) {
            // Đặt hậu
            coll[col] = diag1[row + col] = diag2[row - col + n] = true;
            
            solve(row + 1);

            // Quay lui (Backtrack)
            coll[col] = diag1[row + col] = diag2[row - col + n] = false;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); // Tối ưu tốc độ nhập xuất
    cin.tie(NULL);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> board[i][j];
        }
    }

    solve(0);
    cout << Count << "\n";

    return 0;
}