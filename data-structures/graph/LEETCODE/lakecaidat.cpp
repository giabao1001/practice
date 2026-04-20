#include <iostream>
#include <vector>
#include <queue>
using namespace std;

long long getMax(long long a, long long b){
    if ( a > b) return a;
    return b;
}

long long solve (){
    const int dx[] = {-1,1,0,0};
    const int dy[] = {0,0,1,-1};
    int n, m;
    cin >> n >> m;
    vector <vector<int>> arr (n,vector<int>(m,0));
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < m ; ++j){
            cin >> arr[i][j];
        }
    }
    long long maxWater = 0;
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < m ; ++j){
            if (arr[i][j]>0){
                long long currWater = 0;
                queue<pair<int,int>> q;
                q.push(make_pair(i,j));
                currWater += arr[i][j];
                arr[i][j] = 0;
                while (!q.empty()){
                    pair <int,int> curr = q.front();
                    q.pop();
                    int row = curr.first;
                    int col = curr.second;
                    for (int k = 0; k < 4; ++k){
                        int currCol = col + dx[k];
                        int currRow = row + dy[k];
                        if ( currCol >= 0 && currCol < m && currRow >=0 && currRow <n && arr[currRow][currCol] > 0){
                            currWater += arr[currRow][currCol] ;
                            arr[currRow][currCol] = 0;
                            q.push(make_pair(currRow,currCol));
                        }
                    }
                }
                maxWater = getMax(currWater,maxWater);
            }
        }
    }
    return maxWater;
}

int main() {
ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    return 0;
}