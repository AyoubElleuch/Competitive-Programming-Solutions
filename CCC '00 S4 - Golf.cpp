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

int golf(int main, vi clubs, unordered_map<int, int>&dp){
    if(dp.find(main)!=dp.end()) return dp[main];
    if(main==0) return 0;
    else if(main < 0) return -1;
    vi tmp;
    for(auto elm : clubs){
        int x = golf(main-elm, clubs, dp);
        if(x>=0){
            tmp.pb(x+1);
        }
    }
    if(tmp.size()>0){
        sort(all(tmp));
        dp.insert(mp(main, tmp[0]));
        return dp[main];
    }
    dp.insert(mp(main, -1));
    return -1;
}

int main(){
    int n, m, i;
    unordered_map<int, int> dp;
    vi clubs;
    cin >> n >> m;
    for(i=0;i<m;i++){
        int tmp; cin >> tmp;
        clubs.pb(tmp);
    }
    int ans = golf(n, clubs, dp);
    if(ans>0) cout << "Roberta wins in " << ans << " strokes.";
    else cout << "Roberta acknowledges defeat.";
    return 0;
}
