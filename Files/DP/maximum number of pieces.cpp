#include <bits/stdc++.h>
using namespace std;

const int N = 1000;
int a, b, c;
int dp[N];


int func(int n) {
    if (n < 0) {
        return  -1e9;
    }
    else if (n == 0){
        return 0;
    }
    else if(dp[n] != 0){
        return dp[n];
    }
    else{
        dp[n] = 1 + max(func(n - a), max(func(n - b), func(n -  c)));
        return dp[n];
    }
}



int main(){
    int n;
    cin >> n;
    cin >> a >> b >> c;
    int solution = func(n);
    if (solution <= -1e9){
        cout << -1;
    }
    else{
        cout << solution;
    }

}