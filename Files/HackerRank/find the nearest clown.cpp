#include <bits/stdc++.h>
using namespace std;
const int N = 100000000;
#define pb push_back
#define F first
#define S second


bool visited[N];
int mini = 999999999, x;
map<int, pair<vector<int>,int>> m;



int bfs(int i, int c){
    int p = 0;
    queue <int> q;
    q.push(i);
    visited[i] = true;
    while(!q.empty()){
        i = q.front();
        q.pop();
        for (auto el : m[i].F){
            if (visited[el]){
                continue;
            }
            else if(m[el].S == c){
                return p;
            }
            else{
                p++;
                visited[el] = true;
                q.push(el);
            }
        }
    }
    return -1;
}




void find(int num){
    for (int i = 1; i <= x; i++){
        if (m[i].S == num){
            int c = bfs(i, num);
            if (c == -1){
                continue;
            }
            mini = min(c, mini);
        }
    }
    if (mini == 999999999){
        cout << -1;
        return;
    }
    cout << mini;
}




int main() {
    int n, a, b, color;
    cin >> x >> n;
    for (int i = 0; i < x; i++){
        pair<vector<int>, int> p;
        m[i+1] = p;
        visited[i+1] = false;
    }
    for (int i = 0; i < n; i++){
        cin >> a >> b;
        m[a].F.pb(b);
        m[b].F.pb(a);
    }
    for (int i = 0; i < x; i++){
        cin >> color;
        m[i+1].S = color;
    }
    cin >> color;
    find(color);

}