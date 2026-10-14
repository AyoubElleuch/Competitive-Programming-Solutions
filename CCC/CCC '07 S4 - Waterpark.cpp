#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define pf pop_front
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

vvi v(10000+10);
vi dp(10000+10);

int explore(int n){
    if(n==1) return 1;
    if(dp[n]!=0) return dp[n];
    int ans = 0;
    for(int elm:v[n]){
        ans+=explore(elm);
    }
    dp[n] = ans;
    return dp[n];
}

int main(){
    int n;
    cin >> n;
    while(n){
        int a, b;
        cin >> a >> b;
        if(a==0) break;
        v[b].pb(a);
    }
    cout << explore(n);
    return 0;
}
// TATAKAE TATAKAE
