#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second


const int N = 10;
int n, m, o = 0, maxi = 0;
bool visited[N][N];
int arr[N][N];



void dfs(int i, int j){
    if (arr[i+1][j] == 1 and !visited[i+1][j]){
        o++;
        visited[i+1][j] = true;
        dfs(i+1, j);
    }
    if (arr[i-1][j] == 1 and !visited[i-1][j]){
        o++;
        visited[i-1][j] = true;
        dfs(i-1, j);
    }
    if (arr[i+1][j+1] == 1 and !visited[i+1][j+1]){
        o++;
        visited[i+1][j+1] = true;
        dfs(i+1, j+1);
    }
    if (arr[i+1][j-1] == 1 and !visited[i+1][j-1]){
        o++;
        visited[i+1][j-1] = true;
        dfs(i+1, j-1);
    }
    if (arr[i-1][j+1] == 1 and !visited[i-1][j+1]){
        o++;
        visited[i-1][j+1] = true;
        dfs(i-1, j+1);
    }
    if (arr[i-1][j-1] == 1 and !visited[i-1][j-1]){
        o++;
        visited[i-1][j-1] = true;
        dfs(i-1, j-1);
    }
    if (arr[i][j+1] == 1 and !visited[i][j+1]){
        o++;
        visited[i][j+1] = true;
        dfs(i, j+1);
    }
    if (arr[i][j-1] == 1 and !visited[i][j-1]){
        o++;
        visited[i][j-1] = true;
        dfs(i, j-1);
    }
}



void count(){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (arr[i][j] == 1 and !visited[i][j]){

                visited[i][j] = true;
                o = 1;
                dfs(i, j);
                maxi = max(o, maxi);
            }
        }
    }
}






int main(){
    cin >> n >> m;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> arr[i][j];
            visited[i][j] = false;
        }
    }
    count();
    cout << maxi;


}