#include <iostream>
#include <string>
#include <cmath>
using namespace std;



int main() {
    string x, ch, y, m, name;
    bool p;
    int n;
    ch = "";
    cin >> x;
    for (int i = 0; i < x.length(); i++){
        ch += tolower(x[i]);
    }
    cin >> n;
    for (int i = 0; i <= n; i++){
        m = "";
        getline(cin, y);
        p = true;
        name = "";
        for (int j = 0; j < y.length(); j++){
            if (y[j] == ' '){
                p = true;
                name += " ";
                continue;
            }
            if (p){
                name += toupper(y[j]);
                m += tolower(y[j]);
                p = false;
                continue;
            }
            name += tolower(y[j]);
        }
        if (m == ch){
            cout << name << endl;
        }
    }
}