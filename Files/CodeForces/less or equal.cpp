→ Source
Copy

    #include <bits/stdc++.h>
    using namespace std;
     
     
     
    int main() {
        long long n,k, a;
        cin >> n >> k;
        vector <long long> v;
        for (long long i = 0; i < n; i++){
            cin >> a;
            v.push_back(a);
        }
        sort(v.begin(), v.end());
        if (k == 0){
            if (v[0] > 1){
                cout << 1;
            }
            else{
                cout << -1;
            }
            return 0;
        }
        int cnt = 0;
        for (int i = 0; i < n; i++){
            if (v[i] <= v[k-1]){
                cnt++;
            }
        }
        if (v[k-1] > 10e9 or cnt != k){
            cout << -1;
            return 0;
        }
        cout << v[k-1];
    }