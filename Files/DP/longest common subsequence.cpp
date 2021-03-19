#include <bits/stdc++.h>
using namespace std;


const int N = 102;

int main(){
    int n, m;
    int dp[N][N];
    cin >> n >> m;
    vector <int> v1(n+1);
    v1.push_back(0);
    vector <int> v2(m+1);
    v2.push_back(0);
    for (int i = 1; i <= n ;i++){
        cin >> v1[i];
    }
    for (int j = 1; j <= m; j++){
        cin >> v2[j];
    }
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            if (v1[i] == v2[j]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    int i = n;
    int j = m;
    vector <int> s;
    while(true) {
        if (v1[i] == v2[j]){
            s.push_back(v1[i]);
            i--;
            j--;
            if (s.size() == dp[n][m]){
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
