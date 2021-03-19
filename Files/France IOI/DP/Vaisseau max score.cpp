#include <bits/stdc++.h>
using namespace std;
long long dp[2002][57];
int main(){
    long long n, m, p, a;
    cin >> n >> m >> p;
    p += 1;
    for (long long i = 0; i < n; i++){
        for (long long j = 0; j <= m +1; j++){
            dp[i][j] = - INT_MAX;
        }
    }
    for (long long i = 0; i < n; i++){
        for (long long j = 1; j <= m; j++){
            cin >> a;
            dp[i][j] = a;
        }
    }
    for (long long j = 0; j <= m +1; j++){
        if (j == p){
            continue;
        }
        else{
            dp[n-1][j] = - INT_MAX;
        }
    }
    long long maxi = - INT_MAX;
    for (long long i = n - 2; i >= 0; i--){
        for (long long j = 1; j <= m; j++){
            dp[i][j] += max(dp[i+1][j], max(dp[i+1][j-1], dp[i+1][j+1]));
        }
    }
    for (long long i = 1; i <= m; i++){
        maxi = max(maxi, dp[0][i]);
    }
    cout << maxi;
}