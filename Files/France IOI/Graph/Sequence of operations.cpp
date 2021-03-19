#include <bits/stdc++.h>
using namespace std;
const int N = 100001;
bool visited[N];
int main(){
    int o1, o2, o3, o4;
    cin >> o1 >> o2 >> o3 >> o4;
    int num, des;
    cin >> num >> des;
    queue <int> q;
    q.push(num);
    for (bool &i : visited){
        i = false;
    }
    visited[num] = true;
    while (!q.empty()){
        num = q.front();
        q.pop();
        if (num == des){
            break;
        }
        if (num + o1 < N and !visited[num+o1]){
            visited[num+o1] = true;
            q.push(num+o1);
        }
        if (num - o2 > 0 and !visited[num-o2]){
            visited[num-o2] = true;
            q.push(num-o2);
        }
        if (num * o3 < N and !visited[num*o3]){
            visited[num*o3] = true;
            q.push(num*o3);
        }
        if (o4 != 0){
            if (!visited[num/o4] and num % o4 == 0) {
                visited[num / o4] = true;
                q.push(num / o4);
            }
        }
    }
    cout << visited[des];
}