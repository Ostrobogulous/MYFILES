#include <bits/stdc++.h>
using namespace std;
const int N = 10004;
vector <int> g[N];
bool visited[N];
int dp[N];
int c = 0;
int n, m;
int func(int a){
    if (a == n){
        return 1;
    }
    if (dp[a] != -1){
        return dp[a];
    }
    else{
        dp[a] = 0;
        for (int i = 0; i < g[a].size(); i++){
            if (!visited[g[a][i]]){
                visited[g[a][i]] = true;
                dp[a] +=  func(g[a][i]);
                visited[g[a][i]] = false;
            }
        }
        return dp[a];
    }
}
int main(){
    int  a, b;
    cin >> n >> m;
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < m; i++){
        cin >> a >> b;
        g[a].push_back(b);
    }
    g[0].push_back(1);
    func(0);
    cout << dp[1];
}