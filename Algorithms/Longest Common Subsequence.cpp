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
#define loop(x, n) for(int x=0; x<n; x++)
#define boost() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define dpp(dp, x) 

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

// Link to problem: https://dmoj.ca/problem/lcs

vi v1, v2;
int n, m;
int dp[1001][1001];

int solve(int i, int j){
    if(i==n || j==m) return 0;
    int &ret = dp[i][j];
    if(~ret) return ret;
    ret=-1e9;
    if(v1[i]==v2[j]) {
        ret = max(ret, solve(i+1, j+1)+1);
    }
    else{
        int tmp = max(solve(i, j+1), solve(i+1, j));
        ret = max(ret, tmp);
    }
    return ret;
}

int main(){
    cin >> n >> m;
    for(int i=0; i<1001; i++){
        for(int j=0; j<1001; j++){
            dp[i][j]=-1;
        }
    }
    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        v1.pb(x);
    }
    for(int i=0; i<m; i++){
        int x;
        cin >> x;
        v2.pb(x);
    }
    cout << solve(0, 0);
    return 0;
}

// TATAKAE TATAKAE
