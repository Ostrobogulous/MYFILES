#include <bits/stdc++.h>
using namespace std;


const int N = 102;
int dp[N][N];

int main(){
    int n;
    cin >> n;
    string seq;
    cin >> seq;
    vector <char> v;
    v.push_back('0');
    for (int i = 0; i < n ;i++){
        v.push_back(seq[i]);
    }
    for (int i = 1; i < n; i++){
        for (int j = i+1; j <= n; j++){
//            cout << i << " " << j << " " << v[i] << " " << v[j] << endl;
            if (v[i] == v[j]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    cout << dp[n-1][n] << endl;
    int i = n - 1;
    int j = n;
    vector <char> s;
    while(true) {
        if (v[i] == v[j] and i != j){
            s.push_back(v[i]);
            i--;
            j--;
            if (s.size() == dp[n-1][n]){
                break;
            }
        }
        else{
            if (dp[i][j] == dp[i-1][j]){
                i--;
            }
            else{
                j--;
            }
        }
    }
    reverse(s.begin(), s.end());
    for (auto el : s){
        cout << el << " ";
    }

}
