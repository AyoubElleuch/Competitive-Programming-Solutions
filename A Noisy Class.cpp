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

// Link to problem: https://dmoj.ca/problem/anoisyclass

int n, m, a, b, c=0;
int students[10001];
vi v;
int visited[10001];
vvi adj(10001);

int main(){
    cin >> n >> m;
    for(int i=0; i<m; i++){
        cin >> a >> b;
        students[b]++;
        if(!visited[a]) v.pb(a);
        visited[a]=1;
        adj[a].pb(b);
    }
    for(int i=0; i<int(v.size()); i++) visited[i]=0;
    for(int i=0; i<int(v.size()); i++){
        int currentStudent = v[i];
        if(!students[currentStudent]){
            for(int j=0; j<int(adj[currentStudent].size()); j++){
                students[adj[currentStudent][j]]-=1;
            }
        }
    }
    for(int i=0; i<10001; i++){
        if(students[i]){
            cout << "N";
            return 0;
        }
    }
    cout << "Y";
    return 0;
}
// TATAKAE TATAKAE1
