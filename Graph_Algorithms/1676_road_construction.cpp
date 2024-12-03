// barkolorious - 02 December 2024
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
int par[N], sz[N];
int comp_num, max_comp = 1;

void Make (int u) {
  par[u] = u;
  sz[u] = 1;
}

int Find (int u) {
  if (par[u] == u) return u;
  return par[u] = Find(par[u]);
}

int Size (int u) {
  return sz[Find(u)];
}

void Link (int u, int v) {
  u = Find(u), v = Find(v);
  par[v] = u;
  sz[u] += sz[v];
  max_comp = max(max_comp, sz[u]);
}

void solve () {
  int n, m; cin >> n >> m;
  comp_num = n;
  for (int i = 1; i <= n; i++) Make(i);
  for (int i = 0; i < m; i++) {
    int u, v; cin >> u >> v;
    if (Find(u) != Find(v)) {
      comp_num--;
      Link(u, v);
    }
    cout << comp_num __ max_comp << endl;
  }
}

/*
-- Sample 1 --
Input:
5 3
1 2
1 3
4 5
Output:
4 2
3 3
2 3
*/

/*
g++ -std=c++17 -O2 -Wall -DLOCAL "C:\Users\LENOVO\Desktop\BARKIN\Genel\Programming\Competitive\Questions\CSES\Graph_Algorithms\1676_road_construction.cpp" -o _run
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