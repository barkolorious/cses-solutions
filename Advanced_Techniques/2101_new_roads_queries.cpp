// barkolorious - 02 December 2024
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
const int D = 18;
int dsu[N];
int par[N][D], val[N][D], depth[N];
int n, m, q; 
vector<pair<int, int>> adj[N];

void DSU_Make (int u) {
  dsu[u] = u;
}

int DSU_Find (int u) {
  if (dsu[u] == u) return u;
  return dsu[u] = DSU_Find(dsu[u]);
}

void DSU_Link (int u, int v) {
  u = DSU_Find(u), v = DSU_Find(v);
  dsu[v] = u;
}

void dfs (int u, int p, int d) {
  depth[u] = d;
  par[u][0] = p;
  for (auto edge : adj[u]) {
    if (edge.fr == p) continue;
    val[edge.fr][0] = edge.sc;
    dfs(edge.fr, u, d + 1);
  }
}

void LCA_Init () {
  memset(depth, -1, sizeof(depth));

  for (int i = 1; i <= n; i++)
		if (depth[i] == -1) dfs(i, i, 0);

  for (int d = 1; d < D; d++) {
    for (int i = 1; i <= n; i++) {
      par[i][d] = par[par[i][d - 1]][d - 1];
      val[i][d] = max(val[i][d - 1], val[par[i][d - 1]][d - 1]);
    }
  }
}

int LCA_query (int a, int b) {
  if (depth[a] > depth[b]) swap(a, b);

  int res = 0;
  for (int d = D - 1; d >= 0; d--) {
    if (depth[b] - (1 << d) >= depth[a]) {
      res = max(res, val[b][d]);
      b = par[b][d];
    }
  }

  if (a == b) return res;

  for (int d = D - 1; d >= 0; d--) {
    if (par[a][d] != par[b][d]) {
      res = max(res, val[a][d]);
      res = max(res, val[b][d]);
      a = par[a][d];
      b = par[b][d];
    }
  }

  if (par[a][0] != par[b][0]) return -1;
	res = max(res, val[a][0]);
	res = max(res, val[b][0]);

	return res;
}

void solve () {
  cin >> n >> m >> q;

  for (int i = 1; i <= n; i++) DSU_Make(i);

  for (int i = 0; i < m; i++) {
    int u, v; cin >> u >> v;
    if (DSU_Find(u) != DSU_Find(v)) {
      DSU_Link(u, v);
      adj[u].pb({v, i + 1});
      adj[v].pb({u, i + 1});
    }
  }

  LCA_Init();

  for (int i = 0; i < q; i++)  {
    int u, v; cin >> u >> v;
    cout << LCA_query(u, v) << endl;
  }
}

/*
-- Sample 1 --
Input:
5 4 3
1 2
2 3
1 3
2 5
1 3
3 4
3 5
Output:
2
-1
4
*/

/*
g++ -std=c++17 -O2 -Wall -DLOCAL "C:\Users\LENOVO\Desktop\BARKIN\Genel\Programming\Competitive\Questions\CSES\Advanced_Techniques\2101_new_roads_queries.cpp" -o _run
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