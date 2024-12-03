// barkolorious - 21 September 2024
#include <bits/stdc++.h>
using namespace std;

#define FIN(x) freopen(x ".in", "r", stdin)
#define FOUT(x) freopen(x ".out", "w", stdout)
#define int long long
#define pb  push_back
#define fr  first
#define sc  second

const int N = 2e5 + 5;

/*
g++ -std=c++17 -O2 -Wall -DLOCAL "C:\Users\LENOVO\Desktop\BARKIN\Genel\Programming\Competitive\Questions\CSES\Sorting_and_Searching\1074_stick_lengths.cpp" -o _run
*/

void solve () {
  int n; cin >> n;
  int a[n];
  for (int& p_i : a) cin >> p_i;
  sort(a, a + n);
  if (n % 1) {
    int median = a[n / 2];
    int ans = 0;
    for (int i = 0; i < n; i++) ans += abs(a[i] - median);
    cout << ans << endl;
  } else {
    int median1 = a[n / 2], median2 = a[n / 2 - 1];
    int ans1 = 0, ans2 = 0;
    for (int i = 0; i < n; i++) {
      ans1 += abs(a[i] - median1);
      ans2 += abs(a[i] - median2);
    }
    cout << min(ans1, ans2) << endl;
  }
}

/*
-- Sample 1 --
Input:
5
2 3 1 5 2
Output:
5
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