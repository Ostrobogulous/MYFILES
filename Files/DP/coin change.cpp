#include <iostream>
using namespace std;



int main(){
    int n, y;
    cin >> n >> y;
    int coins[y];
    int table[y+1][n+1];
    for (int i = 1; i <= n; i++){
        table[0][i] = 0;
    }

    for (int i = 1; i < y + 1; i++){
        table[i][0] = 1;
        cin >> coins[i-1];
    }
    for (int i = 1; i <= y; i++){
        for (int j = 1; j <= n; j++){
            if (j - coins[i-1] >= 0){
                table[i][j] = table[i][j - coins[i-1]] + table[i-1][j];
            }
            else{
                table[i][j] = table[i-1][j];
            }
        }
    }
    cout << table[y][n];



}