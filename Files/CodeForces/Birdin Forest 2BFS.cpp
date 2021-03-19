    #include <bits/stdc++.h>
    using namespace std;
     
     
    const int N = 1005;
    char mat[N][N];
    int x, y;
    bool visited[N][N];
     
     
    int bfs(pair<int, int> s){
        queue<pair<int ,int>> q;
        q.push({s.first, s.second});
        int o = 0, v = 1, d = 1;
        while (!q.empty()){
            if (o == v){
                v = q.size();
                o = 0;
                d++;
            }
            pair<int, int> p = q.front();
            q.pop();
            o++;
            pair<int, int> pos [] = {{1, 0}, {-1, 0}, {0, 1},{0, -1}};
            for (auto el : pos){
                if (p.first + el.first >= x or p.first + el.first < 0 or p.second + el.second >= y or p.second + el.second < 0){
                    continue;
                }
                else if (mat[el.first+p.first][el.second + p.second] >= '0' and mat[el.first+p.first][el.second + p.second] <= '9' and !visited[el.first+p.first][el.second + p.second]){
                    visited[el.first+p.first][el.second + p.second] = true;
                    q.push({el.first+p.first, el.second + p.second});
                }
                else if(mat[el.first+p.first][el.second + p.second] == 'E'){
                    return d;
                }
            }
        }
    }
     
     
    int func(int m, pair<int, int> e){
        queue<pair<int ,int>> q;
        q.push({e.first, e.second});
        int o = 0, v = 1, d= 1, uw = 0;
        while (!q.empty()){
            if (o == v){
                v = q.size();
                o = 0;
                d++;
                if (d > m){
                    break;
                }
            }
            pair<int, int> p = q.front();
            q.pop();
            o++;
            pair<int, int> pos [] = {{1, 0}, {-1, 0}, {0, 1},{0, -1}};
            for (auto el : pos){
                if (p.first + el.first >= x or p.first + el.first < 0 or p.second + el.second >= y or p.second + el.second < 0){
                    continue;
                }
                else if (mat[el.first+p.first][el.second + p.second] >= '0' and mat[el.first+p.first][el.second + p.second] <= '9' and !visited[el.first+p.first][el.second + p.second]){
                    visited[el.first+p.first][el.second + p.second] = true;
                    q.push({el.first+p.first, el.second + p.second});
                    uw += mat[el.first+p.first][el.second + p.second] - '0';
    //                cout << mat[el.first+p.first][el.second + p.second] - '0' << endl;
                }
            }
        }
        return uw;
    }
     
     
     
     
    int main() {
        cin >> x >> y;
        pair<int, int> s, e;
        for (int i = 0; i < x; i++){
            for (int j = 0; j < y; j++){
                cin >> mat[i][j];
                if (mat[i][j] == 'E'){
                    e = {i,j};
                }
                if (mat[i][j] == 'S'){
                    s = {i, j};
                }
            }
        }
        int d = bfs(s);
        memset(visited, 0, sizeof(visited));
        cout << func(d, e);
     
    }