// barkolorious - 19 September 2024
#include <bits/stdc++.h>
using namespace std;

#define FIN(x) freopen(x ".in", "r", stdin)
#define FOUT(x) freopen(x ".out", "w", stdout)
#define int long long
#define pb  push_back
#define fr  first
#define sc  second

const int N = 2e5 + 5;

/*
g++ -std=c++17 -O2 -Wall -DLOCAL "C:\Users\LENOVO\Desktop\BARKIN\Genel\Programming\Competitive\Questions\CSES\Tree_Algorithms\1138_path_queries.cpp" -o _run
*/

int val[N], segt[4 * N], par[N], head[N], heavy[N], pos[N], depth[N], arr[N];
int curr_pos = 1, n, q; 
vector<int> adj[N];

int dfs (int u) {
  int size = 1, max_size = 0;
  for (int v : adj[u]) {
    if (v != par[u]) {
      par[v] = u; depth[v] = depth[u] + 1;
      int child_size = dfs(v);
      size += child_size;
      if (child_size > max_size) {
        heavy[u] = v;
        max_size = child_size;
      }
    }
  }
  return size;
}

void decompose (int u, int h) {
  head[u] = h; pos[u] = curr_pos++;
  arr[pos[u]] = val[u];
  
  if (heavy[u]) decompose(heavy[u], h);
  for (int v : adj[u]) {
    if (v != par[u] && v != heavy[u]) {
      decompose(v, v);
    }
  }
}

void build (int v, int tl, int tr) {
  if (tl == tr) segt[v] = arr[tl];
  else {
    int tm = (tl + tr) / 2;
    build(2 * v, tl, tm);
    build(2 * v + 1, tm + 1, tr);
    segt[v] = segt[2 * v] + segt[2 * v + 1];
  }
}

void update (int v, int tl, int tr, int p, int x) {
  if (tl == tr) segt[v] = x;
  else {
    int tm = (tl + tr) / 2;
    if (p <= tm) update(2 * v, tl, tm, p, x);
    else update(2 * v + 1, tm + 1, tr, p, x);
    segt[v] = segt[2 * v] + segt[2 * v + 1];
  }
}

int segt_query (int v, int tl, int tr, int l, int r) {
  if (tr < l || tl > r) return 0;
  if (tl == l && tr == r) return segt[v];
  int tm = (tl + tr) / 2;
  return segt_query(2 * v, tl, tm, l, min(tm , r)) +
         segt_query(2 * v + 1, tm + 1, tr, max(l, tm + 1), r);
}

int query (int u, int v) {
  int res = 0;
  for (; head[u] != head[v]; v = par[head[v]]) {
    if (depth[head[u]] > depth[head[v]]) swap(u, v);
    res += segt_query(1, 1, n, pos[head[v]], pos[v]);
  }
  if (depth[u] > depth[v]) swap(u, v);
  res += segt_query(1, 1, n, pos[u], pos[v]);
  return res;
}


void solve () {
  cin >> n >> q;

  for (int i = 1; i <= n; i++) cin >> val[i];
  for (int i = 0; i < n - 1; i++) {
    int u, v; cin >> u >> v;
    adj[u].pb(v); adj[v].pb(u);
  }

  par[1] = 1;
  dfs(1);
  decompose(1, 1);

  build(1, 1, curr_pos - 1);

  for (int qi = 0; qi < q; qi++) {
    int type; cin >> type;
    if (type == 1) {
      int u, x; cin >> u >> x;
      val[u] = x;
      arr[pos[u]] = x;
      update(1, 1, n, pos[u], x);
    } else if (type == 2) {
      int u; cin >> u;
      cout << query(1, u) << endl;
    }
  }
}

/*
-- Sample 1 --
Input:
5 3
4 2 5 2 1
1 2
1 3
3 4
3 5
2 4
1 3 2
2 4
Output:
11
8
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