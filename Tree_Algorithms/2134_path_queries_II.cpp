// barkolorious - 19 September 2024
#include <bits/stdc++.h>
using namespace std;

#define FIN(x) freopen(x ".in", "r", stdin)
#define FOUT(x) freopen(x ".out", "w", stdout)
// #define int long long
#define pb  push_back
#define fr  first
#define sc  second

const int N = 2e5 + 5, D = 19;

/*
g++ -std=c++17 -O2 -Wall -DLOCAL "C:\Users\LENOVO\Desktop\BARKIN\Genel\Programming\Competitive\Questions\CSES\Tree_Algorithms\2134_path_queries_II.cpp" -o _run
*/

int n, segt[1 << D]{};
vector<int> adj[N];

int head[N], depth[N], id[N];
int subtree[N], p[N][D], val[N], curr_id = 1;

void update (int v, int x) {
  segt[v += n] = x;
  for (v /= 2; v; v /= 2) 
    segt[v] = max(segt[2 * v], segt[2 * v + 1]);
}

int query (int l, int r) {
  int ra = 0, rb = 0;
  for (l += n, r += n + 1; l < r; l /= 2, r /= 2) {
    if (l & 1) ra = max(ra, segt[l++]);
    if (r & 1) rb = max(rb, segt[--r]);
  }
  return max(ra, rb);
}

int dfs (int u, int par) {
  subtree[u] = 1;
  for (int v : adj[u]) {
    if (v == par) continue;
    depth[v] = depth[u] + 1;
    p[v][0] = u; 
    subtree[u] += dfs(v, u);
  }
  return subtree[u];
}

void init_lca () {
  for (int d = 1; d < D - 1; d++)
    for (int i = 1; i <= n; i++) 
      p[i][d] = p[p[i][d - 1]][d - 1];
}

void hld (int u, int par, int h) {
  id[u] = curr_id++;
  head[u] = h;
  update(id[u], val[u]);
  int heavy_child = -1, heavy_subtree = -1;
  for (int v : adj[u]) {
    if (v == par) continue;
    if (subtree[v] > heavy_subtree) {
      heavy_child = v;
      heavy_subtree = subtree[v];
    }
  }
  if (heavy_child == -1) return;
  hld(heavy_child, u, h);
  for (int v : adj[u]) {
    if (v == par || v == heavy_child) continue;
    hld(v, u, v);
  }
}

int lca (int u, int v) {
  if (depth[u] < depth[v]) swap(u, v);
  for (int d = D - 1; d >= 0; d--) {
    if (depth[u] - depth[v] >= (1 << d)) 
      u = p[u][d];
  }
  for (int d = D - 1; d >= 0; d--) {
    if (p[u][d] != p[v][d]) {
      u = p[u][d]; v = p[v][d];
    }
  }
  if (u != v) {
    u = p[u][0];
    v = p[v][0];
  }
  return u;
}

int path (int u, int par) {
  int ret = 0;
  while (u != par) {
    if (head[u] == u) {
      ret = max(ret, val[u]);
      u = p[u][0];
    } else if (depth[head[u]] > depth[par]) {
      ret = max(ret, query(id[head[u]], id[u]));
      u = p[head[u]][0];
    } else {
      ret = max(ret, query(id[par] + 1, id[u]));
      break;
    }
  }
  return ret;
}

void solve () {
  int q;
  scanf("%d%d", &n, &q);

  for (int i = 1; i <= n; i++) scanf("%d", &val[i]);
  for (int i = 2; i <= n; i++) {
    int u, v; 
		scanf("%d%d", &u, &v); 
    adj[u].pb(v); adj[v].pb(u);
  }
  
  dfs(1, 1);
  init_lca();
  hld(1, 1, 1);
  
  for (int qi = 0; qi < q; qi++) {
    int type;
		scanf("%d", &type);
    if (type == 1) {
      int u, x; scanf("%d%d", &u, &x);
      val[u] = x;
      update(id[u], val[u]);
    } else if (type == 2) {
      int u, v; scanf("%d%d", &u, &v);
      int w = lca(u, v);
      int ans = max(max(path(u, w), path(v, w)), val[w]);
      cout << ans << " ";
    }
  }
}

/*
-- Sample 1 --
Input:
5 3
2 4 1 3 3
1 2
1 3
2 4
2 5
2 3 5
1 2 2
2 3 5
Output:
4 3
*/

int32_t main () {
  #ifndef LOCAL
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
  #endif

  #ifdef LOCAL
    FILE* __FILE_IN__ = FIN("C:/Users/LENOVO/Desktop/BARKIN/Genel/Programming/Competitive/_run");
    FILE* __FILE_OUT__ = FOUT("C:/Users/LENOVO/Desktop/BARKIN/Genel/Programming/Competitive/_run");
    clock_t __START__ = clock();
  #else
    #ifndef ONLINE_JUDGE
      FILE* __FILE_IN__ = FIN("usaco");
      FILE* __FILE_OUT__ = FOUT("usaco");
    #endif
  #endif

  solve();

  #ifdef LOCAL
    clock_t __END__ = clock();
    fclose(__FILE_IN__);
    fclose(__FILE_OUT__);
    cerr << "Executed in: " << fixed << setprecision(3) << (double) (__END__ - __START__) / CLOCKS_PER_SEC << "seconds" << endl;
  #else
    #ifndef ONLINE_JUDGE
      fclose(__FILE_IN__);
      fclose(__FILE_OUT__);
    #endif
  #endif

  return 0;
}