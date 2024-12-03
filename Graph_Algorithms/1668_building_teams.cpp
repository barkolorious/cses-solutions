// barkolorious - 02 October 2024
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
int color[N], vis[N];

int dfs (int u, int clr = 0) {
  color[u] = clr;
  for (int v : adj[u]) {
    if (vis[v]) {
      if (color[v] != !clr) return -1;
      continue;
    }
    vis[v] = true;
    int ret = dfs(v, !clr);
    if (ret == -1) return -1;
  }
  return 1;
}

void solve () {
  int n, m; cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int u, v; cin >> u >> v;
    adj[u].pb(v);
    adj[v].pb(u);
  }

  for (int i = 1; i <= n; i++) {
    if (vis[i]) continue;
    int ret = dfs(i);
    if (ret == -1) {
      cout << "IMPOSSIBLE" << endl;
      return;
    }
  }
  
  for (int i = 1; i <= n; i++) cout << color[i] + 1 << " \n"[i == n];
}

/*
-- Sample 1 --
Input:
5 3
1 2
1 3
4 5
Output:
1 2 2 1 2
*/

/*
g++ -std=c++17 -O2 -Wall -DLOCAL "C:\Users\LENOVO\Desktop\BARKIN\Genel\Programming\Competitive\Questions\CSES\Graph_Algorithms\1668_building_teams.cpp" -o _run
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