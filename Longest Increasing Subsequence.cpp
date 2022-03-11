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

// link to problem: https://dmoj.ca/problem/dp1p3

int n;
vi v, sq(5000, 1);
unordered_map<int, int> dp; 
int longest(int l, int i);

int main() {
    int ans = 0;
    cin >> n;
    for(int i=0; i<n; i++){
        int x; cin >> x; v.pb(x);
    }
    int i = 1;
    for(int j=0; j<n; j++){
        while(j!=i){
            if(v[j]<v[i]){
                if((sq[i]-1<=sq[j])) sq[i]=sq[j]+1;
            }
            ++j;
        }
        j=-1;
        if(i<n-1) ++i;
        else break;
    }
    for(int i=0; i<n; i++){
        if(sq[i]>ans) ans = sq[i];
    }
    cout << ans;
    return 0;
}

// TATAKAE TATAKAE
