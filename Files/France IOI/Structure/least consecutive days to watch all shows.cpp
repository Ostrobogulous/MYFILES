#include <bits/stdc++.h>
using namespace std;
int main(){
    int d, y;
    cin >> d >> y;
    int b[100001];
    int arr[100000];
    for (int i = 0; i < y; i++){
        b[i] = 0;
    }
    for(int i = 0; i < d; i++){
        cin >> arr[i];
    }
    int count = 0, mini = d, p = 0;
    for (int i = 0; i < d; i++){
        if (b[arr[i]] == 0){
            count++;
        }
        b[arr[i]]++;
        if (count == y){
            while (b[arr[p]] > 1){
                b[arr[p]]--;
                p++;
            }
            mini = min(mini, i - p + 1);
        }
    }
    cout << mini;
}