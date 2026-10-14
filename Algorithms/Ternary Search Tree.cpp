#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define all(x) x.begin(), x.end()
#define fi first
#define se second
#define inf 1000000000
#define NIL -1;
#define sz(x) (ll)x.size()
#define boost() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef vector<int> vi;
typedef vector<float> vf;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<int, bool> pib;
typedef vector<pii> vii;
typedef vector<pib> vib;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
typedef vector<string> vs;
typedef pair<string, string> pss;
typedef pair<ll, ll> pll;
typedef vector<pss> vss;
typedef pair<db, db> pdd;
typedef vector<db> vd;
typedef vector<vib> vvib;

//  https://dmoj.ca/problem/ternarysearchtree

int n, v;

class Node {
    int value = 0;

    public:
        Node(int newValue) : value(newValue) {}

        Node* children[3] = {nullptr, nullptr, nullptr};

        int getValue() const {
            return value;
        };

        void setValue(int newValue){
            value = newValue;
        };
};


class Tree {
    Node* Root = nullptr;

    public:
        void addNode(Node* newNode){
            if (!newNode) {
                return;
            }

            if (!Root) {
                Root = newNode;
                return;
            }

            int childIndex;
            if (newNode->getValue() < Root->getValue()) {
                childIndex = 0;
            } else if (newNode->getValue() == Root->getValue()) {
                childIndex = 1;
            } else {
                childIndex = 2;
            }

            if (!Root->children[childIndex]) {
                Root->children[childIndex] = newNode;
                cout << Root->getValue() << endl;
            } else {
                addNodeAt(Root->children[childIndex], newNode);
            }
        };

    private:
        void addNodeAt(Node* current, Node* newNode) {
            int childIndex;
            if (newNode->getValue() < current->getValue()) {
                childIndex = 0;
            } else if (newNode->getValue() == current->getValue()) {
                childIndex = 1;
            } else {
                childIndex = 2;
            }

            if (!current->children[childIndex]) {
                current->children[childIndex] = newNode;
                cout << current->getValue() << endl;
            } else {
                addNodeAt(current->children[childIndex], newNode);
            }
        }
};

int main(){
    cin >> n;

    Tree tree;

    while(n--){
        cin >> v;
        Node* node = new Node(v);
        tree.addNode(node);
    }
    
    return 0;
}
