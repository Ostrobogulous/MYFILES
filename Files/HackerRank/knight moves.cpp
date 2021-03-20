#include <bits/stdc++.h>
using namespace std;


const int N = 27;
int dp[N][N];
bool visited[N][N];

int main() {
    int n;
    cin >> n;
    for (int i = 1; i < n; i++){
        for (int j = 1; j < n; j++){
            int o1 = min(i, j), o2 = max(i, j);
            if (dp[o1][o2] != 0){
                cout << dp[o1][o2] << " ";
                continue;
            }
            memset(visited, 0, sizeof(visited));
            queue <pair<int,int>> q;
            q.push({0, 0});
            bool f = false;
            int y = 1, o = 0, d = 1;
            while (!q.empty()){
                if (o == y){
                    y = q.size();
                    o = 0;
                    d++;
                }
                pair<int, int> p = q.front();
                q.pop();
                pair<int, int> pos[] = {{p.first + i, p.second + j}, {p.first + i, p.second - j}, {p.first - i, p.second + j}, {p.first - i, p.second - j},
                                        {p.first + j, p.second + i}, {p.first + j, p.second - i}, {p.first -j, p.second + i}, {p.first - j, p.second - i}
                };
                o++;
                for (auto el : pos){
                    if (el.first < 0 or el.second < 0 or el.first >= n or el.second >= n){
                        continue;
                    }
                    else if(el.first == n - 1 and el.second == n-1){
                        f = true;
                        while (!q.empty()){
                            q.pop();
                        }
                        break;
                    }
                    else if(!visited[el.first][el.second]){
                        visited[el.first][el.second] = true;
                        q.push({el.first, el.second});
                    }
                }
            }
            if (f){
                cout << d << " ";
                dp[o1][o2] = d;
            }
            else{
                cout << -1 << " ";
                dp[o1][o2] = -1;
            }
        }
        cout << endl;
    }
}