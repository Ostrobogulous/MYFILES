#include <iostream>
#include <map>
#include <cmath>
#include <string>
using namespace std;

long long int arr[100] = {0, 1, 1, 1, 1, 2};

int main() {
    int x;
    cin >> x;
    for (int i = 6; i <= x; i++) {
        arr[i] = arr[i - 1] + arr[i - 5];
    }
    cout << arr[x];
}


