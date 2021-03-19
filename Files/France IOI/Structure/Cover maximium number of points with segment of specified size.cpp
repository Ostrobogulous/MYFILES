#include <bits/stdc++.h>
using namespace std;
int main(){
    long int x, y, s = 0, maxi = 1, res = 0;
    long int arr[100000];
    cin >> x >> y;
    for (int i = 0; i < y; i++){
        cin >> arr[i];
    }
    sort(arr, arr + y);
    for (int i = 1; i < y; i++){
        res = arr[i] - arr[s];
        while (res > x){
            s += 1;
            res = arr[i] - arr[s];
        }
        if (i - s + 1 > maxi){
            maxi = i - s + 1;
        }
    }
    cout << maxi;
}