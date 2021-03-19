#include <bits/stdc++.h>
using namespace std;
bool special_sort(const vector<int> &a, const vector<int> &b){
    return (a[2] < b[2]);
}
vector <vector<int>> vect;
int main(){
    int n, y, s, e;
    bool t;
    cin >> n >> y;
    int arr[n][2];
    for (int i = 0; i < n; i++){
        arr[i][0] = 0;
        arr[i][1] = 0;
    }
    for (int i = 0; i < y; i++){
        vector <int> o;
        cin >> s >> e;
        o.push_back(s); o.push_back(e); o.push_back(i);
        vect.push_back(o);
    }
    sort(vect.begin(), vect.end());
    for (int i = 0; i < y; i++){
        t = true;
        for (int j = 0; j < n; j++){
            if (vect[i][0] >= arr[j][1]){
                arr[j][0] = vect[i][0];
                arr[j][1] = vect[i][1];
                vect[i].push_back(j+1);
                t = false;
                break;
            }
        }
        if (t){
            cout << "NON";
            return 0;
        }
    }
    sort(vect.begin(),vect.end(), special_sort);
    cout << "OUI" << endl;
    for (int i = 0; i < y - 1; i++){
        cout << vect[i][3] << " ";
    }
    cout << vect[y-1][3];
}