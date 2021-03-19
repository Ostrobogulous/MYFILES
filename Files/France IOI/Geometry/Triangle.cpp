#include <bits/stdc++.h>
using namespace std;
double cal(double a1,double a2,double b1,double b2){
    return sqrt(pow(a1-a2,2)+pow(b1-b2, 2));
}
int main(){
    double x1, x2, x3, y1, y2, y3, dist1, dist2, dist3, p, s;
    cin >> x1 >> y1;
    cin >> x2 >> y2;
    cin >> x3 >> y3;
    dist1  = cal(x1, x2, y1, y2);
    dist2 = cal(x1, x3, y1, y3);
    dist3 = cal(x2, x3, y2, y3);
    p = (dist1 + dist2 + dist3) * 0.5;
    s = sqrt(p * (p - dist1) * (p - dist2) * (p - dist3));
    cout << (int)(s*2 + 0.5);
}