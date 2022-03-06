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

vector<ll> v = {0, 990, 1010, 1970, 2030, 2940, 3060, 3930, 4060, 4970, 5030, 5990, 6010, 7000};
ll a, b, n, m;

ll ways(ll i, unordered_map<ll, ll>& dp);

int main() {
    unordered_map<ll, ll> dp;
    cin >> a >> b >> n;
    while(n--){
        cin >> m;
        v.pb(m);
    }
    sort(all(v));
    cout << ways(0, dp) << endl;
    return 0;
}

ll ways(ll i, unordered_map<ll, ll>& dp){
    ll s = v.size();
    if(i>=s) return 0;
    if(v[i]==v[s-1]) return 1;
    if(dp[i]) return dp[i];
    ll ans = 0;
    for(ll j=i+1; j<s; j++){
        if(v[j]-v[i]>=a && v[j]-v[i]<=b){
            ans+=ways(j, dp);
        }
    }
    dp[i] = ans;
    return dp[i];
}

// TATAKAE TATAKAE
