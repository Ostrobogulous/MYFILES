#include <bits/stdc++.h>
using namespace std;
int main(){
    int y, n, s, e, maxi = 0, o = 0, res;
    vector <pair<int,int>> v;
    cin >> y >> n;
    for (int i = 0; i < n; i++){
        cin >> s >> e;
        if ( s <= e){
            v.emplace_back(s, e);
            o++;
        }
        else{
            v.emplace_back(0, e);
            v.emplace_back(s, y);
            o += 2;
        }
    }
    sort(v.begin(), v.end());
    if (v[0].first > maxi){
        maxi = v[0].first;
    }
    for (int i = 0; i < o - 1; i++){
        res = v[i+1].first - v[i].second;
        if (res > maxi){
            maxi = res;
        }
        else if(res < 0){
            if (v[i+1].second < v[i].second){
                v[i+1].second = v[i].second;
            }
        }
    }
    if (y + v[0].first - v[o-1].second > maxi){
        maxi = y+ v[0].first - v[o-1].second;
    }
    cout << maxi;
};