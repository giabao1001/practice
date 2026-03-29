#include <iostream>
#include <queue>

using namespace std;

int main() {
    priority_queue<int> maxPq;
    priority_queue<int,vector<int>,greater<int>> minPq;
    int n; 
    cin >> n;
    for (int i = 0; i < n; ++ i){
        maxPq.push(i);
        minPq.push(i);
    }
    for (int i = 0; i < n; ++i){
        cout << maxPq.top() << " ";
        maxPq.pop();
        cout << minPq.top() << "\n";
        minPq.pop();
    }
    return 0;
}