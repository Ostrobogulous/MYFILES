    #include <bits/stdc++.h>
    using namespace std;
     
    int main() {
        ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
        long long t;
        cin >> t;
        for (long long i = 0; i < t; i++){
            long long a, num;
            cin >> a;
            priority_queue <long long> v1;
            priority_queue <long long> v2;
            for (long long j = 0; j < a; j++){
                cin >> num;
                if (num % 2 == 0){
                    v1.push(num);
                }
                else{
                    v2.push(num);
                }
            }
            long long o = 0;
            long long s1 = 0, s2 = 0;
            while (!v1.empty() or !v2.empty()){
                if (v1.empty()){
                    if (o % 2 == 0){
                        v2.pop();
                    }
                    else{
                        s2 += v2.top();
                        v2.pop();
                    }
                }
                else if (v2.empty()){
                    if (o % 2 == 0){
                        s1 += v1.top();
                        v1.pop();
                    }
                    else{
                        v1.pop();
                    }
                }
                else{
                    if (o % 2 == 0){
                        if (v1.top() >= v2.top()){
                            s1 += v1.top();
                            v1.pop();
                        }
                        else{
                            v2.pop();
                        }
                    }
                    else{
                        if (v1.top() > v2.top()){
                            v1.pop();
                        }
                        else{
                            s2 += v2.top();
                            v2.pop();
                        }
                    }
                }
                o++;
            }
            if (s1 == s2){
                cout << "Tie" << endl;
            }
            else if (s1 > s2){
                cout << "Alice" << endl;
            }
            else{
                cout << "Bob" << endl;
            }
     
     
        }
    }