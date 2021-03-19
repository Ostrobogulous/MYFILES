#include <bits/stdc++.h>
using namespace std;
struct rect{
    int x1, y1, x2, y2;
    int area(){
        return (x2 - x1) * (y2 - y1);
    }
};
int intersect(rect p, rect q){
    int xOv = max(0, min(p.x2, q.x2) - max(p.x1, q.x1));
    int yOv = max(0, min(p.y2, q.y2) - max(p.y1, q.y1));
    return yOv * xOv;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n, area;
    rect a, b;
    cin >> a.x1 >> a.y1 >> a.x2 >> a.y2;
    area = a.area();
    cin >> n;
    for (int i = 0; i < n ;i++){
        cin >> b.x1 >> b.y1 >> b.x2 >> b.y2;
        area -= intersect(a, b);
    }
    cout << area;
}