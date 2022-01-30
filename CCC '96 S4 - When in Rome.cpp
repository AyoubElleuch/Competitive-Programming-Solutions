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

unordered_map<char, int> romans = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};

bool valid(char a, char b){
    if(a=='I' && (b=='V' || b=='X')){
        return true;
    }else if(a=='X' && (b=='L' || b=='C')){
        return true;
    }else if(a=='C' && (b=='D' || b=='M')){
        return true;
    }
    return false;
}

int romanToInt(string s){
    int ans = 0;
    for(int i=0; i<int(s.size()); i++){
        char a = s[i];
        if(i<int(s.size())-1){
            char b = s[i+1];
            if(valid(a, b)){
                ans+=romans[b]-romans[a];
                i++;
            }else{
                ans+=romans[a];
            }
        }else{
            ans+=romans[a];
        }
    }
    return ans;
}

string intToRomans(int n){
    string str_romans[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};

    string result = "";

    for (int i = 0; i < 13; ++i){
        while(n - values[i] >= 0){
            result += str_romans[i];
            n -= values[i];
        }
    }
    return result;
}

int main() {
    int n;
    cin >> n;
    while(n--){
        string s, f="", sec="";
        bool found = false;
        cin >> s;
        for(int i=0; i<int(s.size()-1);i++){
            if(found){
                sec+=s[i];
            }else{
                if(s[i]=='+'){
                    found = true;
                    continue;
                }
                f+=s[i];
            }
        }
        cout << s;
        int sum = romanToInt(f) + romanToInt(sec);
        if(sum>1000) cout << "CONCORDIA CUM VERITATE" << endl;
        else{
            cout << intToRomans(sum) << endl;
        }
    }
    return 0;
}
// TATAKAE TATAKAE
