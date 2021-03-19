#include <bits/stdc++.h>
using namespace std;
int const N = 1002;
int d[N];
int l[N];
int p = 2;
vector <int> g[N];
vector <pair<int, int>> opp;
bool visited[N];
int x, y;
void func(int el, int q){
    for (int i = 0; i < g[el].size(); i++){
        if (g[el][i] == q){
            continue;
        }
        if (visited[g[el][i]]){
            if (l[el] > d[g[el][i]]){
                l[el] = d[g[el][i]];
            }
            continue;
        }
        else{
            d[g[el][i]] = p; l[g[el][i]] = p;
            p++;
            visited[g[el][i]] = true;
            func(g[el][i], el);
        }
        if (l[g[el][i]] < l[el]) {
            l[el] = l[g[el][i]];
        }
        if (l[g[el][i]] > d[el]) {
            opp.emplace_back(el, g[el][i]);
        }
    }
}
int main(){
//    freopen("shell.in", "r", stdin);
//    freopen("shell.out", "w", stdout);
    int a, b;
    cin >> x >> y;
    for (int i = 0; i < x; i++){
        visited[i] = false;#include <bits/stdc++.h>
using namespace std;
int const N = 1002;
int d[N];
int l[N];
int p = 2;
vector <int> g[N];
vector <pair<int, int>> opp;
bool visited[N];
int x, y;
void func(int el, int q){
    for (int i = 0; i < g[el].size(); i++){
        if (g[el][i] == q){
            continue;
        }
        if (visited[g[el][i]]){
            if (l[el] > d[g[el][i]]){
                l[el] = d[g[el][i]];
            }
            continue;
        }
        else{
            d[g[el][i]] = p; l[g[el][i]] = p;
            p++;
            visited[g[el][i]] = true;
            func(g[el][i], el);
        }
        if (l[g[el][i]] < l[el]) {
            l[el] = l[g[el][i]];
        }
        if (l[g[el][i]] > d[el]) {
            opp.emplace_back(el, g[el][i]);
        }
    }
}
int main(){
//    freopen("shell.in", "r", stdin);
//    freopen("shell.out", "w", stdout);
    int a, b;
    cin >> x >> y;
    for (int i = 0; i < x; i++){
        visited[i] = false;
    }
    for (int i = 0; i < y; i++){
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    d[1] = 1; l[1] = 1;
    visited[1] = true;
    func(1, 1);
    cout << opp.size() << endl;
    sort(opp.begin(), opp.end());
    for (auto el : opp){
        cout << el.first << " " << el.second << endl;
    }
}
    }
    for (int i = 0; i < y; i++){
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    d[1] = 1; l[1] = 1;
    visited[1] = true;
    func(1, 1);
    cout << opp.size() << endl;
    sort(opp.begin(), opp.end());
    for (auto el : opp){
        cout << el.first << " " << el.second << endl;
    }
}