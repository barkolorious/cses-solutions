// barkolorious - 08 October 2024
#include <bits/stdc++.h>
using namespace std;

#define FIN(x) freopen(x ".in", "r", stdin)
#define FOUT(x) freopen(x ".out", "w", stdout)
#define int long long
#define pb  push_back
#define fr  first
#define sc  second

const int N = 2e5 + 5;
vector<int> adj[N];
int n;
pair<int, int> max1[N], max2[N];
int ans[N];

void dfs1 (int u, int p) {
  max1[u] = max2[u] = {0, u};
  for (int v : adj[u]) {
    if (v == p) continue;
    dfs1(v, u);
    if (max1[v].fr + 1 > max1[u].fr) {
      max2[u] = max1[u];
      max1[u] = {max1[v].fr + 1, v};
    } else if (max1[v].fr + 1 > max2[u].fr) {
      max2[u] = {max1[v].fr + 1, v};
    }
  }
}

void dfs2 (int u, int p) {
  for (int v : adj[u]) {
    if (v == p) continue;
    if (max1[u].sc == v) {
      if (max1[v].fr < max2[u].fr + 1) {
        max2[v] = max1[v];
        max1[v] = {max2[u].fr + 1, u};
      } else if (max2[v].fr < max2[u].fr + 1) {
        max2[v] = {max2[u].fr + 1, u};
      }
    } else {
      max2[v] = max1[v];
      max1[v] = {max1[u].fr + 1, u};
    }
    dfs2(v, u);
  }
}

void solve () {
  cin >> n;
  for (int i = 1; i < n; i++) {
    int u, v; cin >> u >> v;
    adj[u].pb(v);
    adj[v].pb(u);
  }
  dfs1(1, -1);
  dfs2(1, -1);
  for (int i = 1; i <= n; i++) cout << max1[i].fr << " \n"[i == n];

}

/*
-- Sample 1 --
Input:
5
1 2
1 3
3 4
3 5
Output:
2 3 2 3 3
*/

/*
g++ -std=c++17 -O2 -Wall -DLOCAL "C:\Users\LENOVO\Desktop\BARKIN\Genel\Programming\Competitive\Questions\CSES\Tree_Algorithms\1132_tree_distances_I.cpp" -o _run
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