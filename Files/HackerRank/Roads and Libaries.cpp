#include <bits/stdc++.h>
using namespace std;
const int N = 1000000;
#define pb push_back


bool visited[N];
void bfs(vector<int> arr[], int i){
    queue <int> q;
    q.push(i);
    visited[i] = true;
    while (!q.empty()){
        i = q.front();
        q.pop();
        for (int & el : arr[i]){
            if (visited[el]){
                continue;
            }
            visited[el] = true;
            q.push(el);
        }
    }
}


int count(vector <int> arr[], int n){
    int c = 0;
    for (int i = 0; i < n; i++){
        if (visited[i]){
            continue;
        }
        c++;
        bfs(arr, i);
    }
    return c;
}


int main(){
    int x, n, m, l, r, a, b;
    cin >> x;
    while (x){
        x--;
        cin >> n >> m >> l >> r;
        int j = m;
        vector<int> arr[n];
        for (int i = 0; i < n; i++){
            visited[i] = false;
        }
        while (j){
            j--;
            cin >> a >> b;
            arr[a-1].pb(b-1);
            arr[b-1].pb(a-1);
        }
        if (l < r){
            cout << l * n << endl;
            continue;
        }
        int o = count(arr, n);
        cout << r  * (n - o) + (o * l) << endl;
    }
}