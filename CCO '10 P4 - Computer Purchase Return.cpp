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

vi dp(3001, 0);
vvii adj = {{}, {}, {}, {}, {}, {}};
int t, n, ci, va, ti, b;

int main() {
    int ans = 0, c = 1;
    cin >> t >> n;
    for(int i=0; i<n; i++){
        cin >> ci >> va >> ti;
        adj[ti].pb({ci, va});
    }
    cin >> b;
    for(int i=1; i<=t; i++){
        for(int k=b; k>=0; k--){
            for(int j=0; j<int(adj[i].size()); j++){
                if(k+adj[i][j].fi <= b){
                    if((k==0 && i==1) || (dp[k]!=0 && dp[k]+adj[i][j].se > dp[k+adj[i][j].fi])){
                        dp[k+adj[i][j].fi] = dp[k]+adj[i][j].se;
                        if(c==i) c++;
                    }
                }
            }
        }
    }
    if(c<t){
        cout << -1;
        return 0;
    }
    for(int i=1; i<=b; i++){
        if(dp[i]>ans){
            ans=dp[i];
        }
    }
    cout << ans;
    return 0;
}
// TATAKAE TATAKAE
