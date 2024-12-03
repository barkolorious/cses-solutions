// barkolorious - 29 November 2024
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
#define check_bit(a, i) (((a) & (1 << (i))) >> (i))

const int N = 25;
const int mod = 1e9 + 7;
vector<int> radj[N];

void solve () {
  int n, m; cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int v, u; cin >> v >> u;
    radj[u - 1].pb(v - 1);
  }
  int E = (1 << n);
  int dp[E][n]{};
  dp[1][0] = 1;
  for (int s = 0; s < E; s++) {
    if (!check_bit(s, 0)) continue;
    if (check_bit(s, n - 1) && s != E - 1) continue;
    for (int v = 0; v < n; v++) {
      if (!check_bit(s, v)) continue;
      for (int u : radj[v]) {
        if (!check_bit(s, u)) continue;
        dp[s][v] += dp[s ^ (1 << v)][u];
        dp[s][v] %= mod;
      }
    }
  }
  // for (int s = 0; s < E; s++) {
  //   for (int i = 0; i < n; i++) cout << dp[s][i] << " \n"[i == n - 1];
  // }
  cout << dp[E - 1][n - 1] << endl;
}

/*
-- Sample 1 --
Input:
4 6
1 2
1 3
2 3
3 2
2 4
3 4
Output:
2
*/

/*
g++ -std=c++17 -O2 -Wall -DLOCAL "C:\Users\LENOVO\Desktop\BARKIN\Genel\Programming\Competitive\Questions\CSES\Graph_Algorithms\1690_hamiltonian_flights.cpp" -o _run
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