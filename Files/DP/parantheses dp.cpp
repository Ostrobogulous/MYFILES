#include <iostream>
using namespace std;



int main(){
    int n;
    cin >> n;
    long long int table[n+1];
    table[0] = 1;
    for (int i = 1; i <= n + 1; i++){
        table[i] = 0;
    }
    for (int i = 1; i <= n+1; i++){
        for (int j = 0; j < i; j++){
            table[i] += table[j] * table[i-j-1];
        }
    }
    cout << table[n];


}