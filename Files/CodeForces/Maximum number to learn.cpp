    #include <bits/stdc++.h>
    using namespace std;
     
     
     
     
     
    int main(){
        int n, x;
        cin >> n >> x;
        vector<int> v(n);
        for (int i = 0; i < n; i++){
            cin >> v[i];
        }
        sort(v.begin(), v.end());
        int ans = 0;
        int i = 0;
        while (ans + v[i] <= x and i < n){
            ans += v[i];
            i++;
        }
        cout << i ;
    }