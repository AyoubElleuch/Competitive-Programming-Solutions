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
typedef set<string> sstr;

int min(int a, int b){
    return a<b?a:b;
}
int max(int a, int b){
    return a>b?a:b;
}

int minSum(vi& dmoj, vi& peg){
    int sum = 0;
    sort(all(dmoj)); sort(all(peg));
    for(int i = 0; i < int(dmoj.size()); i++){
        sum+=max(dmoj[i], peg[i]);
    }
    return sum;
}
int maxSum(vi& dmoj, vi& peg){
    int sum = 0;
    sort(all(dmoj)); sort(all(peg), greater<int>());
    for(int i = 0; i < int(dmoj.size()); i++){
        sum+=max(dmoj[i], peg[i]);
    }
    return sum;
}


int main() {
    int k, n; cin >> k >> n;
    vi dmoj(n); vi peg(n);
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < n; j++){
            if(i==0)cin >> dmoj[j];
            else cin >> peg[j];
        }
    }
    if(k==1) cout << minSum(dmoj, peg);
    else cout << maxSum(dmoj, peg);

    return 0;
}

// LONG LONG
