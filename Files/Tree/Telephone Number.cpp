#include <bits/stdc++.h>
using namespace std;


vector <string> v;
vector <string> ve;


class Node {
public:
    string name;
    char value;
    vector<Node> connections;

    Node(string name, char value) {
        this->name = name;
        this->value = value;
    }

    void add_connection(string phone_number, string name, int p) {
        if (p >= phone_number.length()){
            this->name = name;
            return;
        }
        for (auto &number : connections) {
            if (number.value == phone_number[p]) {
                cout << -1 << endl;
                p++;
                number.add_connection(phone_number, name, p);
                return;
            }
        }
        Node new_node("x", phone_number[p]);
        p++;
        new_node.add_connection(phone_number, name, p);
        connections.push_back(new_node);
        return;
    }
    int count_elements(){
    int count = 0;
    for (auto el : connections){
        count += 1;
        count += el.count_elements();
    }
    return count;
}
    void get_numbers(string p) {
        p += value;
        if (connections.empty()) {
            v.push_back(p);
            return;
        }
        for (auto &el : connections) {
            el.get_numbers(p);
        }
    }
    void auto_complete(string num, string p, int o){
        if (connections.empty()) {
            ve.push_back(p);
            return;
        }
        for (auto &el : connections){
            if (o < num.size()){
                if (el.value == num[o]){
                    string s;
                    s = p +  el.value;
                    int x = o + 1;
                    el.auto_complete(num, s, x);
                }
            }
            else{
                string a;
                a = p + el.value;
                el.auto_complete(num, a, o);
            }
        }
    }

};



int main(){
    Node node("a", 'a');
    node.add_connection("1257", "iyed", 0);
    node.add_connection("1178", "iy", 0);
    node.add_connection("1279", "ihy", 0);
    node.add_connection("2257", "mohamed", 0);
    for (auto el : node.connections){
        cout << el.connections.size() << endl;
    }
    cout << node.count_elements() << endl;
    node.get_numbers("");
    for (auto el : v){
        cout << el << endl;
    }
    node.auto_complete("1", "", 0);
    for (auto el : ve){
        cout << el << endl;
    }

}
