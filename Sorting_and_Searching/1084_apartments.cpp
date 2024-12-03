// barkolorious - 27 September 2024
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
g++ -std=c++17 -O2 -Wall -DLOCAL "C:\Users\LENOVO\Desktop\BARKIN\Genel\Programming\Competitive\Questions\CSES\Sorting_and_Searching\1084_apartments.cpp" -o _run
*/

void solve () {
  int n, m, k; cin >> n >> m >> k;
  multiset<int> a, b;
  for (int i = 0; i < n; i++) {
    int ai; cin >> ai;
    a.insert(ai);
  }
  for (int i = 0; i < m; i++) {
    int bi; cin >> bi;
    b.insert(bi);
  }
  auto itr = a.begin();
  int ans = 0;
  for (; itr != a.end(); itr++) {
    int x = *itr;
    auto itr2 = b.lower_bound(x - k);
    if (abs(x - *itr2) <= k) {
      ans++;
      b.erase(itr2);
    }
  }
  cout << ans << endl;
}

/*
-- Sample 1 --
Input:
4 3 5
60 45 80 60
30 60 75
Output:
2
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