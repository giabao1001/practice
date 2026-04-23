#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;

/**
 * Tính tổ hợp chập k của n (nCr) dư MOD.
 * Sử dụng công thức Pascal: C(n, k) = C(n-1, k-1) + C(n-1, k)
 */
int nCr(int n, int k) {
    if (k < 0 || k > n) return 0;
    if (k == 0 || k == n) return 1;
    if (k > n / 2) k = n - k; // Tối ưu: C(n, k) = C(n, n-k)

    vector<int> dp(k + 1, 0);
    dp[0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = min(i, k); j > 0; j--) {
            dp[j] = (dp[j] + dp[j - 1]) % MOD;
        }
    }
    return dp[k];
}

int main() {
    int n = 5, k = 2;
    cout << "C(" << n << ", " << k << ") = " << nCr(n, k) << endl;
    return 0;
}