// barkolorious - 03 December 2024
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

const int N = 1e5 + 5;
vector<int> adj[N];
vector<int> cycle;
int n, m;
int vis[N], on_stack[N];

bool dfs (int u) {
	vis[u] = on_stack[u] = true;
  for (int v : adj[u]) {
    if (on_stack[v]) {
      cycle.pb(u);
      on_stack[u] = on_stack[v] = false;
      return true;
    } else if (!vis[v]) {
      if (dfs(v)) {
        if (on_stack[u]) {
          cycle.pb(u);
          on_stack[u] = false;
          return true;
        } else {
          cycle.pb(u);
          return false;
        }
      }

      if (!cycle.empty()) return false;
    }
  }

  on_stack[u] = false;
  return false;
}

void solve () {
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int u, v; cin >> u >> v;
    adj[u].pb(v);
  }
  
  for (int i = 1; cycle.empty() && i <= n; i++) { dfs(i); }

  if (cycle.empty()) {
    cout << "IMPOSSIBLE" << endl;
    return;
  } else {
		reverse(cycle.begin(), cycle.end());
    cout << cycle.size() + 1 << endl;
    for (int u : cycle) cout << u << " ";
    cout << cycle[0] << endl;
  }
}

/*
-- Sample 1 --
Input:
4 5
1 3
2 1
2 4
3 2
3 4
Output:
4
2 1 3 2
*/

/*
g++ -std=c++17 -O2 -Wall -DLOCAL "C:\Users\LENOVO\Desktop\BARKIN\Genel\Programming\Competitive\Questions\CSES\Graph_Algorithms\1678_round_trip_II.cpp" -o _run
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