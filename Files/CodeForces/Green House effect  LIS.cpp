#include <bits/stdc++.h>
using namespace std;

const int N = 5004;
int dp[N];

int main() {
    int n, m, a;
    double b;
    cin >> n >> m;
    vector<int> v;
    map <int,int> dic;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        v.push_back(a);
    }
    for (int i = 0; i < n; i++){
        int maxi = 0;
        for (int j = i; j >=0; j--){
            if (v[j] <= v[i] and dp[j] > maxi){
                maxi =dp[j];
            }
        }
        dp[i] = 1 + maxi;
    }
    int maxi = 0;
    for (int i = 0; i < n; i++){
        maxi = max(maxi, dp[i]);
    }
    cout << n - maxi;

}