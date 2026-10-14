#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define all(x) x.begin(), x.end()
#define fi first
#define se second
#define inf 1000000000
#define EPSILON (pow(2, -203))
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

int main(){
    int n; cin >> n;
    vs first, second;
    for(int i = 0; i<2; i++){
        for(int j = 0; j<n; j++){
            string s; cin >> s;
            i==0?first.pb(s):second.pb(s);
        }
    }
    if(n%2==1){
        cout << "bad";
        return 0;
    }
    for(int i = 0; i < n; i++){
        auto it = find(second.begin(), second.end(), first[i]);
        int position = distance(second.begin(), it);
        if(!(first[position]==second[i]) || position == i){
            cout << "bad";
            return 0;
        }
    }
    cout << "good";
    return 0;
}
// LONG LONG
