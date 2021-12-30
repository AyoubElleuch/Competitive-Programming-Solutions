#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define all(x) x.begin(), x.end()
#define fi first
#define se second
#define inf 1000000000
#define EPSILON (pow(2, -203))
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
typedef set<string> sstr;

int min(int a, int b){
    return a<b?a:b;
}
int max(int a, int b){
    return a>b?a:b;
}

class position{
    public:
        int x;
        int y;
};

bool visited[9][9];

bool inBounds(int x, int y, bool visited[9][9]){
    if(x >= 1 && x <= 8 && y >= 1 && y <= 8){
        if(!visited[x][y]){
            return true;
        }
    }
    return false;
}

position exploreBoard(int x,  int y, bool visited[9][9]){
    visited[x][y] = true;
    position newPosition;
    newPosition.x = x;
    newPosition.y = y;
    return newPosition;  
} 

int main(){
    boost();
    position start, end;
    cin >> start.x >> start.y >> end.x >> end.y;
    vector<position> bfs;
    vector<position> newNode;
    bfs.pb(start);
    visited[start.x][start.y] = true;
    int counter = 0;
    while(bfs.size()){
        newNode.clear();
        for (position eachPosition : bfs){
            if(eachPosition.x == end.x && eachPosition.y == end.y){
                cout << counter << endl;
                return 0;
            }else{
                int x1 = eachPosition.x;
                int y1 = eachPosition.y;
                if(inBounds(x1 + 1, y1 + 2, visited)) newNode.pb(exploreBoard(x1 + 1, y1 + 2, visited));
                if(inBounds(x1 + 1, y1 - 2, visited)) newNode.pb(exploreBoard(x1 + 1, y1 - 2, visited));
                if(inBounds(x1 + 2, y1 + 1, visited)) newNode.pb(exploreBoard(x1 + 2, y1 + 1, visited));
                if(inBounds(x1 + 2, y1 - 1, visited)) newNode.pb(exploreBoard(x1 + 2, y1 - 1, visited));
                if(inBounds(x1 - 1, y1 + 2, visited)) newNode.pb(exploreBoard(x1 - 1, y1 + 2, visited));
                if(inBounds(x1 - 1, y1 - 2, visited)) newNode.pb(exploreBoard(x1 - 1, y1 - 2, visited));
                if(inBounds(x1 - 2, y1 + 1, visited)) newNode.pb(exploreBoard(x1 - 2, y1 + 1, visited));
                if(inBounds(x1 - 2, y1 - 1, visited)) newNode.pb(exploreBoard(x1 - 2, y1 - 1, visited));
            }
        }
        bfs = newNode;
        counter++;
    }
    cout << counter;
    return 0;
}
// LONG LONG
