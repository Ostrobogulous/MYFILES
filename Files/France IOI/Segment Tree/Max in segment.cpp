#include <bits/stdc++.h>
using namespace std;



int  max_size(int n) {
    int x = (int)(ceil(log2(n)));
    int max_size = 2*(int)pow(2, x) - 1;
    return max_size;
}

const int N = max_size(100000);
vector<int> v(N);

int getMid(int s, int e) { return s + (e -s)/2; }


int constructSTUtil(int arr[], int ss, int se, int si)
{

    if (ss == se)
    {
        v[si] = arr[ss];
        return arr[ss];
    }


    int mid = getMid(ss, se);
    v[si] = max(constructSTUtil(arr, ss, mid, si*2+1),
            constructSTUtil(arr, mid+1, se, si*2+2));
    return v[si];
}








int getmaxUtil(int ss, int se, int qs, int qe, int si){

    if (qs <= ss && qe >= se)
        return v[si];

    if (se < qs || ss > qe)
        return 0;

    int mid = getMid(ss, se);
    return max(getmaxUtil(ss, mid, qs, qe, 2*si+1),
           getmaxUtil(mid+1, se, qs, qe, 2*si+2));
}


int getmax(int n, int qs, int qe)
{
    return getmaxUtil(0, n-1, qs, qe, 0);
}

const int M = 100004;
int arr[M];

int main(){

    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    constructSTUtil(arr, 0, n-1, 0);
    int k, a, b;
    cin >> k;
    for (int i = 0; i < k; i++){
        cin >> a>>b;
        a--; b--;
        cout << getmax(n, a, b) << endl;
    }

}