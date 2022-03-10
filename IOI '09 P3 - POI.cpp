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

int scores[2001], tasks[2001], solvedTasks[2001];
vvi v = vector<vector<int>>(2001, vector<int>(2001, 0));

int main() {
    vi ans;
    for(int i = 0; i<2001; i++) scores[i]=tasks[i]=solvedTasks[i]=0;
    int n, t, p, x, ps, cs=0, co = 0;
    cin >> n >> t >> p;
    for(int i=1; i<=n; i++){
        for(int j=0; j<t; j++){
            cin >> x;
            tasks[j+1]+=x;
            v[i][j]=x;
            solvedTasks[i]+=x;
        }
    }
    for(int i=1; i<=t; i++){
        tasks[i] = n-tasks[i];
    }
    for(int i=1; i<=n; i++){
        vi tmp = v[i];
        for(int j=0; j<t; j++){
            scores[i]+=(tasks[j+1]*tmp[j]);
        }
        ans.pb(scores[i]);
    }
    ps = scores[p];

    for(int i=0; i<int(ans.size()); i++){
        if(ans[i]==ps){
            if(solvedTasks[i+1]>solvedTasks[p]) cs++;
            else if(i+1<p && solvedTasks[i+1]==solvedTasks[p]) co++;
        }
    }
    sort(all(ans), greater<int>());
    cout << ps << " ";
    for(int i=0; i<int(ans.size()); i++){
        if(p==1 && ans[i]==ps){
            cout << i+1;
            return 0;
        }
        if(ans[i]==ps){
            cout << i+cs+co+1;
            return 0;
        }
    }
    return 0;
}
// TATAKAE TATAKAE
