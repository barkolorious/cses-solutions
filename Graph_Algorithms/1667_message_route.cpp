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

const int N = 1e5 + 5;
vector<int> adj[N];
int vis[N], par[N];
stack<int> route;

void solve () {
  int n, m; cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int u, v; cin >> u >> v;
    adj[u].pb(v);
    adj[v].pb(u);
  }
  queue<int> bfs;
  bfs.push(1);
  vis[1] = true;
  while (!bfs.empty()) {
    int u = bfs.front(); bfs.pop();
    for (int v : adj[u]) {
      if (vis[v]) continue;
      par[v] = u;
      vis[v] = true;
      bfs.push(v);
    }
  }
  if (!vis[n]) {
    cout << "IMPOSSIBLE" << endl;
    return;
  }
  int ptr = n;
  while (ptr != 1) {
    route.push(ptr);
    ptr = par[ptr];
  }
  route.push(1);
  cout << route.size() << endl;
  while (!route.empty()) {
    cout << route.top() << " ";
    route.pop();
  }
  cout << endl;
}

/*
-- Sample 1 --
Input:
5 5
1 2
1 3
1 4
2 3
5 4
Output:
3
1 4 5
*/

/*
g++ -std=c++17 -O2 -Wall -DLOCAL "C:\Users\LENOVO\Desktop\BARKIN\Genel\Programming\Competitive\Questions\CSES\Graph_Algorithms\1667_message_route.cpp" -o _run
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