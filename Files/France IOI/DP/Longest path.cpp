#include <bits/stdc++.h>
using namespace std;


const long long N = 10007;

vector <pair<long long,long long>> g[N];
long long dp[N];
bool visited[N];
long long n, m;
bool c = false;


long long func(){
    queue <long long> q;
    q.push(1);
    visited[1] = true;
    while (!q.empty()){
        long long o = q.front();
        q.pop();
        visited[o] = false;
        for (int i = 0; i < g[o].size(); i++){
            if (dp[g[o][i].first] < dp[o] + g[o][i].second){
                dp[g[o][i].first] = dp[o] + g[o][i].second;
                if (!visited[g[o][i].first]){
                    visited[g[o][i].first] = true;
                    q.push(g[o][i].first);
                }
            }
        }
    }
    return dp[n];

}





int main(){
    cin >> n >> m;
    long long a, b, w;
    for (long long i = 0; i < m; i++){
        cin >> a >> b >> w;
        g[a].emplace_back(b, w);
    }
    cout << func();
}