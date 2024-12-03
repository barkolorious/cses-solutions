// barkolorious - 02 October 2024
#include <bits/stdc++.h>
using namespace std;

#define FIN(x) freopen(x ".in", "r", stdin)
#define FOUT(x) freopen(x ".out", "w", stdout)
#define int long long
#define pb  push_back
#define fr  first
#define sc  second

const int N = 2e5 + 5;

int par[N];

void Make (int u) {
  par[u] = u;
}

int Find (int u) {
  if (par[u] == u) return par[u];
  return par[u] = Find(par[u]);
}

void Union (int u, int v) {
  u = Find(u), v = Find(v);
  par[u] = v;
}

void solve () {
  int n, m; cin >> n >> m;
  for (int i = 1; i <= n; i++) Make(i);
  for (int i = 1; i <= m; i++) {
    int a, b; cin >> a >> b;
    Union(a, b);
  }
  set<int> roots;
  for (int i = 1; i <= n; i++)
    if (i == par[i])
      roots.insert(i);

  cout << roots.size() - 1 << endl;
  auto itr = roots.begin();
  for (; next(itr) != roots.end(); itr++) {
    cout << *itr << " " << *next(itr) << endl;
  }
}

/*
-- Sample 1 --
Input:
4 2
1 2
3 4
Output:
1
2 3
*/

/*
g++ -std=c++17 -O2 -Wall -DLOCAL "C:\Users\LENOVO\Desktop\BARKIN\Genel\Programming\Competitive\Questions\CSES\Graph_Algorithms\1666_building_roads.cpp" -o _run
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