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

ull n, a, b, k, ans = 0;
ull arr[10000008];

int main(){
    cin >> n;
    for(ull i=2; i<=10000001; i++){
        if(arr[i]==ans){
            for(ull j=i; j<=10000001; j+=i){
                arr[j]+=1;
            }
        }
    }
    for(ull c=1; c<=n; c++){
        cin >> a >> b >> k;
        for(ull i=a; i<=b; i++){
            if(arr[i]==k) ans++;
        }
        cout << "Case #" << c << ": " << ans << endl;
        ans=0; 
    }
    return 0;
}
// TATAKAE TATAKAE
