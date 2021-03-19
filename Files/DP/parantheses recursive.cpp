#include <iostream>
using namespace std;

int ways(int n){
    int res = 0;
    if (n == 0){
        return 1;
    }
    for (int i = 0; i < n; i++){
        res += ways(i) * ways(n - i - 1);
    }
    return res;

}


int main(){
    int n;
    cin >> n;
    cout << ways(n);

}