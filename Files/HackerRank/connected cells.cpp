#include <bits/stdc++.h>
using namespace std;
const int N = 10;
#define pb push_back
#define F first
#define S second


bool visited[N][N];
int maxi = 0, n, m;
int arr[N][N];


int bfs(int i, int j){
    int o = 1;
    queue <pair<int, int>> q;
    q.push({i, j});
    visited[i][j] = true;
    while (!q.empty()){
        i = q.front().F; j = q.front().S;
        q.pop();
        if (arr[i+1][j] == 1 and !visited[i+1][j]){
            o++;
            visited[i+1][j] = true;
            q.push({i+1, j});
        }
        if (arr[i-1][j] == 1 and !visited[i-1][j]){
            o++;
            visited[i-1][j] = true;
            q.push({i-1, j});
        }
        if (arr[i+1][j+1] == 1 and !visited[i+1][j+1]){
            o++;
            visited[i+1][j+1] = true;
            q.push({i+1, j+1});
        }
        if (arr[i+1][j-1] == 1 and !visited[i+1][j-1]){
            o++;
            visited[i+1][j-1] = true;
            q.push({i+1, j-1});
        }
        if (arr[i-1][j+1] == 1 and !visited[i-1][j+1]){
            o++;
            visited[i-1][j+1] = true;
            q.push({i-1, j+1});
        }
        if (arr[i-1][j-1] == 1 and !visited[i-1][j-1]){
            o++;
            visited[i-1][j-1] = true;
            q.push({i-1, j-1});
        }
        if (arr[i][j+1] == 1 and !visited[i][j+1]){
            o++;
            visited[i][j+1] = true;
            q.push({i,j+1});
        }
        if (arr[i][j-1] == 1 and !visited[i][j-1]){
            o++;
            visited[i][j-1] = true;
            q.push({i, j-1});
        }
    }
    return o;
}




int check(){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (arr[i][j] == 1 and !visited[i][j]){
                int c = bfs(i, j);
                maxi = max(c, maxi);
            }
        }
    }
    return maxi;
}





int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> arr[i][j];
        }
    }
    cout << check();


}
