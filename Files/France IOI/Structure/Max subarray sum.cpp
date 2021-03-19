#include <iostream>
#include <algorithm>
#include <cmath>
#include <map>
#include <stack>
using namespace std;
int main(){
    int x, maxi = 0, o, current = 0;
    cin >> x;
    int arr[x];
    for (int i = 0; i < x; i++){
        cin >> arr[i];
    }
    for (int i = 0; i < x; i++){
        o = max(current + arr[i], arr[i]);
        if (o > maxi){
            maxi = o;
        }
        current = o;
    }
    cout << maxi;
}