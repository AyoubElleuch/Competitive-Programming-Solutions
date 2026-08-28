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

// https://dmoj.ca/problem/traffic

class Edge {
    public:
        int destination;
        int time;
};

int n, k, s, e, t, g, r;

long long solve(const vector<vector<Edge>>& graph,
                const vector<int>& green,
                const vector<int>& red){
                    
    // dist[i] is the fastest known time to reach intersection i.
    vector<long long> dist(graph.size(), inf);
    dist[1] = 0;

    // Store (time, intersection), with the smallest time processed first.
    priority_queue<pair<long long, int>,
                   vector<pair<long long, int>>,
                   greater<pair<long long, int>>> pq;
    pq.push({0, 1});

    while (!pq.empty()) {
        pair<long long, int> state = pq.top();
        pq.pop();
        long long currentTime = state.first;
        int current = state.second;

        // An older, slower entry for this intersection can be ignored.
        if (currentTime != dist[current]) continue;
        if (current == k) return currentTime;

        for (const Edge& edge : graph[current]) {
            long long wait = 0;

            // Wait at the current light if it is red when we arrive.
            if (green[current] != 0 || red[current] != 0) {
                long long cycle = green[current] + red[current];
                long long phase = currentTime % cycle;

                if (phase >= green[current]) {
                    wait = cycle - phase;
                }
            }

            long long newTime = currentTime + wait + edge.time;
            if (newTime < dist[edge.destination]) {
                dist[edge.destination] = newTime;
                pq.push({newTime, edge.destination});
            }
        }
    }

    return dist[k];
}

int main(){
    boost();
    cin >> n >> k;
    vector<vector<Edge>> graph(k + 1);
    vector<int> green(k + 1);
    vector<int> red(k + 1);

    while(n--){
        cin >> s >> e >> t;
        graph[s].pb({e, t});
        graph[e].pb({s, t});
    }

    for (int i = 1; i <= k; i++) {
        cin >> green[i] >> red[i];
    }

    cout << solve(graph, green, red) << '\n';

    return 0;
}
