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
g++ -std=c++17 -O2 -Wall -DLOCAL "C:\Users\LENOVO\Desktop\BARKIN\Genel\Programming\Competitive\Questions\CSES\Sorting_and_Searching\1163_traffic_lights.cpp" -o _run
*/

void solve () {
  int n, x; cin >> x >> n;

  int a[n];
  for (int& p : a) cin >> p;

  set<pair<int, pair<int, int>>> passages;
  set<int> lights;

  passages.insert({x, {0, x}});
  lights.insert(0); lights.insert(x);

  for (int i = 0; i < n; i++) {
    auto Upper = lights.upper_bound(a[i]);
    auto Lower = --Upper;
    int upper = *++Upper;
    int lower = *Lower;

    passages.erase({upper - lower, {lower, upper}});
    passages.insert({a[i] - lower, {lower, a[i]}});
    passages.insert({upper - a[i], {a[i], upper}});
    
    cout << passages.rbegin()->fr << " ";
    lights.insert(a[i]);
  }
  cout << endl;
}

/*
-- Sample 1 --
Input:
8 3
3 6 2
Output:
5 3 3
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