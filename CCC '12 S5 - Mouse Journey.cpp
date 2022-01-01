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
typedef pair<ll, pll> plll;
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
    int r, c;
    cin >> r >> c;
  
    // Initializing grids
    char grid[25][25];
    int dp[25][25];
    for(int i = 0; i < 25; i++){
        for(int j = 0; j < 25; j++){
            dp[i][j] = 0;
            grid[i][j] = 'n';
        }
    }
    dp[0][0] = 1;
    
    int n; cin >> n;
    while(n--){
        int a, b;
        cin >> a >> b;
        grid[a-1][b-1] = 'c';
    }
    for(int i = 0;  i < r; i++){
        for(int j = 0; j < c; j++){
            if(j+1 < c){
                if(grid[i][j+1] == 'c'){
                    dp[i][j+1] = 0;
                }else{
                    dp[i][j+1]+=dp[i][j];
                }
            }
            if(i+1 < r){
                if(grid[i+1][j] == 'c'){
                    dp[i+1][j] = 0;
                }else{
                    dp[i+1][j]+=dp[i][j];
                }
            }
        }
    }
    cout << dp[r-1][c-1];
    return 0;
}
// LONG LONG
