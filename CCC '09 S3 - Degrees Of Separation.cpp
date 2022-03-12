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

char c;
int adj[51][51];

void addFriends(int x, int y){
    if(!adj[x][y]){
        adj[x][y]=1;
        adj[y][x]=1;
    }
}

void deleteFriends(int x, int y){
    adj[x][y] = adj[y][x] = 0;
}

void numFriends(int x){
    int ans = 0;
    for(int i=0; i<51; i++){
        if(adj[x][i]) ans++;
    }
    cout << ans << endl;
}

void fof(int x){
    vi dp(51, 0);
    dp[x]=1;
    int ans = 0;
    for(int i=0; i<51; i++){
        if(adj[x][i]){
            dp[i]=1;
            for(int j=0; j<51; j++){
                if(adj[x][j]!=adj[i][j] && adj[i][j]==1 && !dp[j]){
                    ans++;
                    dp[j]=1;
                }
            }
        }
    }
    cout << ans << endl;
}

void degree(int x, int y){
    vi dp(51, 0);
    int ans = 0;
    vi bfs = {x};
    while(!bfs.empty()){
        ans++;
        vi tmp;
        for(int i=0; i<int(bfs.size()); i++){
            dp[bfs[i]] = 1;
            if(adj[bfs[i]][y]){
                cout << ans << endl;
                return;
            }
            for(int j=0; j<51; j++){
                if(adj[bfs[i]][j] && !dp[j]){
                    tmp.pb(j);
                }
            }
        }
        bfs=tmp;
    }
    cout << "Not connected" << endl;
}

int main() {
    int x, y;
    for(int i=0; i<51; i++){
        for(int j=0; j<51; j++){
            adj[i][j]=0;
        }
    }
    addFriends(1, 6);
    addFriends(2, 6);
    addFriends(3, 6);
    addFriends(4, 6);
    addFriends(5, 6);
    addFriends(7, 6);
    addFriends(7, 8);
    addFriends(8, 9);
    addFriends(9, 10);
    addFriends(9, 12);
    addFriends(10, 11);
    addFriends(11, 12);
    addFriends(12, 13);
    addFriends(13, 14);
    addFriends(13, 15);
    addFriends(15, 3);
    addFriends(3, 4);
    addFriends(4, 5);
    addFriends(3, 5);
    addFriends(16, 17);
    addFriends(17, 18);
    addFriends(18, 16);
    cin >> c;
    while(c!='q'){
        if(c=='i'){
            cin >> x >> y;
            addFriends(x, y);
        }
        if(c=='d'){
            cin >> x >> y;
            deleteFriends(x, y);
        }
        if(c=='n'){
            cin >> x;
            numFriends(x);
        }
        if(c=='f'){
            cin >> x;
            fof(x);
        }
        if(c=='s'){
            cin >> x >> y;
            degree(x, y);
        }
        if(c=='q') return 0;
        cin >> c;
    }

    return 0;
}
// TATAKAE TATAKAE
