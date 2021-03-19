#include <iostream>
using namespace std;

long long int factorial(int n){
    long long int fact = 1;
    for (int i = n; i > 1; i--){
        fact *= i;
    }
    return fact;
}


int main(){
    int x;
    long long int m, y;
    cin >> x;
    m = factorial(2*x);
    y = factorial(x);
    cout << m/(y*y*(x+1));
}