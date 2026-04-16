#include <iostream>
#include <vector>
using namespace std;


int getGcd(int a, int b){
    while (a!=0){
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

struct Node{
    int count;
    int Gcd;
};

const int maxN = 100005;
int arr[maxN];
Node tree[maxN*4];
int n ;

Node mergeNode(Node L, Node R){
    Node res;
    res.Gcd = getGcd(L.Gcd,R.Gcd);
    res.count = 0;
    if (L.Gcd == res.Gcd) res.count += L.count;
    if (R.Gcd == res.Gcd) res.count += R.count;
    return res;
}

void build ( int pos, int left, int right){
    if ( left == right ){
        tree[pos].Gcd = arr[left];
        tree[pos].count = 1;
        return;
    }
    int mid = (left + right)/2;
    build (pos*2, left, mid);
    build (pos*2 +1, mid + 1, right);
    tree[pos] = mergeNode(tree[pos*2],tree[pos*2+1]);
}

Node query(int pos, int tleft, int tright,int left, int right ){
    if ( right < tleft || left > tright){
        return {0,0};
    }
    if ( tleft >= left && tright <= right ){
        return tree[pos];
    }
    else {
        int mid = (tleft + tright)/2;
        Node p1 = query(pos*2,tleft,mid,left,right);
        Node p2 =query(pos*2+1,mid+1,right,left,right);

        if (p1.Gcd == 0) return p2;
        if (p2.Gcd == 0) return p1;

        return mergeNode(p1,p2);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}