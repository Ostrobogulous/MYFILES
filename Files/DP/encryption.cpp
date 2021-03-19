#include <bits/stdc++.h>
using namespace std;


const int N = 5007;
long long dp[N];
string l;


int main() {
    while (true) {
        cin >> l;
        memset(dp, 0, sizeof(dp));
        if (l == "0") {
            break;
        }
        dp[0] = 1; dp[1] = 1;
        for (int i = 2; i <= l.size(); i++){
            if (l[i-2] == '1' or (l[i-2] == '2' and l[i-1] <= '6')){
                dp[i] += dp[i-2];
            }
            if (l[i-1] != '0') {
                dp[i] += dp[i - 1];
            }
        }
        cout << dp[l.size()] << endl;
    }
}