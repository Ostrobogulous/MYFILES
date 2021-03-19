    #include<bits/stdc++.h>
    using namespace std;
     
     
     
     
     
    int main(){
        int t;
        long long num, c;
        cin >> t;
        while (t--){
            cin >> num >> c;
            cout << fixed  << setprecision(0) << c + floor((c - 1) / (num - 1)) << endl;
        }
    }