#include <bits/stdc++.h>
using namespace std;


int main(){
    int n, k;
    cin >> n >> k;
    vector <char> v;
    k -= n;
    while (n > 0) {
        n--;
        v.push_back(min('a' + k, 'a' + 25));
        k -= min(k, 25);
    }
    reverse(v.begin(), v.end());
    for (auto el : v){
        cout << el;
    }
        
}