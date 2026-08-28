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

// https://dmoj.ca/problem/ctuopen2018g

int a, b, c, d;

int main(){
    cin >> a >> b >> c >> d;

    // every move the knight changes the square color.
    //
    // if both start on the same color, white always
    // moves to the color opposite to the black knight's square
    // -> only black can win
    //
    // same thought process if they start on different colors
    // -> white always wins
    bool sameColor = ((a + b) % 2 == (c + d) % 2);

    if (sameColor) cout << "black\n";
    else cout << "white\n";


    return 0;
}
