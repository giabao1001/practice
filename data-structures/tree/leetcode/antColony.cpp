#include <iostream>
#include <vector>
#include <numeric> // Cho std::gcd (C++17)

using namespace std;

// Dùng std::gcd nếu dùng C++17, nếu không dùng hàm này:
int computeGcd(int a, int b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

struct Node {
    int gcdValue;
    int count;
};

class SegmentTree {
private:
    int n;
    vector<Node> tree;
    vector<int> data;

    Node merge(Node L, Node R) {
        if (L.gcdValue == 0) return R;
        if (R.gcdValue == 0) return L;

        int resGcd = computeGcd(L.gcdValue, R.gcdValue);
        int resCount = 0;
        if (L.gcdValue == resGcd) resCount += L.count;
        if (R.gcdValue == resGcd) resCount += R.count;
        
        return {resGcd, resCount};
    }

    void build(int pos, int l, int r) {
        if (l == r) {
            tree[pos] = {data[l], 1};
            return;
        }
        int mid = (l + r) / 2;
        build(2 * pos, l, mid);
        build(2 * pos + 1, mid + 1, r);
        tree[pos] = merge(tree[2 * pos], tree[2 * pos + 1]);
    }

    Node query(int pos, int tl, int tr, int l, int r) {
        if (l > r) return {0, 0};
        if (l == tl && r == tr) return tree[pos];
        
        int mid = (tl + tr) / 2;
        return merge(query(2 * pos, tl, mid, l, min(r, mid)),
                     query(2 * pos + 1, mid + 1, tr, max(l, mid + 1), r));
    }

public:
    SegmentTree(const vector<int>& input) : data(input) {
        n = data.size() - 1;
        tree.assign(4 * n + 1, {0, 0});
        build(1, 1, n);
    }