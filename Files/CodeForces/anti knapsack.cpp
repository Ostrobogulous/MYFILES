    #include <bits/stdc++.h>
    using namespace std;
     
     
     
     
    int main(){
        int t, n, k;
        cin >> t;
        while (t--){
            cin >> n >> k;
            vector<int> v;
            for (int i = k +1; i <= n; i++){
                v.push_back(i);
            }
            for (int i = ((k+1) / 2); i < k; i++){
                v.push_back(i);
            }
            cout << v.size() << endl;
            for (auto el : v){
                cout << el << " ";
            }
            cout << endl;
        }
    }