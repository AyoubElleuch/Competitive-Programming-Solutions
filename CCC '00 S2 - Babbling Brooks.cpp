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

int n, q, a, p;
float l;
vector<float> rivers;

int main(){
    cin >> n;
    while(n--){
        float x;
        cin >> x;
        rivers.pb(x);
    }
    cin >> q;
    while(q!=77){
        if(q==99){
            cin >> a >> p;
            l=float((rivers[a-1]/100)*p);
            rivers.insert(rivers.begin()+a-1, l);
            rivers[a]-=l;
        }
        else if(q==88){
            cin >> a;
            rivers[a-1]+=rivers[a];
            rivers.erase(rivers.begin()+a);
        }else break;
        cin >> q;
    }
    for(int river:rivers) cout << river << " ";
    return 0;
}
// TATAKAE TATAKAE1
