    #include <bits/stdc++.h>
    using namespace std;
    const long long N = 2*1e5 + 4;
     
     
    long long dp[N];
     
    int main() {
        long long t, maxi;
        cin >> t;
        for (long long i = 0; i < t; i++){
            long long a, b;
            maxi = 0;
            cin >> a;
            memset(dp, 0, sizeof(dp));
            for (long long j = 1; j <= a; j++){
                cin >> b;
                dp[j] += b;
                if (j + b <= a){
                    dp[j+b] = max(dp[j], dp[j + b]);
                }
                maxi = max(maxi, dp[j]);
            }
            cout << maxi << endl;
        }
    }