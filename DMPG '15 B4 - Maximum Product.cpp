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
vi neg;

int main(){
    int ans = 1;
    bool zero = 0;
    cin >> n;
    for(int i=1; i<=n; i++){
        int x;
        cin >> x;
        if(x>0) ans*=x;
        else if(x<0){
            neg.pb(x);
        }else zero=1;
    }
    sort(all(neg), greater<int>());
    if(int(neg.size())%2==0){
        for(int x:neg) ans*=x;
        neg={};
    }else{
        for(int i=1; i<int(neg.size()); i++){
            ans*=neg[i];
        }
        neg={neg[0]};
    }
    if(neg.size() && ans==1 && !zero) cout << neg[0];
    else if(ans==1) cout << 0;
    else cout << ans;
    return 0;
}
// TATAKAE TATAKAE
