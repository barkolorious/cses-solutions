// barkolorious - 22 November 2024
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

const int N = 1e3 + 5;
const int mod = 1e9 + 7;

void solve () {
  int n; cin >> n;
  int grid[n + 1][n + 1], dp[n + 1][n + 1]{};
  for (int y = 1; y <= n; y++) {
    for (int x = 1; x <= n; x++){
      char ch; cin >> ch;
      grid[x][y] = (ch == '.');
    }
  }
  dp[1][1] = grid[1][1];

  for (int x = 1; x <= n; x++) {
    for (int y = 1; y <= n; y++) {
      if (x == 1 && y == 1) continue;
      if (!grid[x][y]) continue;
      dp[x][y] = (dp[x - 1][y] + dp[x][y - 1]) % mod;
    }
  }
  
  cout << dp[n][n] << endl;
}

/*
-- Sample 1 --
Input:
4
....
.*..
...*
*...
Output:
3
*/

/*
g++ -std=c++17 -O2 -Wall -DLOCAL "C:\Users\LENOVO\Desktop\BARKIN\Genel\Programming\Competitive\Questions\CSES\Dynamic_Programming\1638_grid_paths.cpp" -o _run
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