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

// Link to problem: https://dmoj.ca/problem/ds2

int parent(int x);
void fusion(int x, int y);
int v[100001], r[100001];

int main() {
    vi ans;
    int n, m, a, b, sa, sb,nodes = 1;
    cin >> n >> m;
    for(int i=0; i<100001; i++){
        v[i]=i;
        r[i]=1;
    }
    for(int i=1; i<=m; i++){
        cin >> a >> b;
        sa = parent(a);
        sb = parent(b);
        if(sa!=sb){
            fusion(sa, sb);
            nodes++;
            ans.pb(i);
        }
    }
    if(nodes<n){
        cout << "Disconnected Graph";
        return 0;
    }else{
        for(auto elm:ans){
            cout << elm << endl;
        }
    }
    return 0;
}

int parent(int x){
    while(v[x]!=x) x = v[x];
    return x;
}

void fusion(int x, int y){
    if(r[x]>=r[y]){
        v[y] = x;
        r[x]+=r[y];
    }else{
        v[x]=y;
        r[y]+=r[x];
    }
}
// TATAKAE TATAKAE
