#include <iostream>
using namespace std;

const int maxn = 100;
int n, arr[maxn], t[maxn*4];

void build (int curr, int left, int right){
    if ( left == right ){
        t[curr] = arr[left];
        return;
    }
    int mid = (left + right)/2;
    build(curr*2,left,mid);
    build(curr*2 + 1, mid +1, right);
    t[curr] = t[curr*2] + t[curr*2+1];
}

void update (int curr , int left, int right, int pos, int val){
    // curr số thứ tự của số trong cây
    // pos là vị trí để có thể gán val 
    if ( left == right ){
        t[curr] = val;
    }
    else {
        int mid = (left + right)/2;
        if (pos <= mid){
            update(2*curr,left,mid,pos,val);
        }
        else {
            update(2*curr+1,mid+1,right,pos,val);
        }
        t[curr] = t[curr*2] + t[curr*2+1];
    }
}
// truy vấn
long long query(int curr, int tleft, int tright, int left, int right){
    if (tleft == left && tright == right){
        return t[curr];
    }

    // case 1:
    if ( tleft > right || tright < left ) return 0;
    // case 2: 
     if ( tleft >= left && tright <= right ){
        return t[curr];
    }
    // case 3;
    int mid = (tleft + tright)/2;
    long long s1 = query(curr*2,tleft,mid,left,right);
    long long s2 = query(curr*2+1,mid +1,tright,left,right);
    return s1 + s2;
}

int main() {
ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; ++i){
        arr[i] = i;
    }
    build(1,1,n);
    cout << query(1,1,n,1,3) << "\n";
    return 0;
}