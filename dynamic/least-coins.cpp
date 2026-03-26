#include <climits>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int s ;
    cin >> s;
    const int max = 1e9;
    vector<int> coins (s+1,max);
    vector<int> value = {1,3,5,7};
    coins[0] = 0;
    for ( int i = 1; i <= s; ++i ){
        for ( auto v : value ){
            if ( i - v >= 0 && coins[i-v] != max ){
                coins[i] = min(coins[i], coins[i-v] + 1);
            }
        }
    }

    cout << coins[s] << "\n";
    return 0;
}