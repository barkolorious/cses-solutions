// barkolorious - 09 October 2024
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
int n, subt[N], subl[N], parl[N], part[N];

void dfs1 (int v, int p) {
  subt[v] = 1;
  subl[v] = 0;
  for (int u : adj[v]) {
    if (u == p) continue;
    dfs1(u, v);
    subt[v] += subt[u];
    subl[v] += subl[u] + subt[u];
  }
}

void dfs2 (int v, int p) {
  for (int u : adj[v]) {
    if (u == p) continue;
    parl[u] = subl[v] - (subt[u] + subl[u]) + (subt[v] - subt[u]);
    if (p != -1) parl[u] += parl[v] + (subt[1] - subt[v]);
  }
  for (int u : adj[v]) {
    if (u == p) continue;
    dfs2(u, v);
  }
}

void solve () {
  cin >> n;
  for (int i = 1; i < n; i++) {
    int v, u; cin >> v >> u;
    adj[u].pb(v);
    adj[v].pb(u);
  }
  dfs1(1, -1);
  dfs2(1, -1);
  for (int i = 1; i <= n; i++) cout << subt[i] << " \n"[i == n];
  for (int i = 1; i <= n; i++) cout << subl[i] << " \n"[i == n];
  for (int i = 1; i <= n; i++) cout << parl[i] << " \n"[i == n];
  for (int i = 1; i <= n; i++) cout << subl[i] + parl[i] << " \n"[i == n];
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
6 9 5 8 8
*/

/*
g++ -std=c++17 -O2 -Wall -DLOCAL "C:\Users\LENOVO\Desktop\BARKIN\Genel\Programming\Competitive\Questions\CSES\Tree_Algorithms\1133_tree_distances_II.cpp" -o _run
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