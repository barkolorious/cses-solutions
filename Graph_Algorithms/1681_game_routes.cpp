// barkolorious - 04 December 2024
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
const int mod = 1e9 + 7;
vector<int> adj[N], radj[N];
int dp[N], in_deg[N];

void solve () {
  int n, m; cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int u, v; cin >> u >> v;
    adj[u].pb(v);
    radj[v].pb(u);
    in_deg[v]++;
  }
  vector<int> topo;
  queue<int> q;
  
  for (int i = 1; i <= n; i++) if (in_deg[i] == 0) q.push(i);
  dp[1] = 1;

  while (!q.empty()) {
    int u = q.front(); q.pop();
    topo.pb(u);
    for (int v : adj[u]) if (--in_deg[v] == 0) q.push(v);
  }

  for (int u : topo) {
    for (int v : adj[u]) {
      dp[v] = (dp[v] + dp[u]) % mod;
    }
  }

  cout << dp[n] << endl;
}

/*
-- Sample 1 --
Input:
4 5
1 2
2 4
1 3
3 4
1 4
Output:
3
*/

/*
g++ -std=c++17 -O2 -Wall -DLOCAL "C:\Users\LENOVO\Desktop\BARKIN\Genel\Programming\Competitive\Questions\CSES\Graph_Algorithms\1681_game_routes.cpp" -o _run
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