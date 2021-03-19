#include <iostream>
using namespace std;


const int N = 100;
int dp[N][N];


int main(){
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++){
        dp[i][i] = 1;
    }
    int p = s.size() - 1;
    for (int j = 1; j < s.size(); j++){
        for (int i = 0; i < p; i++){
            if (s[i] == s[i+j]){
                dp[i][i+j] = 2 + dp[i+1][i+j-1];
            }
            else{
                dp[i][i+j] = max(dp[i+1][i+j], dp[i][i+j-1]);
            }
        }
        p--;
    }
    cout << dp[0][s.size()-1];
}