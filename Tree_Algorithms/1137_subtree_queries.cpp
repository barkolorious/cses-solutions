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
vector<int> adj[MAXN], euler;
int subt[MAXN], val[MAXN], idx_at_euler[MAXN];

struct FenwickTree {
  int n; vector<int> tree;

  FenwickTree (int __n) {
    n = __n;
    tree.assign(n + 1, 0);
  }

  void add (int idx, int val) {
    while (idx <= n) {
      tree[idx] += val;
      idx += idx & -idx;
    }
  } 

  int prefix_sum (int idx) {
    int res = 0;
    while (idx > 0) {
      res += tree[idx];
      idx -= (idx & -idx);
    }
    return res;
  }

  int sum (int l, int r) {
    return prefix_sum(r) - prefix_sum(l - 1);
  }
};

void dfs (int u, int p) {
  subt[u] = 1;
  idx_at_euler[u] = euler.sz();
  euler.pb(u);
  for (int v : adj[u]) {
    if (v == p) continue;
    dfs(v, u);
    subt[u] += subt[v];
  }
}

void solve () {
  int n, q; cin >> n >> q;
  int arr[n + 1]; 
  for (int i = 1; i <= n; i++) cin >> arr[i];
  for (int i = 1; i < n; i++) {
    int u, v; cin >> u >> v;
    adj[u].pb(v);
    adj[v].pb(u);
  }
  euler.pb(-1);
  dfs(1, 1);
  FenwickTree BIT(n);
  for (int i = 1; i <= n; i++) {
    BIT.add(idx_at_euler[i], arr[i]);
  }

  while (q--) {
    int type; cin >> type;
    if (type == 1) {
      int s, x; cin >> s >> x;
      BIT.add(idx_at_euler[s], -arr[s]);
      arr[s] = x;
      BIT.add(idx_at_euler[s], arr[s]);
    } else if (type == 2) {
      int s; cin >> s;
      int r = idx_at_euler[s] + subt[s] - 1;
      int l = idx_at_euler[s];
      cout << BIT.sum(l, r) << endl;
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
2 3
1 5 3
2 3
Output:
8
10
*/

/*
g++ -std=c++17 -O2 -Wall -DLOCAL "C:\Users\LENOVO\Desktop\BARKIN\Genel\Programming\Competitive\Questions\CSES\Tree_Algorithms\1137_subtree_queries.cpp" -o _run
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