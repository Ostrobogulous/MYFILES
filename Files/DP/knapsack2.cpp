#include <bits/stdc++.h>
using namespace std;


long long const N = 100004;
long long dp[102][N];


int main(){
    long long o, capacity;
    long long w, v;
    cin >> o >> capacity;
    long long maxi= 0;
    long long weights[N]; long long profits[N];
    for (long long i = 0; i < o; i++){
        cin >> w >> v;
        weights[i] = w; profits[i] = v;
    }
    for (long long i = 0; i < capacity; i++){
        dp[0][i] = 0;
    }
    for (long long i = 1; i <= o; i++){
        for (long long j = 1; j <= capacity; j++) {
            long long y = 0;
            if (j >= weights[i-1]){
                y += profits[i-1] * (j / weights[i-1]);
                y += dp[i-1][j - (weights[i-1] * (j / weights[i-1])) - 1];
            }
            dp[i][j-1] = max(dp[i-1][j-1], y);
            maxi = max(dp[i][j-1], maxi);
        }
    }
    cout << maxi;
}
