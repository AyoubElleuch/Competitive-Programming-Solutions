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

int n, m, x, y, ans = 0;
int board[101][101];

void fillBoard(int r, int c){
    if(!board[r][c]) board[r][c]=1;
    for(int i=1; i<=n; i++){
        if(!board[i][c]) board[i][c]=1;
        if(!board[r][i]) board[r][i]=1;
    }
    for(int i=r, j=c; i<=n && j<=n; i++, j++){
        if(!board[i][j]) board[i][j]=1;
    }
    for(int i=r, j=c; i<=n && j>=1; i++, j--){
        if(!board[i][j]) board[i][j]=1;
    }
    for(int i=r, j=c; i>=1 && j>=1; i--, j--){
        if(!board[i][j]) board[i][j]=1;
    }
    for(int i=r, j=c; i>=1 && j<=n; i--, j++){
        if(!board[i][j]) board[i][j]=1;
    }
}


int main(){
    cin >> n >> m;
    for(int i=1; i<=m; i++){
        cin >> x >> y;
        fillBoard(x, y);
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++) if(board[i][j]==0) ans+=1;
    }
    cout << ans;
    return 0;
}
// TATAKAE TATAKAE
