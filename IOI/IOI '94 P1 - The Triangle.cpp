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

vvi v;
int n;
unordered_map<string , int> dp;

int maxSum(int x, int level, int index);

int main() {
    cin >> n;
    for(int i=0; i<n; i++){
        vi tmp;
        for(int j=0; j<=i; j++){
            int x;
            cin >> x;
            tmp.pb(x);
        }
        v.pb(tmp);
    }
    cout << maxSum(v[0][0], 1, 0);
    return 0;
}

int maxSum(int x, int level, int index){
    if(level>=n) return x;
    string d = to_string(x) + "," + to_string(level) + "," + to_string(index);
    if(dp[d]) return dp[d];
    int ans = x;
    ans+=max(maxSum(v[level][index], level+1, index), maxSum(v[level][index+1], level+1, index+1));
    dp[d] = ans;
    return ans;
}
// TATAKAE TATAKAE
