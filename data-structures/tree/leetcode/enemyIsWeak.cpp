#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct FenwickTree {
    int size;
    vector<int> tree;

    FenwickTree(int n) : size(n), tree(n + 1, 0) {}

    void update(int i, int delta) {
        for (; i <= size; i += i & -i) tree[i] += delta;
    }

    int query(int i) {
        int sum = 0;
        for (; i > 0; i -= i & -i) sum += tree[i];
        return sum;
    }

    void clear() {
        fill(tree.begin(), tree.end(), 0);
    }
};

void compress(vector<int>& a) {
    vector<int> temp = a;
    sort(temp.begin(), temp.end());
    temp.erase(unique(temp.begin(), temp.end()), temp.end());
    for (int &x : a) {
        x = lower_bound(temp.begin(), temp.end(), x) - temp.begin() + 1;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);