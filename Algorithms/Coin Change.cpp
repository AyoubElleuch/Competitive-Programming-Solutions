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

// link to problem: https://dmoj.ca/problem/cchange

vi v;
int x, n;
unordered_map<ull, ull> dp;
ull minchange(int value);

int main() {
    cin >> x >> n;
    for(int i=0; i<n; i++){
        int t; cin >> t;
        v.pb(t);
    }
    cout << minchange(x);
    return 0;
}

ull minchange(int value){
    if(value==0) return 0;
    if(value<0) return -1;
    if(dp[value]) return dp[value];
    ull m = 10001;
    for(int i=0; i<n; i++){
        ull next = minchange(value-v[i])+1;
        if(next>0 && next<m) m=next;
    }
    dp[value] = m;
    return dp[value];
}

// TATAKAE TATAKAE
