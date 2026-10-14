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

int n, m;
int visited[10001], added[10001];
vvi adj = vector<vector<int>> (10001);

int main(){
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> m;
        while(m--){
            int tmp; cin >> tmp;
            adj[i].pb(tmp);
        }
    }

    int visitedPages = 0;
    bool reached = 0;
    int steps = 1;
    vi bfs = {1};
    while(!bfs.empty()){
        if(!reached) ++steps;
        vi tmp;
        for(int i=0; i<int(bfs.size()); i++){
            int current = bfs[i];
            visited[current]=1;
            visitedPages+=1;
            for(int next:adj[current]){
                if(!visited[next] && !added[next]){
                    if(adj[next].empty()) reached = 1;
                    tmp.pb(next);
                    added[next]=1;
                }
            }
        }
        bfs=tmp;
    }
    if(visitedPages==n) cout << "Y" << endl;
    else cout << "N" << endl;
    cout << steps;
    return 0;
}
// TATAKAE TATAKAE
