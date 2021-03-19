#include <iostream>
#include <map>
#include <cmath>
#include <string>
using namespace std;

int func(int n){
    if (n < 0){
        return 0;
    }
    if (n == 1){
        return 1;
    }
    if (n == 5){
        return 2;
    }
    return func(n - 1) + func(n - 5);
}

int main() {
    int x;
    cin >> x;
    cout << func(x);
}
