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
#define flip_bit(a, i) ((a) ^ (1 << (i)))

const int N = 2e5 + 5;

void solve () {
  int n, x; cin >> n >> x;
  int w[n];
  for (int i = 0; i < n; i++) cin >> w[i];
  int E = (1 << n);
  pair<int, int> dp[E];
  dp[0] = {1, 0};
  for (int s = 1; s < E; s++) {
    dp[s] = {n + 1, 0};
    for (int i = 0; i < n; i++) {
      if (!check_bit(s, i)) continue;
      auto last = dp[flip_bit(s, i)];
      if (w[i] + last.sc <= x) last.sc += w[i];
      else { last.fr++; last.sc = w[i]; }
      dp[s] = min(dp[s], last);
    }
  }
  cout << dp[E - 1].fr << endl;
}

/*
-- Sample 1 --
Input:
4 10
4 8 6 1
Output:
2
*/

/*
g++ -std=c++17 -O2 -Wall -DLOCAL "C:\Users\LENOVO\Desktop\BARKIN\Genel\Programming\Competitive\Questions\CSES\Dynamic_Programming\1653_elevator_rides.cpp" -o _run
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