// barkolorious - 11 December 2024
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
vector<vector<int>> adj;
vector<int> tin, euler, clr;
int n; 

struct FenwickTree {
  int n; vector<int> tree;

  FenwickTree (int __n) {
    n = __n;
    tree.assign(n + 1, 0);
  }

  void add (int idx, int val) {
    idx++;
    while (idx <= n) {
      tree[idx] += val;
      idx += idx & -idx;
    }
  }

  int prefix_sum (int idx) {
    idx++; int res = 0;
    while (idx) {
      res += tree[idx];
      idx -= idx & -idx;
    }
    return res;
  }

  int range_sum (int l, int r) {
    return prefix_sum(r) - prefix_sum(l - 1);
  }
};

void dfs (int u, int p) {
  tin[u] = euler.sz();
  for (int v : adj[u]) {
    if (v == p) continue;
    dfs(v, u);
  }
  euler.pb(u);
}

void solve () {
  cin >> n;
  tin.resize(n + 1);
  adj.resize(n + 1);
  clr.resize(n + 1);
  for (int i = 1; i <= n; i++) cin >> clr[i];
  for (int i = 1; i < n; i++) {
    int u, v; cin >> u >> v;
    adj[u].pb(v);
    adj[v].pb(u);
  }
  dfs(1, 1);
  map<int, int> last;
  int ans[n + 1];
  FenwickTree BIT(n);
  for (int i = 0; i < n; i++) {
    int node = euler[i];
    if (last.count(clr[node])) {
      BIT.add(last[clr[node]], -1);
    }
    last[clr[node]] = i;
    BIT.add(i, 1);
    
    ans[node] = BIT.range_sum(tin[node], i);
  }

  for (int i = 1; i <= n; i++) cout << ans[i] << " \n"[i == n];

}

/*
-- Sample 1 --
Input:
5
2 3 2 2 1
1 2
1 3
3 4
3 5
Output:
3 1 2 1 1
*/

/*
g++ -std=c++17 -O2 -Wall -DLOCAL "C:\Users\LENOVO\Desktop\BARKIN\Genel\Programming\Competitive\Questions\CSES\Tree_Algorithms\1139_distinct_colors.cpp" -o _run
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