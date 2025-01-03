// barkolorious - 03 December 2024
// in god, do we trust? 
#include <bits/stdc++.h>
using namespace std;

#define FIN(x) freopen(x ".in", "r", stdin)
#define FOUT(x) freopen(x ".out", "w", stdout)
#define int long long
#define pb  push_back
#define fr  first
#define sc  second
#define __  << " " << 

const int N = 2e5 + 5;
vector<int> adj[N], radj[N];
int in_degree[N], par[N], dist[N];
int n, m;

void solve () {
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int u, v; cin >> u >> v;
    adj[u].pb(v);
    radj[v].pb(u);
    in_degree[v]++;
  }

  vector<int> topo;
  queue<int> q;
  for (int i = 1; i <= n; i++) {
    if (in_degree[i] == 0) q.push(i);
    dist[i] = INT_MIN;
  }

  while (!q.empty()) {
    int u = q.front(); q.pop();
    topo.pb(u);
    for (int v : adj[u]) {
      if (--in_degree[v] == 0) q.push(v);
    }
  } 

  memset(par, -1, sizeof(par));
  dist[1] = 0;
  for (int u : topo) {
    for (int v : radj[u]) {
      if (dist[v] + 1 > dist[u]) {
        dist[u] = dist[v] + 1;
        par[u] = v;
      }
    }
  }

  if (dist[n] < 0) {
    cout << "IMPOSSIBLE" << endl;
    return;
  } 

  vector<int> route;
  int ptr = n;
  while (ptr != 1) {
    route.pb(ptr);
    ptr = par[ptr];
  }
  route.pb(1);
  reverse(route.begin(), route.end());
  cout << route.size() << endl;
  for (int x : route) cout << x << " ";
  cout << endl;
}

/*
-- Sample 1 --
Input:
5 5
1 2
2 5
1 3
3 4
4 5
Output:
4
1 3 4 5
*/

/*
g++ -std=c++17 -O2 -Wall -DLOCAL "C:\Users\LENOVO\Desktop\BARKIN\Genel\Programming\Competitive\Questions\CSES\Graph_Algorithms\1680_longest_flight_route.cpp" -o _run
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