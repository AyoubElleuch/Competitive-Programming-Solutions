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

// Link to problem: https://dmoj.ca/problem/tle17c3p3

ull min(ull a, ull b){
    if(a<b) return a;
    else return b;
}

int n, m, t, ni;
int items[300001];
ull visited[300001];
vvi adj(300001);

int main(){
    ull ans = 1e19;
    cin >> n >> m;
    for(int i=0; i<m; i++){
        cin >> t >> ni;
        while(ni--){
            int tmp; cin >> tmp;
            adj[t].pb(tmp);
        }
    }
    for(int i=1; i<=n; i++){ 
        cin >> items[i]; 
    }
    if(adj[1].empty()){cout << items[1]; return 0;}
    vi bfs;
    bfs.pb(1);
    visited[1]=items[1];
    while(!bfs.empty()){
        vi tmp;
        for(int i=0; i<int(bfs.size()); i++){
            int currentItem = bfs[i];
            for(int j=0; j<int(adj[currentItem].size()); j++){
                int nextItem = adj[currentItem][j];
                visited[nextItem]=visited[currentItem]+items[nextItem];
                if(adj[nextItem].empty()) ans=min(ans, visited[nextItem]);
                else tmp.pb(nextItem);
            }
        }
        bfs=tmp;
    }
    cout << ans;
    return 0;
}
// TATAKAE TATAKAE1
