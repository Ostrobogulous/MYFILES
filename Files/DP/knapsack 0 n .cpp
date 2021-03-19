#include <bits/stdc++.h>
using namespace std;



int main(){
    vector<pair<int, int>> v;
    int o, c, w, p;
    cin >> o >> c;
    for (int i = 0; i < o; i++){
        cin >> p >> w ;
        v.emplace_back(p, w);
    }
    int dp[c];
    for (int i = 0; i < c; i++){
        dp[i] = 0;
    }
    for (int i = 0; i < c; i++){
        for (int j = 0; j < o; j++){
            if (v[j].second <= i + 1){
                dp[i] = max(v[j].first + dp[i-v[j].second], dp[i]);
            }
        }
    }
    cout << dp[c-1];

}