#include <iostream>
#include <algorithm>
using namespace std;

void compression(vector <int> arr,int n){
    vector<int> copy = arr;
    sort(copy.begin(),copy.end());
    for ( int i = 0; i < n; ++i ){
    arr[i] = lower_bound(copy.begin(),copy.end(),arr[i]) - arr.begin() + 1;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    return 0;
}