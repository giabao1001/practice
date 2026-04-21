#include <iostream>
#include <vector>
using namespace std;
const int Max = 1e9;
int main() {
ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n ;
    cout << "so loai tien: ";
    cin >> n;
    vector<int> type(n);
    for (int i = 0; i < n; ++i){
        cin >> type[i];
    }
    cout << "Tong can tim: ";
    int s;
    cin >> s;
    vector<int> traces(s+1,-1);
    vector<int> coin(s+1,Max);
    coin[0] = 0 ;
    for (int i = 1; i <= s; ++i){
        for(int v: type){
            // vấn đề mấu chốt nằm ở việc là điều kiện để có thể xét phần tử hiện tại 
            if (i - v >= 0 && coin[i-v] != Max){
                if ( coin[i] >= coin[i-v] +1 ){
                    coin[i] = coin[i-v] + 1;
                    traces[i] = v;
                }
            }
        }
    }
    cout << "total: " << coin[s] << "\n";
    int temp = s;
    while (temp > 0){
        cout << traces[temp] << " ";
        temp = temp - traces[temp];
    }
    cout << "\n";
    return 0;
}