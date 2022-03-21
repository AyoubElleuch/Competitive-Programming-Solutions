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
#define loop(x, n) for(int x=0; x<n; x++)
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

int find(string s){
    int b = 1;
    for(int i=1; i<int(s.size()); i++){
        if(s[i]=='B') b++;
        else if(s[i]=='S'){
            b--;
            if(!b) return i;
        }
    }
    return 0;
}

bool solve(string s){
    int l=s.size();
    if(l==1 && s[0]=='A') return true;
    else if(l>2){
        if(s[0]=='A' && s[1]=='N') return solve(s.substr(2, l));
        else if(s[0]=='B'){
            int i = find(s);
            if(i>1){
                if(solve(s.substr(1, i-1))){
                    if(s[i+1]=='N') return solve(s.substr(i+2, l));
                    else if(s.substr(i+1, l).size()==0) return true;
                }
            }
        }
    }
    return false;
}

int main(){
    string s;
    cin >> s;
    while(s!="X"){
        if(s.size() && solve(s)) cout << "YES";
        else cout << "NO";
        cout << endl;
        cin >> s;
    }
    return 0;
}

// TATAKAE TATAKAE
