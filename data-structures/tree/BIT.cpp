#include <iostream>
using namespace std;

int n; 
int BIT[100005]; // khai báo đại size 

void updateTree (int index, int val){
    while ( index <= n ){
        BIT[index] += val;
        index += (index & -index);
    }
}

int sumRange(int index){
    int sum  = 0;
    while (index >= 0){
        sum += BIT[index];
        index -= (index & -index);
    }
    return sum;
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cout << (6 & -6) << " \n";
    return 0;
}