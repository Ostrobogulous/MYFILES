    #include <bits/stdc++.h>
    using namespace std;
     
     
    void b_search(long long  a, long long b){
        long long l = 1, r = 10e9, ans, mid, y;
        while (l <= r){
            mid = (l + r) / 2;
            y = mid - mid / a;
            if (y == b){
                ans = mid;
                r = mid - 1;
            }
            else if (y > b){
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        cout << ans << endl;
    }
     
     
     
    int main() {
        int t;
        cin >> t;
        long long a, b;
        while (t--){
            cin >> a >> b;
            b_search(a, b);
        }
    }