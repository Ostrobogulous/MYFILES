#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 6;

bool visited[N];
vector<int> adj[N];
int dist[N];
int w;



void bfs(){
    queue <int> q;
    q.push(w);
    visited[w] = true;
    int p = 1, o = 0, c = 1;
    while (!q.empty()){
        if (o == p){
            p = q.size();
            c++;
            o = 0;
        }
        int y = q.front();
        q.pop();
        o++;
        for (int i = 0; i < adj[y].size(); i++){
            if (!visited[adj[y][i]]){
                dist[adj[y][i]] = c;
                visited[adj[y][i]] = true;
                q.push(adj[y][i]);
            }
        }
    }
}


int main(){
    int n, m, a, b;
    cin >> n >> m;
    for (int i = 0; i < m; i++){
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    cin >> w;
    bfs();
    for (int i = 1; i <= n; i++){
        cout << i << " " << dist[i] << endl;
    }


}