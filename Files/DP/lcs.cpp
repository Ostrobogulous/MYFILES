#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 20;

int arr[N];
int dp[N];

int main(){
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++){
        int maxi = 0;
        for (int j = i; j >=0; j--){
            if (arr[j] < arr[i] and dp[j] > maxi){
                maxi =dp[j];
            }
        }
        dp[i] = 1 + maxi;
    }
    int maxi = 0;
    for (int i = 0; i < n; i++){
        maxi = max(maxi, dp[i]);
    }
    cout << maxi;
    int cur = maxi;
    vector <int> seq;
    int j = n - 1;
    while (cur != 0){
        cout << j << endl;
        if (dp[j] == cur){
            cur -= 1;
            seq.push_back(arr[j]);
        }
        j--;

    }
    reverse(seq.begin(), seq.end());
    for (auto el : seq){
        cout << el <<  " " ;
    }
}
