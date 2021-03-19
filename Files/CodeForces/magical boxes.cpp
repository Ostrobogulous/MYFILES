#include <bits/stdc++.h>
using namespace std;



int main() {
    int n;
    cin >> n;
    int a = 0, maxi = 0;
    for (int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        maxi = max(x, maxi);
        int o = 0, s = 1;
        while (s < y){
            s *= 4;
            o++;
        }
        a = max(a, x + o);
    }
    if (a == maxi){
        a++;
    }
    cout << a;

}