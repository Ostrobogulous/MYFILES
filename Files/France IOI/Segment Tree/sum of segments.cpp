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
    v[si] = constructSTUtil(arr, ss, mid, si*2+1)+
            constructSTUtil(arr, mid+1, se, si*2+2);
    return v[si];
}
void updateValueUtil(int ss, int se, int i, int diff, int si)
{
    // Base Case: If the input index lies outside the range of
    // this segment
    if (i < ss || i > se)
        return;
    // If the input index is in range of this node, then update
    // the value of the node and its children
    v[si] = v[si] + diff;
    if (se != ss)
    {
        int mid = getMid(ss, se);
        updateValueUtil(ss, mid, i, diff, 2*si + 1);
        updateValueUtil(mid+1, se, i, diff, 2*si + 2);
    }
}
void updateValue(int arr[], int n, int i, int new_val)
{
    if (i < 0 || i > n-1)
    {
        cout<<"Invalid Input";
        return;
    }
    int diff = new_val - arr[i];
    arr[i] = new_val;
    
    updateValueUtil(0, n-1, i, diff, 0);
}
int getsumUtil(int ss, int se, int qs, int qe, int si){
    if (qs <= ss && qe >= se)
        return v[si];
    if (se < qs || ss > qe)
        return 0;
    int mid = getMid(ss, se);
    return getsumUtil(ss, mid, qs, qe, 2*si+1)+
           getsumUtil(mid+1, se, qs, qe, 2*si+2);
}
int getsum(int n, int qs, int qe)
{
    return getsumUtil(0, n-1, qs, qe, 0);
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
    char c;
    cin >> k;
    for (int i = 0; i < k; i++){
        cin >> c >> a >> b;
        if (c == 'S'){
            cout << getsum(n, a, b) << endl;
        }
        else{
            updateValue(arr, n, a, b);
        }
    }
}