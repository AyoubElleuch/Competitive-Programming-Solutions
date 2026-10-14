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

int grid[200][401];

int main() {
    // Initializing grid
    for(int i=0; i<200; i++){
        for(int j=0; j<401; j++){
            grid[i][j]=0;
        }
    }
    grid[0][200] = grid[1][200] = grid[2][200] = 1;
    grid[6][199] = grid[6][200] = grid[6][201] = grid[6][202] = grid[6][203] = grid[6][204] = grid[6][205] = grid[6][206] = grid[6][207] = 1;
    grid[2][200] = grid[2][201] = grid[2][202] = grid[2][203] = grid[2][205] = grid[2][206] = grid[2][207] = 1;
    grid[3][203] = grid[3][205] = grid[4][203] = grid[4][205] = grid[4][204] = grid[3][207] = grid[4][207] = 1;
    grid[5][207] = grid[5][199] = grid[4][199] = 1;

    char q;
    int n, safe=1;
    int row = -5, col = -1, dr = 0, dc = 0;
    cin >> q >> n;
    while(q!='q' && safe){
        dr = dc = 0;
        if(q=='l') dc = -1;
        else if(q=='r') dc = 1;
        else if(q=='u') dr = 1;
        else dr = -1;
        while(n>0){
            row += dr;
            col += dc;
            if(grid[-(row+1)][col+200]) safe = 0;
            else grid[-(row+1)][col+200] = 1;
            n--; 
        }
        cout << col << " " << row << " ";
        if(safe==1){
            cout << "safe" << endl;
        }else{
            cout << "DANGER"<< endl;
            break;
        }
        cin >> q >> n;
    }
    return 0;
}
// TATAKAE TATAKAE
