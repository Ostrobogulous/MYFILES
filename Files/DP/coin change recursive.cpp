#include <iostream>
using namespace std;

int ways(int n, int coins[], int y){
    if (n == 0){
        return 1;
    }
    if (n < 0){
        return 0;
    }
    if (y < 0){
        return 0;
    }
    return ways(n - coins[y], coins, y) + ways(n, coins, y - 1);
}


int main(){
    int n, y, c;
    cin >> n >> y;
    int coins[y];
    for (int i = 0; i < y; i++){
        cin >> c;
        coins[i] = c;
    }
    cout << ways(n, coins, y - 1);

}