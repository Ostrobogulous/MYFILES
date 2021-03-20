#include <bits/stdc++.h>
using namespace std;


int main(){
    int n, res = 0, level;
    cin >> n;
    for (int i = 1; i <= n; i++){
        level = i * (i + 1) / 2;
        res += level;
        if (res >= n){
            while (res - i >= n){
                res -= i;
                i--;
                level--;
            }
            break;
        }
    }
    cout << level;
}