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
const int mod = 1e9 + 7;
vector<pair<int, int>> adj[N];
int dist[N], vis[N];
int max_edges[N], min_edges[N];
int route_cnt[N];

void solve () {
  int n, m; cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int u, v, w; cin >> u >> v >> w;
    adj[u].pb({v, w});
  } 
  for (int i = 1; i <= n; i++) {
    dist[i] = LLONG_MAX;
    max_edges[i] = 0, min_edges[i] = LLONG_MAX;
  }
  priority_queue<pair<int, int>> pq;
  pq.push({0, 1});
  dist[1] = 0;
  route_cnt[1] = 1;
  min_edges[1] = max_edges[1] = 0;
  while (!pq.empty()) {
    int u = pq.top().sc; pq.pop();
    if (vis[u]) continue;
    vis[u] = true;
    // cout << u << endl;
    for (auto edge : adj[u]) {
      int v = edge.fr, w = edge.sc;
      if (dist[u] + w < dist[v]) {
        dist[v] = dist[u] + w;
        max_edges[v] = max_edges[u] + 1;
        min_edges[v] = min_edges[u] + 1;
        route_cnt[v] = route_cnt[u];
        pq.push({-dist[v], v});
      } else if (dist[u] + w == dist[v]) {
        max_edges[v] = max(max_edges[v], max_edges[u] + 1);
        min_edges[v] = min(min_edges[v], min_edges[u] + 1);
        route_cnt[v] = (route_cnt[v] + route_cnt[u]) % mod;
      }
    }
  }
  cout << dist[n] __ route_cnt[n] __ min_edges[n] __ max_edges[n] << endl;
}

/*
-- Sample 1 --
Input:
4 5
1 4 5
1 2 4
2 4 5
1 3 2
3 4 3
Output:
5 2 1 2
*/

/*
g++ -std=c++17 -O2 -Wall -DLOCAL "C:\Users\LENOVO\Desktop\BARKIN\Genel\Programming\Competitive\Questions\CSES\Graph_Algorithms\1202_investigation.cpp" -o _run
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