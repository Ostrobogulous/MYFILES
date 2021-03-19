#include <bits/stdc++.h>
using namespace std;



int main(){
    vector<vector<double>> v;
    double o, c, w, p, q;
    cin >> o >> c;
    for (double i = 0; i < o; i++){
        cin >> p >> w >> q;
        v.push_back(vector<double>{p / w, p, w, q});
    }
    sort(v.begin(), v.end());
    double i = 0;
    double win = 0;
    while (c > 0 or i < o){
        if (v[i][2] * v[i][3] <= c){
            c -= v[i][2] * v[i][3];
            win += v[i][1] * v[i][3];
        }
        else{
            win += (c / v[i][2]) * v[i][3];
            c = 0;
        }
        i++;
    }
    cout << win;
}