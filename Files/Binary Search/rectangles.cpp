#include <bits/stdc++.h>
using namespace std;

// Rectangles: n rectangles of the same size w width and h length, it is required to find the smallest size into which these rectangle can be packed, rectangles cannot be rotated.

bool check(long long num, long long  w, long long  h, long long  n){
    return (num / w) * (num / h) >= n;
}


int main() {
    long long w, h, n;
    cin >> w >> h >> n;
    long long  l = 0;
    long long  r = 1;
    while (!check(r, w, h, n)){
        r *= 2;
    }
     while (r > l + 1){
       long long  mid = (l+r) / 2;
       if (check(mid, w, h, n)){
           r  = mid;
       }
       else{
           l = mid;
       }
   }
   cout << r;
}