#include <iostream>
using namespace std;

int main() {
ios_base::sync_with_stdio(false); cin.tie(NULL);
    int arr [7] = { 4, 5, 6, 7, 0, 1, 2};
    int n = 7;
    int left = 0;
    int right = n - 1 ;
    while ( left != right ){
        int mid = (left + right)/2;
        if ( arr [mid] < arr [right]) {
            cout << "left: " << left << " " ;
            cout << "right: " << right << "\n";
            right = mid ;
        }
        else {
            cout << "left: " << left << " " ;
            cout << "right: " << right << "\n";
            left = mid + 1;
        }
    }
    cout << left  << "\n";
    return 0;
}