// barkolorious - 26 September 2024
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
g++ -std=c++17 -O2 -Wall -DLOCAL "C:\Users\LENOVO\Desktop\BARKIN\Genel\Programming\Competitive\Questions\CSES\Sorting_and_Searching\1632_movie_festival_II.cpp" -o _run
*/

void solve () {
  int n, k; cin >> n >> k;
  vector<pair<int, int>> movies;
  for (int i = 0; i < n; i++) {
    int a, b; cin >> a >> b;
    movies.pb({b, a});
  }
  sort(movies.begin(), movies.end());
  multiset<pair<int, int>> ms;
  for (int i = 0; i < k; i++) ms.insert({0, 0});
  for (int i = 0; i < n; i++) {
    if (ms.empty()) {
      ms.insert({-movies[i].fr, -1});
    } else {
      auto itr = ms.upper_bound({-movies[i].sc, -n});
      int count = 0;
      if (itr == ms.end()) continue;
      count += -itr->sc;
      ms.erase(itr);
      ms.insert({-movies[i].fr, -(count + 1)});
    }
  }
  auto itr = ms.begin(); int ans = 0;
  for (int i = 0; i < k && itr != ms.end(); i++) {
    ans += -itr->sc;
    itr++;
  }
  cout << ans << endl;
}

/*
-- Sample 1 --
Input:
5 2
1 5
8 10
3 6
2 5
6 9
Output:
4
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