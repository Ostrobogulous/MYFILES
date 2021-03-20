#include <bits/stdc++.h>
using namespace std;





int main(){
    int n, k;
    cin >> n >> k;
    int a, b;
    cin >> a >> b;
    int p1 = a, p2 = b;
    unordered_set<string> w;
    for (int i = 0; i < k; i++){
        cin >> a >> b;
        stringstream ss1, ss2;
        string s1, s2;
        ss1 << a, ss2 << b;
        ss1 >> s1, ss2 >> s2;
        string s = s1 + '+' + s2;
        w.insert(s);
    }
    int count = 0;

    // up
    for (int i = p1 + 1; i <= n; i++){
         stringstream yy1, yy2;
         string y1, y2;
         yy1 << i, yy2 << p2;
         yy1 >> y1, yy2 >> y2;
         string y = y1 + '+' + y2;
         if (w.count(y) == 1){
             break;
         }
         else{
             count++;
         }
    }

    // down
    for (int i = p1 - 1; i > 0; i--){
        stringstream yy1, yy2;
        string y1, y2;
        yy1 << i, yy2 << p2;
        yy1 >> y1, yy2 >> y2;
        string y = y1 + '+' + y2;
        if (w.count(y) == 1){
            break;
        }
        else{
            count++;
        }
    }

    // right
    for (int i = p2 + 1; i <= n; i++){
        stringstream yy1, yy2;
        string y1, y2;
        yy1 << p1, yy2 << i;
        yy1 >> y1, yy2 >> y2;
        string y = y1 + '+' + y2;
        if (w.count(y) == 1){
            break;
        }
        else{
            count++;
        }
    }


    // left
    for (int i = p2 -1; i > 0; i--){
        stringstream yy1, yy2;
        string y1, y2;
        yy1 << p1, yy2 << i;
        yy1 >> y1, yy2 >> y2;
        string y = y1 + '+' + y2;
        if (w.count(y) == 1){
            break;
        }
        else{
            count++;
        }
    }
    int j = p2 + 1;

    // up right
    for (int i = p1 + 1; i <= n; i++){
        if (j > n){
            break;
        }
        stringstream yy1, yy2;
        string y1, y2;
        yy1 << i, yy2 << j;
        yy1 >> y1, yy2 >> y2;
        string y = y1 + '+' + y2;
        if (w.count(y) == 1){
            break;
        }
        else{
            j++;
            count++;
        }
    }
    j = p2 - 1;

    // up left
    for (int i = p1 + 1; i <= n; i++){
        if (j <= 0){
            break;
        }
        stringstream yy1, yy2;
        string y1, y2;
        yy1 << i, yy2 << j;
        yy1 >> y1, yy2 >> y2;
        string y = y1 + '+' + y2;
        if (w.count(y) == 1){
            break;
        }
        else{
            j--;
            count++;
        }
    }
    j = p2 - 1;

    // down left
    for (int i = p1 - 1; i > 0; i--){
        if (j <= 0){
            break;
        }
        stringstream yy1, yy2;
        string y1, y2;
        yy1 << i, yy2 << j;
        yy1 >> y1, yy2 >> y2;
        string y = y1 + '+' + y2;
        if (w.count(y) == 1){
            break;
        }
        else{
            j--;
            count++;
        }
    }

    //down right
    j = p2 + 1;
    for (int i = p1 - 1; i > 0; i--){
        if (j > n){
            break;
        }
        stringstream yy1, yy2;
        string y1, y2;
        yy1 << i, yy2 << j;
        yy1 >> y1, yy2 >> y2;
        string y = y1 + '+' + y2;
        if (w.count(y) == 1){
            break;
        }
        else{
            j++;
            count++;
        }
    }
    cout << count;
}