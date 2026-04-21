#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m; 
    cin >> n >> m;
    vector<vector<int>> A = {
        {1, 3, 1, 5},
        {2, 2, 4, 1},
        {5, 0, 2, 3}
    };
    vector<vector<int>> Sum (n,vector<int>(m,0));
    for (int i = 0;i < m; ++i){
        for (int j = 0; j < n; ++j){
            int maxPrevious = 0; 

            if (i > 0){
                maxPrevious = max(Sum[i-1][j],maxPrevious);
            }

            if (j > 0 ){
                maxPrevious = max(Sum[i][j-1],maxPrevious);
            }

            Sum[i][j] = A[i][j] + maxPrevious;
        }
    }
    cout << Sum[m-1][n-1] << "\n";
    return 0;
}