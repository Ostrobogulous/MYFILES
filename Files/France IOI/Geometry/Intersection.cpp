#include <bits/stdc++.h>
using namespace std;
#define point pair<double, double>
class line{
public:
    double a, b, c;
};
class line cal(pair <double, double> P, pair <double, double> Q){
    line l;
    double aa = Q.second - P.second;
    double bb = P.first - Q.first;
    double cc = aa * (P.first) + bb * (P.second);
    l.a = aa;
    l.b = bb;
    l.c = cc;
    return l;
}
int main()
{
    double x, y,  rx, ry;
    pair <double, double> P, Q, A, B;
    cin >> x >> y;
    P.first = x;
    P.second = y;
    cin >> x >> y;
    Q.first = x;
    Q.second = y;
    line l1{}, l2{};
    l1 = cal(P, Q);
    cin >> x >> y;
    A.first = x;
    A.second = y;
    cin >> x >> y;
    B.first = x;
    B.second = y;
    l2 = cal(A, B);
    rx = ((l1.c * l2.b) - (l1.b * l2.c))/((l1.a * l2.b)-(l1.b * l2.a));
    ry = ((l1.a * l2.c) - (l1.c * l2.a)) / ((l1.a * l2.b) - (l1.b * l2.a));
    cout << setprecision(7);
    cout << rx << " " << ry;
}