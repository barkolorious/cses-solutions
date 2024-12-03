// barkolorious - 24 November 2024
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

void solve () {
  string s, t; cin >> s >> t;
  int n = s.length(), m = t.length();

  int dp[n + 1][m + 1];
  for (int i = 0; i <= max(n, m); i++) dp[min(i, n)][0] = dp[0][min(i, m)] = 0;

  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= m; j++) {
      if (!i && !j) continue;
      if (s[i - 1] == t[j - 1]) dp[i][j] = dp[i - 1][j - 1]; 
      else {
        dp[i][j] = INT_MAX;
        if (i) dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1);
        if (j) dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);
        if (i && j) dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + 1);
      }
    }
  }

  cout << dp[n][m] << endl;
}

/*
-- Sample 1 --
Input:
LOVE
MOVIE
Output:
2
*/

/*
g++ -std=c++17 -O2 -Wall -DLOCAL "C:\Users\LENOVO\Desktop\BARKIN\Genel\Programming\Competitive\Questions\CSES\Dynamic_Programming\1639_edit_distance.cpp" -o _run
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