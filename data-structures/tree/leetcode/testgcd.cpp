#include <iostream>
using namespace std;

int getGcd(int a, int b){
    while (b!=0){
        a %= b;
        int temp = a;
        a = b; 
        b = temp;
    }
    return a;
}

int main() {
ios_base::sync_with_stdio(false); cin.tie(NULL);
    cout << getGcd(4,16) << "\n";
    return 0;
}