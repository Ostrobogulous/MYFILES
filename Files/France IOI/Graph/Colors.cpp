#include <bits/stdc++.h>
using namespace std;
const int N = 32;
char g[N][N];
set<pair<pair<int,int>,pair<int,int>>> s;
int a, b;
vector<pair<int,int>> v = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
bool m = false;
void func(int p1, int p2, int o1, int o2){
    if (p1 == a - 1 and p2 == b - 1 and o1 == 0 and o2 == 0){
        m = true;
        return;
    }
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
            int a1 = p1 + v[i].first, a2 = p2 + v[i].second, b1 = o1 + v[j].first, b2 = o2 + v[j].second;
            if (a1 >= 0 and a2 >= 0 and b1 >= 0 and b2 >= 0 and a1 < a and a2 < b and b1 < a and b2 < b and s.count({{a1,a2},{b1,b2}}) == 0 and g[a1][a2] == g[b1][b2]){
                s.insert({{a1,a2},{b1,b2}});
                func(a1, a2, b1, b2);
            }
        }
    }
}
int main(){
    cin >> b >> a;
    for (int i = 0; i < a; i++){
        cin >> g[i];
    }
    func(0, 0, a - 1, b - 1);
    if (m){
        cout << 1;
    }
    else{
        cout << 0;
    }
}