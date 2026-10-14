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

int k, r, c;
vi rooms;
char plan[25][25];
bool visited[25][25];

bool inBounds(int rr, int cc);

int exploreRoom(int rr, int cc);

int main() {
    int ans = 0;
    for(int i=0; i<25; i++){
        for(int j=0; j<25; j++){
            plan[i][j] = 'n';
            visited[i][j] = 0;
        }
    }
    cin >> k >> r >> c;
    cin.ignore();
    for(int i=0; i<r; i++){
        string row;
        getline(cin, row);
        for(int j=0; j<c; j++){
            plan[i][j] = row[j];
        }
    }
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            if(plan[i][j]=='.'){
                int roomSize = exploreRoom(i, j);
                if(roomSize) rooms.pb(roomSize);
            }
        }
    }
    sort(all(rooms), greater<int>());
    for(int i=0; i<int(rooms.size()); i++){
        if(k-rooms[i]>=0){
            ans+=1;
            k-=rooms[i];
        }else{
            break;
        }
    }
    if(ans>1 || ans == 0) cout << ans << " rooms, " << k << " square metre(s) left over";
    else if(ans == 1) cout << ans << " room, " << k << " square metre(s) left over";
    return 0;
}

bool inBounds(int rr, int cc){
    bool rowInBounds = 0<=rr && rr<r;
    bool colInBounds = 0<=cc && cc<c;
    return (!(rowInBounds) ||!(colInBounds));
}

int exploreRoom(int rr, int cc){
    if(inBounds(rr, cc)) return 0;
    if(visited[rr][cc]==1) return 0;
    if(plan[rr][cc]=='I') return 0;
    visited[rr][cc] = 1;
    int ans = 1;
    ans+=exploreRoom(rr+1, cc);
    ans+=exploreRoom(rr, cc+1);
    ans+=exploreRoom(rr-1, cc);
    ans+=exploreRoom(rr, cc-1);
    return ans;
}
// TATAKAE TATAKAE
