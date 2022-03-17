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

// Link to problem: https://dmoj.ca/problem/postfix

float a = 0, b = 0, ans = 0;
int ai = 0, bi = 1;

bool num(string c){
    if(c!="*" && c!="/" && c!="+" && c!="-" && c!="%" && c!="^") return true;
    return false;
}

int main() {
    vector<string> arr;
    vector<string> arr2;
    string s;
    getline(cin, s);
    string tmp = "";
    for(int i=0; i<int(s.size()); i++){
        if(s[i]!=' '){
            tmp+=s[i];
            if(i==int(s.size())-1) arr.pb(tmp);
        }else if(tmp!=""){
            arr.pb(tmp);
            tmp="";
        }
    }
    bool done = 0;
    while(!done){
        done = 1;
        for(int i=0; i<int(arr.size()); i++){
            if(i+1<int(arr.size())-2){
                if(num(arr[i]) && num(arr[i+1])){
                a = stof(arr[i]); b = stof(arr[i+1]);
                int j = i+2;
                float tmp=0;
                if(arr[j]=="*"){tmp=a*b;}
                else if(arr[j]=="/"){tmp=a/b;}
                else if(arr[j]=="+"){tmp=a+b;}
                else if(arr[j]=="-"){tmp=a-b;}
                else if(arr[j]=="%"){tmp=int(a)%int(b);}
                else if(arr[j]=="^"){tmp=pow(a, b);}
                arr2.pb(to_string(tmp));
                done = 0;
                i+=2;
                }else if(!num(arr[i])){
                    arr2.pb(arr[i]);
                }else{
                    arr2.pb(arr[i]);
                    arr2.pb(arr[i+1]);
                    i+=1;
                }
            }else{
                if(!num(arr[i])){
                    arr2.pb(arr[i]);
                }else{
                    arr2.pb(arr[i]);
                    arr2.pb(arr[i+1]);
                    i+=1;
                }
            }
        }
        if(!done){
            arr=arr2;
            arr2={};
        }else{
            arr2=arr;
        }
    }
    if(arr2.size()==1){
        ans = stof(arr2[0]);
        printf("%.1f", ans);
        return 0;
    }
    a = stof(arr2[0]);
    b = stof(arr2[1]);
    for(int i=2; i<int(arr2.size()); i++){
        float tmp=0;
        bool k = 0;
        if(arr2[i]=="*"){tmp=a*b;k=1;}
        else if(arr2[i]=="/"){tmp=a/b;k=1;}
        else if(arr2[i]=="+"){tmp=a+b;k=1;}
        else if(arr2[i]=="-"){tmp=a-b;k=1;}
        else if(arr2[i]=="%"){tmp=int(a)%int(b);k=1;}
        else if(arr2[i]=="^"){tmp=pow(a, b);k=1;}
        if(k){
            arr2[bi] = to_string(tmp);
            ai=bi;
            a=tmp;
        }else{
            b=stof(arr2[i]);
            bi=i;
        }
    }
    ans = stof(arr2[arr2.size()-2]);
    printf("%.1f", ans);
    return 0;
}
// TATAKAE TATAKAE
