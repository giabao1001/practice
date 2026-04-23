#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Nén tọa độ các phần tử trong mảng.
 * Ví dụ: {10, 100, 50} -> {1, 3, 2}
 */
void compressCoordinates(vector<int>& arr) {
    vector<int> temp = arr;
    sort(temp.begin(), temp.end());
    
    // Loại bỏ các phần tử trùng lặp
    temp.erase(unique(temp.begin(), temp.end()), temp.end());

    for (int &x : arr) {
        // Tìm vị trí của x trong mảng đã sắp xếp để lấy thứ hạng
        x = lower_bound(temp.begin(), temp.end(), x) - temp.begin() + 1;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> arr = {10, 100, 50, 10, 50};
    compressCoordinates(arr);

    for (int x : arr) {
        cout << x << " ";
    }
    
    return 0;
}