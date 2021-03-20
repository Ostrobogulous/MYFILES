#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 6;
vector <pair<int, int>> g[N];
int dist[N];
bool visited[N];
int n, m;
int previous[N];

void dijkstra(int o){
    pair<int, int> p;
    multiset<pair<int, int>> q;
    dist[o] = 0;
    q.insert({0, o});
    while (!q.empty()){
        p = *q.begin();
        q.erase(q.begin());
        if (visited[p.second]){
            continue;
        }
        visited[p.second] = true;
        for (int i = 0; i < g[p.second].size(); i++){
            if (dist[g[p.second][i].first] > dist[p.second] + g[p.second][i].second and !visited[g[p.second][i].first]){
                dist[g[p.second][i].first] = dist[p.second] + g[p.second][i].second;
                previous[g[p.second][i].first] = p.second;
                q.insert({dist[g[p.second][i].first], g[p.second][i].first});
            }
        }
    }
}

int main(){
    int a, b, w;
    for (int & i : dist){
        i = INT_MAX;
    }
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> w;
        g[a].emplace_back(b, w);
        g[b].emplace_back(a, w);
    }
    dijkstra(1);
    previous[1] = 1;
    vector<int> v;
    int i = n;
    if (previous[i] == 0){
        cout << -1 << endl;
        return 0;
    }
    while(previous[i] != 1){
        v.push_back(previous[i]);
        i = previous[i];
    }
    reverse(v.begin(), v.end());
    cout << 1 << " ";
    for (auto el : v){
        cout << el << " ";
    }
    cout << n;
}