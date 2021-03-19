#include <iostream>
#include <string>
#include <cmath>
using namespace std;



int main() {
    string enc, line, res;
    int y;
    getline(cin, enc);
    getline(cin, line);
    y = line.length();
    for (int i = 0; i < y; i++){
        if (isalpha(line[i])){
            if (isupper(line[i])){
                res += toupper(enc[(int)tolower(line[i]) - 97]);
            }
            else{
                res += enc[(int)tolower(line[i]) - 97];
            }
        }
        else{
            res += line[i];
        }
    }
    cout << res;


}