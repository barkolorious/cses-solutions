// barkolorious - 10 October 2024
#include <bits/stdc++.h>
using namespace std;

#define FIN(x) freopen(x ".in", "r", stdin)
#define FOUT(x) freopen(x ".out", "w", stdout)
#define int long long
#define pb  push_back
#define fr  first
#define sc  second

const int N = 2e5 + 5;
int n, included[N];
vector<int> adj[N];
int ans = 0;

void dfs (int u, int p) {
  for (int v : adj[u]) {
    if (v == p) continue;
    dfs(v, u);
    if (!included[v] && !included[u]) {
      included[u] = included[v] = true;
      ans++;
    }
  }
}

void solve () {
  cin >> n;
  for (int i = 1; i < n; i++) {
    int v, u; cin >> v >> u;
    adj[v].pb(u);
    adj[u].pb(v);
  }
  dfs(1, -1);
  cout << ans << endl;
} 

/* Alternate Solution */

// const int N = 2e5 + 5;
// int n, dp[2][N];
// vector<int> adj[N];

// void dfs (int u, int p) {
//   for (int v : adj[u]) {
//     if (v == p) continue;
//     dfs(v, u);
//     dp[0][u] += max(dp[0][v], dp[1][v]);
//   }
//   for (int v : adj[u]) {
//     if (v == p) continue;
//     dp[1][u] = max(dp[1][u], dp[0][v] + 1 + dp[0][u] - max(dp[0][v], dp[1][v]));
//   }
// }

// void solve () {
//   cin >> n;
//   for (int i = 1; i < n; i++) {
//     int v, u; cin >> v >> u;
//     adj[v].pb(u);
//     adj[u].pb(v);
//   }
//   dfs(1, -1);
//   cout << max(dp[0][1], dp[1][1]) << endl;
// } 

/*
-- Sample 1 --
Input:
5
1 2
1 3
3 4
3 5
Output:
2
*/

/*
g++ -std=c++17 -O2 -Wall -DLOCAL "C:\Users\LENOVO\Desktop\BARKIN\Genel\Programming\Competitive\Questions\CSES\Tree_Algorithms\1130_tree_matching.cpp" -o _run
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