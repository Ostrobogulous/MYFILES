#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second


const int N = 10;
int n, m, o, maxi = 0;
bool visited[N][N];
int arr[N][N];


pair <int,int> u[8] = {{1,0}, {-1,0}, {0,1}, {0,-1},{1,1},{-1,-1},{-1,1},{1,-1}};

void dfs(int i, int j) {
    for (int k = 0; k < 8; k++) {
        if (arr[i + u[k].F][j + u[k].S] == 1 and !visited[i + u[k].F][j + u[k].S]) {
            visited[i + u[k].F][j + u[k].S] = true;
            o++;
            dfs(i + u[k].F, j + u[k].S);
        }
    }
}



    void count(){
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                if (arr[i][j] == 1 and !visited[i][j]){
                    o = 0;
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