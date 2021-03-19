#include <bits/stdc++.h>
using namespace std;
vector <vector<int>> vect;
int main() {
    int x, y, res = 0, last;
    cin >> x;
    for (int i = 0; i < x; i++){
        vector <int> o;
        cin >> y;
        o.push_back(y);
        cin >> y;
        o.push_back(y);
        vect.push_back(o);
    }
    sort(vect.begin(), vect.end());
    res += vect[0][1] - vect[0][0];
    last = vect[0][1];
    for (int i = 1; i < x; i++){
        if (vect[i][0] >= last){
            res += vect[i][1] - vect[i][0];
            last = vect[i][1];
        }
        else if (vect[i][0] < last){
            if (vect[i][1] > last){
                res += vect[i][1] - last;
                last = vect[i][1];
            }
        }
    }
    cout << res;
}