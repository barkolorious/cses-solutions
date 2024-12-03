// barkolorious - 28 November 2024
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
  int n; cin >> n;
  int a[n];
  for (int i = 0; i < n; i++) cin >> a[i];
  int dp[n + 1];
  for (int i = 0; i <= n; i++) dp[i] = INT_MAX;
  dp[0] = INT_MIN;
  
  for (int i = 0; i < n; i++) {
    int l = upper_bound(dp, dp + n + 1, a[i]) - dp;
    if (dp[l - 1] < a[i] && a[i] < dp[l]) dp[l] = a[i];
  }

  int ans = 0;
  for (int l = 0; l <= n; l++) if (dp[l] < INT_MAX) ans = l;
  cout << ans << endl;
}

/* Alternate Solution */

// int find_lis(const vector<int> &a) {
// 	vector<int> dp;
// 	for (int i : a) {
// 		int pos = lower_bound(dp.begin(), dp.end(), i) - dp.begin();
// 		if (pos == dp.size()) {
// 			// we can have a new, longer increasing subsequence!
// 			dp.push_back(i);
// 		} else {
// 			// oh ok, at least we can make the ending element smaller
// 			dp[pos] = i;
// 		}
// 	}
// 	return dp.size();
// }


/*
-- Sample 1 --
Input:
8
7 3 5 3 6 2 9 8
Output:
4
*/

/*
g++ -std=c++17 -O2 -Wall -DLOCAL "C:\Users\LENOVO\Desktop\BARKIN\Genel\Programming\Competitive\Questions\CSES\Dynamic_Programming\1145_increasing_subsequence.cpp" -o _run
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