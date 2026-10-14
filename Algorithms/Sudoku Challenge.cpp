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

char matrix[9][9];
int ans[9][9];

bool isSafe(int x, int y, int v){
    int i, j, a=(x/3)*3, b=(y/3)*3;
    for(i=0; i<9; i++){
        if(ans[i][y]==v) return false;
        if(ans[x][i]==v) return false;
    }
    for(i=a; i<a+3; i++){
        for(j=b; j<b+3; j++){
            if(ans[i][j]==v) return false;
        }
    }
    return true;
}

void printSudoku(){
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            cout << ans[i][j];
        }
        cout << endl;
    }
}

bool solveSudoku(int row, int col){
    if(col==9){
        if(row==8){
            return true;
        }
        row++;col=0;
    }
    if(ans[row][col]==0){
        for(int k = 1; k<=9; k++){
            if(isSafe(row, col, k)){
                ans[row][col] = k;
                if(solveSudoku(row, col+1)){
                    return true;
                }
                ans[row][col] = 0;
            }
        }
    }else{
        if(solveSudoku(row, col+1)){
            return true;
        }
    }
    return false;
}

int main() {
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            cin >> matrix[i][j];
            if(matrix[i][j]=='.') ans[i][j] = 0;
            else ans[i][j] = matrix[i][j] - '0';
        }
    }
    if(solveSudoku(0, 0)==true){
        printSudoku();
    }
    return 0;
}
// TATAKAE TATAKAE
