#include <iostream>

using namespace std;

const long long MOD = 1e9 + 7;

/**
 * Tính (base^exp) % MOD bằng thuật toán lũy thừa nhanh (Binary Exponentiation).
 */
long long power(long long base, long long exp) {
    long long res = 1;
    base %= MOD;
    
    while (exp > 0) {
        if (exp & 1) { // Kiểm tra bit cuối là 1 (tương đương exp % 2 == 1)
            res = (res * base) % MOD;
        }
        base = (base * base) % MOD;
        exp >>= 1; // Dịch phải 1 bit (tương đương exp /= 2)
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n = 7;
    cout << "2^" << n << " % MOD = " << power(2, n) << "\n";
    
    return 0;
}