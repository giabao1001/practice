#include <iostream>
#include <algorithm>
using namespace std;

int n;
int BIT[1000005];

void compression(vector <int> &arr){
    vector<int> copy = arr;
    sort(copy.begin(),copy.end());
    for ( int i = 1; i <= n ; ++i ){
    arr[i] = lower_bound(copy.begin(),copy.end(),arr[i]) - copy.begin() + 1;
}
}


void updateBIT(int index){
    while (index <= n ){
        BIT[index] += 1;
        index += (index & -index);
    }
}

int countSum (int index){
    int sum = 0;
    while (index > 0 ){
        sum += BIT[index];
        index -= (index & -index);
    }
    return sum;
}

int rangeSum (int left, int right){
    return countSum(right) - countSum(left-1);
}

int main() {
ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n;
    vector <int> arr (n+1);
    for (int i = 1; i <= n; ++ i){
        cin >> arr[i];
    }
    compression(arr);
    
    vector<long long> L (n+1);
    vector<long long> R (n+1);
    for (int i = 1 ; i <= n; ++i){
        L[i] = i - 1 - countSum(arr[i]);
        updateBIT(arr[i]);
    }

    for (int i = 1; i <= n ; ++ i ){
        BIT[i] = 0;
    }

    for (int i = n  ; i >= 1; -- i){
        R[i] = countSum(arr[i]);
        updateBIT(arr[i]);
    }
    
    long long sum = 0;
    
    for ( int i = 1; i <= n; ++ i){
        sum += L[i] * R[i];
    }
    cout << sum ;
    return 0;
}