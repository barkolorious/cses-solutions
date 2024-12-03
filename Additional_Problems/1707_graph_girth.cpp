// barkolorious - 01 December 2024
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

const int N = 2505;
vector<int> adj[N];
int depth[N];

int bfs (int root) {
  memset(depth, -1, sizeof(depth));

  queue<int> q; 

  q.push(root);
  depth[root] = 0;

  int ans = INT_MAX;

  while (!q.empty()) {
    int u = q.front(); 
    q.pop();

    for (int v : adj[u]) {
      if (depth[v] == -1) {
        depth[v] = depth[u] + 1;
        q.push(v);
      } else if (depth[u] <= depth[v]) {
        ans = min(ans, depth[u] + depth[v] + 1);
      }
    }
  }
  return ans;
}

void solve () {
  int n, m; cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int u, v; cin >> u >> v;
    adj[u].pb(v);
    adj[v].pb(u);
  }

  int ans = INT_MAX;
  for (int i = 1; i <= n; i++) ans = min(ans, bfs(i));
  cout << ((ans == INT_MAX) ? -1 : ans) << endl;  
}

/*
-- Sample 1 --
Input:
5 6
1 2
1 3
2 4
2 5
3 4
4 5
Output:
3
*/

/*
g++ -std=c++17 -O2 -Wall -DLOCAL "C:\Users\LENOVO\Desktop\BARKIN\Genel\Programming\Competitive\Questions\CSES\Additional_Problems\1707_graph_girth.cpp" -o _run
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