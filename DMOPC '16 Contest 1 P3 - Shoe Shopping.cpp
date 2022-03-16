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

int n;
double prices[10001];
double dp[10001];

db min(db a, db b){
    if(a<b) return a;
    return b;
}

db free(int a){
    db ans = 0;
    bool done = 0;
    db smallest = inf;
    for(int i=a; i<=a+2; i++){
        smallest = min(smallest, prices[i]);
    }
    for(int i=a; i<=a+2; i++){
        if(prices[i]==smallest && !done){
            done=1;
        }else ans+=prices[i];
    }
    return ans;
}

db dis(int a){
    db ans = 0;
    if(prices[a]>prices[a+1]) ans = double(prices[a]+(prices[a+1]/2));
    else ans = db((prices[a]/2)+prices[a+1]);
    return ans;
}

db solve(int i){
    if(i>n) return 0;
    if(i==n) return prices[i];
    if(dp[i]) return dp[i];
    double ans = 1e19;
    if(i<=n-2) ans = min(solve(i+3)+free(i), ans);
    if(i<=n-1) ans = min(solve(i+2)+dis(i), ans);
    dp[i]=min(solve(i+1)+prices[i], ans);
    return dp[i];
}

int main(){
    db ans = inf;
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> prices[i];
    }
    if(n>=3) ans = min(solve(4)+free(1), ans);
    if(n>=2) ans = min(solve(3)+dis(1), ans);
    ans=min(solve(2)+prices[1], ans);
    printf("%.1f", ans);
    return 0;
}
// TATAKAE TATAKAE
