#include <bits/stdc++.h>
using namespace std;







int main(){
    int n, m, o;
    cin >> n >> m;
    map <int, int> v;
    for (int i = 0; i < m; i++){
        cin >> o;
        v[o]++;
    }
    int l = 0, r = 100;
    int ans = 0, c;
    if (n > m){
        cout << 0;
        return 0;
    }
    while (l <= r){
        c = 0;
        int mid = l + (r - l) / 2;
        if (mid == 0){
            mid = 1;
        }
        for (auto el : v){
            c += el.second / mid;
        }
        if (c < n){
            r = mid - 1;
        }
        if (c >= n){
            ans = mid;
            l = mid + 1;
        }
    }
    cout << ans;

}