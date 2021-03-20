#include <bits/stdc++.h>
using namespace std;

vector <string> vect;
class Node{
public:
    char ch;
    int value = 0;
    vector<Node> connections;

    Node(char ch){
        this->ch = ch;
    }
    void add_connection(string word, int p = 0){
        value++;
        if (p >= word.length()){
            return;
        }
        for (auto &c : connections){
            if (c.ch == word[p]){
                p++;
                c.add_connection(word, p);
                return;
            }
        }
        Node new_node(word[p]);
        p++;
        new_node.add_connection(word, p);
        connections.push_back(new_node);
        return;
    }
    void prefix(string pr) {
        if (ch != '1')pr += ch;

        if ((connections.size() == 1 or connections.size() == 0) and value == 1) {
            vect.push_back(pr);
            return;
        }
        for (auto &el : connections) {
            el.prefix(pr);
        }

    }




};

int main(){
    string arr[] =  {"zebra", "dog", "duck", "dove"};
    Node node('1');
    for(auto el : arr){
        node.add_connection(el);
    }
    node.prefix("");
    for (auto el : vect){
        cout << el << endl;
    }
}