// barkolorious - 10 December 2024
// in god, do we trust? 
#include <bits/stdc++.h>
using namespace std;

// #define USACO
#define FIN(x) freopen(x ".in", "r", stdin)
#define FOUT(x) freopen(x ".out", "w", stdout)
#define all(v) (v).begin(), (v).end()
#define int long long
#define pb  push_back
#define sz  size
#define fr  first
#define sc  second
#define __  << " " << 

const int MAXN = 2e5 + 5;
const int MAXD = 20;
vector<int> adj[MAXN];
int n, q;
int par[MAXN][MAXD]{}, depth[MAXN];

void dfs (int u, int p, int d = 0) {
  depth[u] = d;
  par[u][0] = p;
  for (int v : adj[u]) {
    if (v == p) continue;
    dfs(v, u, d + 1);
  }
}

void init () {
  for (int i = 1; i <= n; i++) depth[i] = -1;
  
  for (int i = 1; i <= n; i++)
    if (depth[i] == -1) dfs(1, 1);

  for (int d = 1; d < MAXD; d++) {
    for (int i = 1; i <= n; i++) {
      par[i][d] = par[par[i][d - 1]][d - 1];
    }
  }
}

int query (int u, int v) {
  if (depth[u] > depth[v]) swap(u, v);

  int ans = 0;

  for (int d = MAXD - 1; d >= 0; d--) {
    if (depth[v] - (1 << d) >= depth[u]) {
      v = par[v][d];
      ans += (1 << d);
    }
  }

  if (u == v) return ans;

  for (int d = MAXD - 1; d >= 0; d--) {
    if (par[u][d] == par[v][d]) continue;
    u = par[u][d];
    v = par[v][d];
    ans += 2 * (1 << d);
  }

  if (par[u][0] != par[v][0]) return -1;

  return ans + 2 * (1 << 0);
}

void solve () {
  cin >> n >> q;

  for (int i = 1; i < n; i++) {
    int u, v; cin >> u >> v;
    adj[u].pb(v); adj[v].pb(u);
  }

  init();

  while (q--) {
    int u, v; cin >> u >> v;
    cout << query(u, v) << endl;
  }
}

/*
-- Sample 1 --
Input:
5 3
1 2
1 3
3 4
3 5
1 3
2 5
1 4
Output:
1
3
2
*/

/*
g++ -std=c++17 -O2 -Wall -DLOCAL "C:\Users\LENOVO\Desktop\BARKIN\Genel\Programming\Competitive\Questions\CSES\Tree_Algorithms\1135_distance_queries.cpp" -o _run
*/

int32_t main () {
  #if !defined(LOCAL)
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
  #endif

  #if defined(LOCAL)
    clock_t __START__ = clock();
    FILE* __FILE_IN__ = FIN("C:/Users/LENOVO/Desktop/BARKIN/Genel/Programming/Competitive/_run");
    FILE* __FILE_OUT__ = FOUT("C:/Users/LENOVO/Desktop/BARKIN/Genel/Programming/Competitive/_run");
  #elif defined(USACO)
    FILE* __FILE_IN__ = FIN("usaco");
    FILE* __FILE_OUT__ = FOUT("usaco");
  #endif

  solve();

  #if defined(LOCAL)
    fclose(__FILE_IN__);
    fclose(__FILE_OUT__);
    cerr << "Executed in: " << fixed << setprecision(3) << (double) (clock() - __START__) / CLOCKS_PER_SEC << "seconds" << endl;
  #elif defined(USACO)
    fclose(__FILE_IN__);
    fclose(__FILE_OUT__);
  #endif

  return 0;
}