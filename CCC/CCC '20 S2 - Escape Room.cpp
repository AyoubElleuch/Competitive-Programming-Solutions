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


int main() {
    int row, col; cin >> row >> col;
    vvi grid = vector<vector<int>>(row+10, vector<int>(col+10)), visited = vector<vector<int>>(row+10, vector<int>(col+10));
    vector<vector<pair<int, int>>> adj=vector<vector<pair<int, int>>>(1000100);
    for(int i = 1; i <= row; i++){
        for(int j=1; j <= col; j++){
            int val; cin >> val;
            grid[i][j] = val;
            adj[i*j].pb(mp(i, j));
        }
    }
    queue<pair<int, int>> bfs;
    bfs.push(mp(1, 1));
    visited[1][1] = true;
    while(!bfs.empty()){
        pair<int, int> cur = bfs.front(); bfs.pop();
        if(cur.fi == row && cur.se == col){
            cout << "yes";
            return 0;
        }
        for(pair<int, int> nxt : adj[grid[cur.fi][cur.se]]){
            if(!visited[nxt.fi][nxt.se]){
                bfs.push(nxt);
            }
            visited[nxt.fi][nxt.se] = true;
        }
    }
    cout << "no";
    return 0;
}
// TATAKAE TATAKAE
