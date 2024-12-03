// barkolorious - 03 September 2024
#include <bits/stdc++.h>
using namespace std;

#define FIN(x) freopen((string(x) + ".in").c_str(), "r", stdin)
#define FOUT(x) freopen((string(x) + ".out").c_str(), "w", stdout)
#define int long long
#define pb  push_back
#define fr  first
#define sc  second

const int N = 2e5 + 5;

/*
g++ -std=c++17 -O2 -Wall -DLOCAL "1660_subarray_sum_I.cpp" -o _run
*/

void solve () {
  int n, x; cin >> n >> x;
  int a[n]; 
  for (int i = 0; i < n; i++) cin >> a[i];
  int j = -1, curr = 0, ans = 0;
  for (int i = 0; i < n; i++) {
    curr += a[i];
    while (curr > x) {
      curr -= a[++j];
    }
    if (curr == x) ans++;
  }
  cout << ans << endl;
}

/*
-- Sample 1 --
Input:
5 7
2 4 1 2 7
Output:
3
*/

int32_t main () {
  #ifndef LOCAL
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
  #endif

  #ifdef LOCAL
    clock_t __START__ = clock();
    FILE* __FILE_IN__ = FIN("_run");
    FILE* __FILE_OUT__ = FOUT("_run");
  #else
    #ifndef ONLINE_JUDGE
      FILE* __FILE_IN__ = FIN("_run");
      FILE* __FILE_OUT__ = FOUT("_run");
    #endif
  #endif

  solve();

  #ifdef LOCAL
    fclose(__FILE_IN__);
    fclose(__FILE_OUT__);
    cerr << "Executed in: " << (double) (clock() - __START__) / CLOCKS_PER_SEC << "seconds" << endl;
  #else
    #ifndef ONLINE_JUDGE
      fclose(__FILE_IN__);
      fclose(__FILE_OUT__);
    #endif
  #endif

  return 0;
}