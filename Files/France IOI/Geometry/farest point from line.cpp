#include <bits/stdc++.h>
using namespace std;
typedef long double C;
typedef complex<C> P;
#define X real()
#define Y imag()
double distance(double x1,double x2,double y1,double y2){
    return sqrt(pow(x1-x2,2)+pow(y1-y2,2));
}
double triangle(double dist1,double dist2,double dist3){
    double o, a;
    o = 0.5 * (dist1 + dist2 + dist3);
    a = sqrt(o * (o - dist1) * (o - dist2) * (o - dist3));
    return a;
}
int main() {
    double  a1, a2, b1, b2, x, y, n, dist1, dist2, dist3, m, h, maxi = 0, po1, po2;
    cin >> a1 >> a2 >> b1 >> b2;
    dist1 = distance(a1, b1, a2, b2);
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> x >> y;
        dist2 = distance(b1, x, b2, y);
        dist3 = distance(a1, x, a2, y);
        m = triangle(dist1, dist2, dist3);
        h = (m / (0.5 * dist1));
        if (h > maxi){
            maxi = h;
            po1 = x;
            po2= y;
        }
    }
    cout << po1 << " " << po2;
}