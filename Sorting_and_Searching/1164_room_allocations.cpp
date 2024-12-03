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
g++ -std=c++17 -O2 -Wall -DLOCAL "C:\Users\LENOVO\Desktop\BARKIN\Genel\Programming\Competitive\Questions\CSES\Sorting_and_Searching\1164_room_allocations.cpp" -o _run
*/

void solve () {
  int n; cin >> n;
  map<int, pair<vector<int>, vector<int>>> timeline; // time - {new ids, old ids}
  for (int i = 1; i <= n; i++) {
    int a, b; cin >> a >> b;
    timeline[a].fr.pb(i);
    timeline[b].sc.pb(i);
  }
  int max_costumor = 0, curr = 0;
  for (auto t : timeline) {
    curr += t.sc.fr.size();
    max_costumor = max(max_costumor, curr);
    curr -= t.sc.sc.size();
  }
  set<int> rooms; int ans[n + 1]{};

  for (int i = 1; i <= n; i++) rooms.insert(i);

  for (auto t : timeline) {
    for (int id : t.sc.fr) {
      ans[id] = *rooms.begin();
      rooms.erase(rooms.begin());
    }
    for (int id : t.sc.sc) {
      rooms.insert(ans[id]);
    }
  }
  cout << max_costumor << endl;
  for (int i = 1; i <= n; i++) cout << ans[i] << " \n"[i == n];
}

/*
-- Sample 1 --
Input:
3
1 2
2 4
4 4
Output:
2
1 2 1
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