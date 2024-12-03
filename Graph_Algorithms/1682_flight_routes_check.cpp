// barkolorious - 04 October 2024
#include <bits/stdc++.h>
using namespace std;

#define FIN(x) freopen(x ".in", "r", stdin)
#define FOUT(x) freopen(x ".out", "w", stdout)
#define int long long
#define pb  push_back
#define fr  first
#define sc  second

const int N = 2e5 + 5;
int n, m; 

vector<int> adj[N], radj[N];
int vis[N];

void dfs (int u) {
  vis[u] = true;
  for (int v : adj[u]) {
    if (vis[v]) continue;
    dfs(v);
  }
}

void rdfs (int u) {
  vis[u] = true;
  for (int v : radj[u]) {
    if (vis[v]) continue;
    rdfs(v);
  }
}

void solve () {
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int u, v; cin >> u >> v;
    adj[u].pb(v);
    radj[v].pb(u);
  }

  dfs(1);
  for (int i = 2; i <= n; i++) {
    if (vis[i]) continue;
    cout << "NO\n1 " << i << endl;
    return;
  }

  for (int i = 1; i <= n; i++) vis[i] = 0;

  rdfs(1);
  for (int i = 2; i <= n; i++) {
    if (vis[i]) continue;
    cout << "NO\n" << i << " 1" << endl;
    return;
  }
  cout << "YES" << endl;
}

/*
-- Sample 1 --
Input:
4 5
1 2
2 3
3 1
1 4
3 4
Output:
NO
4 2
*/

/*
g++ -std=c++17 -O2 -Wall -DLOCAL "C:\Users\LENOVO\Desktop\BARKIN\Genel\Programming\Competitive\Questions\CSES\Graph_Algorithms\1682_flight_routes_check.cpp" -o _run
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