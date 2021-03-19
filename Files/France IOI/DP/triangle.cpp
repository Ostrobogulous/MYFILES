#include <bits/stdc++.h>
using namespace std;
const int N = 204;
int dp[N][N];
int g[N][N];
int n;
int func(int y, int x){
    if (x < 0 or x > n * 2 or y > n * 2){
        return 0;
    }
    if (dp[y][x]){
        return dp[y][x];
    }
    if (g[y][x] == -1){
        return 0;
    }
    else{
        return dp[y][x] = g[y][x] + max(func(y+1, x - 1), func(y+1, x + 1));
    }
}
int main(){
    int p = 0;
    cin >> n;
    memset(g, -1, sizeof(g));
    for (int i = 0; i < n; i++){
        int o = n - i;
        p++;
        for (int j = 0; j < p; j++){
            cin >> g[i][o];
            o += 2;
        }
    }
    cout << func(0, n);
}