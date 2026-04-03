#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        queue<int> q; // Hàng đợi lưu các Index
        vector<bool> visited(n, false); // Đánh dấu Index đã đi qua

        // 1. Khởi tạo điểm xuất phát
        q.push(start);
        visited[start] = true;

        // 2. Bắt đầu loang sóng
        while (!q.empty()) {
            int curr_idx = q.front();
            q.pop();

            // Rút trúng đích (ô có giá trị 0) -> Thắng game!
            if (arr[curr_idx] == 0) {
                return true; 
            }

            // Tính toán 2 "con đường" có thể đi từ curr_idx
            int jump_right = curr_idx + arr[curr_idx];
            int jump_left = curr_idx - arr[curr_idx];

            // Nếu rẽ phải hợp lệ (không văng khỏi mảng và chưa đi qua)
            if (jump_right < n && !visited[jump_right]) {
                q.push(jump_right);
                visited[jump_right] = true; // Đánh dấu ngay!
            }

            // Nếu rẽ trái hợp lệ
            if (jump_left >= 0 && !visited[jump_left]) {
                q.push(jump_left);
                visited[jump_left] = true;
            }
        }

        // Hàng đợi cạn kiệt mà không tìm thấy số 0 nào
        return false;
    }
};