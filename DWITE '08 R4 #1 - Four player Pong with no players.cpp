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

// https://dmoj.ca/problem/dwite08c4p1

int h, v;

pii solve(int h, int v){
    int t_x = 0, t_y = 0, t_f = 0;
    if(h!=0) t_x = 50 / abs(h);
    if(v!=0) t_y = 25 / abs(v);

    if (!t_x) t_f = t_y;
    else if (!t_y) t_f = t_x;
    else t_f = min(t_x, t_y);

    int x_f = 50 + h * t_f;
    int y_f = 25 + v * t_f;

    return mp(x_f, y_f);
};


int main(){
    int n = 5;

    while(n--){
        cin >> h >> v;
        pii result = solve(h, v);
        cout << result.first << "," << result.second << endl;
    }

    return 0;
}
