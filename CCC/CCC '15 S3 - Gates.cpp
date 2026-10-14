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


int main() {
    int g, p, pi, ans = 0;
    cin >> g >> p;
    int gates[g+10];
    for(int i=0; i<g+10; i++){
        gates[i] = 0;
    }
    while(p--){
        cin >> pi;
        --pi;
        while(pi>=0 && gates[pi]>0){
            int tmp = gates[pi];
            gates[pi]++;
            pi=pi-tmp;
        }
        if(pi<0) break;
        else{
            gates[pi]++;
            ans++;
        }

    }
    cout << ans;
    return 0;
}
// TATAKAE TATAKAE
