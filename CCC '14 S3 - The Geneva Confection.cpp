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
    int t; cin >> t;
    while(t--){
        vi tmp;
        int n; cin >> n;
        while(n--){
            int x; cin >> x;
            tmp.pb(x);
        }
        reverse(tmp.begin(), tmp.end());
        int current = 1;
        vi reserve;
        while(true){
            if(tmp.size()>0){
                if(tmp[0] == current){
                    current++;
                    tmp.erase(tmp.begin());
                }else if(reserve.size()>0 && reserve[int(reserve.size())-1]==current){
                        reserve.pop_back();
                        current++;
                }else{
                    reserve.pb(tmp[0]);
                    tmp.erase(tmp.begin());
                }
            }
            else if(reserve.size()>0){
                if(reserve[reserve.size()-1]==current){
                    current++;
                    reserve.pop_back();
                }else{
                    cout << 'N' << endl;
                    break;
                }
            }
            else{
                cout << 'Y' << endl;
                break;
            }
        }
    }
    return 0;
}
// LONG LONG
