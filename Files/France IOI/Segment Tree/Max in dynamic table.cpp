include <bits/stdc++.h>
using namespace std;
int  max_size(int n) {
    int x = (int)(ceil(log2(n)));
    int max_size = 2*(int)pow(2, x) - 1;
    return max_size;
}
const int N = max_size(132000);
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
void updatevalue(int arr[], int ss, int se, int i, int new_val, int si){
    if (ss == se){
        arr[i] = new_val;
        v[si] = new_val;
    }
    else{
        int mid = getMid(ss, se);
        if (i >= ss and i <= mid){
            updatevalue(arr,ss, mid, i, new_val, 2 * si + 1);
        }
        else{
            updatevalue(arr, mid + 1, se, i , new_val, 2 * si + 2);
        }
        v[si] = max(v[si*2+1], v[si*2+2]);
    }
    return;
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
const int M = 132000;
int arr[M];
int main(){
    int n;
    cin >> n;
    n = pow(2, n);
    constructSTUtil(arr, 0, n - 1, 0);
    int k, a, b;
    cin >> k;
    for (int i = 0; i < k; i++){
        cin >> a >> b;
        updatevalue(arr, 0, n- 1,a, b, 0);
        cout << getmax(n, 0, n) << endl;
    }
}