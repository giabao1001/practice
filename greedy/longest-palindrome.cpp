#include <exception>
#include <iostream>
#include <algorithm>
using namespace std;
    int longestPalindrome(string s) {
        int largest = 0;
        char smallest = s[0];
        char biggest = s[0];
        for (int i = 0 ; i < s.size() ; ++ i){
            if ( s[i] < smallest ){
                smallest = s[i];
            }
            else if ( s[i] > biggest ){
                biggest = s[i];
            }
        }
        int nCount = biggest - smallest + 1;
        int count [nCount]; 
        for ( int i = 0; i < nCount; ++i ){
            count[i] = 0;
        }

        for ( auto a : s){
           auto temp = a - smallest;
           count[temp] ++;
        }
        bool hasOdd = 0;
        for (int i = 0 ; i < nCount; ++i){
            if ( count[i] %2 == 0){
                largest += count[i];
            }
            else {
                largest += count[i] - 1;
                hasOdd = 1;
            }
        }
        if (hasOdd) largest += 1;
        return largest;
    }
int main() {
    string s = "abccccdd"; 
    cout << longestPalindrome(s) << "\n";
    return 0;
}