#include <bits/stdc++.h>
using namespace std;
int main() {
    int x, y, maxi = 0, p = 0, s = 0;
    cin >> x >> y;
    int arr[x];
    for (int i = 0; i < x; i++){
        cin >> arr[i];
    }
    for (int i = 0; i < x; i++){
        s += arr[i];
        while (s > y){
            s -= arr[p];
            p++;
        }
        if (i - p + 1> maxi){
            maxi = i - p + 1;
        }
    }
    cout << maxi;
}