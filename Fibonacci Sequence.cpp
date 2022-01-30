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

ull m = 1e9+7, a, b, c, d, first=false;
ull A[4] = {1, 1, 1, 0};
ull v[4] = {1, 1, 1, 0};

void multByOne(){
    a = (v[0]*A[0]+v[1]*A[2])%m;
    b = (v[0]*A[1]+v[1]*A[3])%m;
    c = (v[2]*A[0]+v[3]*A[2])%m;
    d = (v[2]*A[1]+v[3]*A[3])%m;
    v[0]=a; v[1]=b; v[2]=c; v[3]=d;
}

void multTwice(){
    a = (A[0]*A[0]+A[1]*A[2])%m;
    b = (A[0]*A[1]+A[1]*A[3])%m;
    c = (A[2]*A[0]+A[3]*A[2])%m;
    d = (A[2]*A[1]+A[3]*A[3])%m;
    A[0]=a; A[1]=b; A[2]=c; A[3]=d;
}

int matrix_power(ull n){
    while(n>=1){
        if(n%2==1) multByOne();
        n/=2;
        multTwice();
    }
    return v[0];
}

int main() {
    ull n; cin >> n;
    if(n<2){
        cout << n;
        return 0;
    }
    cout << matrix_power(n-2);
    return 0;
}
// TATAKAE TATAKAE
