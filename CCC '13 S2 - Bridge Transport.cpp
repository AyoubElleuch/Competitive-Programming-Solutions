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
    int w, n; cin >> w >> n;
    int total = 0;
    int count = 0;
    vi cars;
    while(n--){
        int x; cin >> x;
        cars.pb(x);
    }
    vi railway;
    for(int i = 0; i < int(cars.size()); i++){
        if(railway.size() < 4){
            if(total+cars[i] <= w){
                railway.pb(cars[i]);
                total+=cars[i];
                count++;
            }else break;
        }else{
            total-= railway[0];
            railway.erase(railway.begin());
            if(total+cars[i] <= w){
                railway.pb(cars[i]);
                total+=cars[i];
                count++;
            }else break;
        }
    }
    cout << count;
    return 0;
}
// LONG LONG
