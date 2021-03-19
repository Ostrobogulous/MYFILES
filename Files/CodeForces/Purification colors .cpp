    #include <bits/stdc++.h>
    using namespace std;
     
    const int N = 101;
    char mat[N][N];
     
     
     
     
    int main() {
        int x;
        cin >> x;
        for (int i = 0; i < x; i++){
            cin >> mat[i];
        }
        vector<pair<int,int>> v;
        for (int i = 0; i < x; i++){
            for (int j = 0; j < x; j++){
                if (mat[i][j] == '.'){
                    v.emplace_back(i, j);
                    break;
                }
            }
        }
        if (v.size() < x){
            v.clear();
            for (int j = 0; j < x; j++){
                for (int i = 0; i < x; i++){
                    if (mat[i][j] == '.'){
                        v.emplace_back(i, j);
                        break;
                    }
                }
            }
        }
        if (v.size() < x){
            cout << -1;
            return 0;
        }
        for (auto el : v){
            cout << el.first + 1 << " " << el.second + 1 << endl;
        }
     
    }