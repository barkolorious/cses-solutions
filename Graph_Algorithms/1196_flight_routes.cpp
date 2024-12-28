// barkolorious - 07 December 2024
// in god, do we trust? 
#include <bits/stdc++.h>
using namespace std;

#define FIN(x) freopen(x ".in", "r", stdin)
#define FOUT(x) freopen(x ".out", "w", stdout)
#define all(v) (v).begin(), (v).end()
#define int long long
#define pb  push_back
#define sz  size
#define fr  first
#define sc  second
#define __  << " " << 

const int N = 2e5 + 5;
const int K = 15;
vector<pair<int, int>> adj[N];
priority_queue<int> dist[N];
int vis[N];

void solve () {
  int n, m, k; cin >> n >> m >> k;
  for (int i = 0; i < m; i++) {
    int u, v, w; cin >> u >> v >> w;
    adj[u].pb({v, w});
  } 

  priority_queue<pair<int, int>> pq;
  pq.push({0, 1});
  dist[1].push(0);

  while (!pq.empty()) {
    int u = pq.top().sc, d = -pq.top().fr;
    pq.pop();

    if (d > dist[u].top()) continue;
    
    for (auto edge : adj[u]) {
      int v = edge.fr, w = edge.sc;
      if (dist[v].sz() < k) {
        dist[v].push(d + w);
        pq.push({-(d + w), v}); 
      } else if (d + w < dist[v].top()){
        dist[v].pop();
        dist[v].push(d + w);
        pq.push({-(d + w), v});
      }
    }
  }
  vector<int> ans;
  while (dist[n].sz()) { ans.pb(dist[n].top()); dist[n].pop(); }
  reverse(all(ans));
  for (int u : ans) cout << u << " ";
  cout.flush();
}

/*
-- Sample 1 --
Input:
4 6 3
1 2 1
1 3 3
2 3 2
2 4 6
3 2 8
3 4 1
Output:
4 4 7
*/

/*
g++ -std=c++17 -O2 -Wall -DLOCAL "C:\Users\LENOVO\Desktop\BARKIN\Genel\Programming\Competitive\Questions\CSES\Graph_Algorithms\1196_flight_routes.cpp" -o _run
*/

int32_t main () {
  #ifndef LOCAL
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
  #endif

  #ifdef LOCAL
    clock_t __START__ = clock();
    FILE* __FILE_IN__ = FIN("C:/Users/LENOVO/Desktop/BARKIN/Genel/Programming/Competitive/_run");
    FILE* __FILE_OUT__ = FOUT("C:/Users/LENOVO/Desktop/BARKIN/Genel/Programming/Competitive/_run");
  #else
    #ifndef ONLINE_JUDGE
      FILE* __FILE_IN__ = FIN("usaco");
      FILE* __FILE_OUT__ = FOUT("usaco");
    #endif
  #endif

  solve();

  #ifdef LOCAL
    fclose(__FILE_IN__);
    fclose(__FILE_OUT__);
    cerr << "Executed in: " << fixed << setprecision(3) << (double) (clock() - __START__) / CLOCKS_PER_SEC << "seconds" << endl;
  #else
    #ifndef ONLINE_JUDGE
      fclose(__FILE_IN__);
      fclose(__FILE_OUT__);
    #endif
  #endif

  return 0;
}