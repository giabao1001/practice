#include <iostream>
using namespace std;

int m = 1000000007;

long long biPow ( long long a, long long n) {
    long long res = 1;
    while ( n > 0 ){
        if ( n%2 == 1 ){
            res *= a%m ;
        }
        a*=a;
        n/=2;
    }
    return res;
}

int main() {
    int n = 7;
    cout << biPow (2,n) << "\n" ;  
    return 0;
}