// barkolorious - 08 December 2024
// in god, do we trust? 
#include <bits/stdc++.h>
using namespace std;

// #define USACO
#define FIN(x) freopen(x ".in", "r", stdin)
#define FOUT(x) freopen(x ".out", "w", stdout)
#define all(v) (v).begin(), (v).end()
#define int long long
#define pb  push_back
#define sz  size
#define fr  first
#define sc  second
#define __  << " " << 

struct Edge {
  int from, to, weight;

  bool operator< (const Edge& a) {
    return this->weight < a.weight;
  }
};

const int MAXN = 2e5 + 5;
int par[MAXN], cnt;
vector<Edge> edges;

void Make (int u) {
  par[u] = u;
}

int Find (int u) {
  if (par[u] == u) return u;
  return par[u] = Find(par[u]);
}

void Link (int u, int v) {
  if (Find(v) != Find(u)) cnt--;
  par[Find(v)] = Find(u);
}

void solve () {
  int n, m; cin >> n >> m;
  cnt = n;

  for (int i = 1; i <= n; i++) Make(i);

  for (int i = 0; i < m; i++) {
    int u, v, w; cin >> u >> v >> w;
    edges.pb({u, v, w});
  }

  sort(all(edges));

  int ans = 0;
  for (Edge edge : edges) {
    if (Find(edge.from) != Find(edge.to)) {
      ans += edge.weight;
      Link(edge.from, edge.to);
    }
  }

  if (cnt > 1) cout << "IMPOSSIBLE" << endl;
  else cout << ans << endl;
}

/*
-- Sample 1 --
Input:
5 6
1 2 3
2 3 5
2 4 2
3 4 8
5 1 7
5 4 4
Output:
14
*/

/*
g++ -std=c++17 -O2 -Wall -DLOCAL "C:\Users\LENOVO\Desktop\BARKIN\Genel\Programming\Competitive\Questions\CSES\Graph_Algorithms\1675_road_reparation.cpp" -o _run
*/

int32_t main () {
  #if !defined(LOCAL)
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
  #endif

  #if defined(LOCAL)
    clock_t __START__ = clock();
    FILE* __FILE_IN__ = FIN("C:/Users/LENOVO/Desktop/BARKIN/Genel/Programming/Competitive/_run");
    FILE* __FILE_OUT__ = FOUT("C:/Users/LENOVO/Desktop/BARKIN/Genel/Programming/Competitive/_run");
  #elif defined(USACO)
    FILE* __FILE_IN__ = FIN("usaco");
    FILE* __FILE_OUT__ = FOUT("usaco");
  #endif

  solve();

  #if defined(LOCAL)
    fclose(__FILE_IN__);
    fclose(__FILE_OUT__);
    cerr << "Executed in: " << fixed << setprecision(3) << (double) (clock() - __START__) / CLOCKS_PER_SEC << "seconds" << endl;
  #elif defined(USACO)
    fclose(__FILE_IN__);
    fclose(__FILE_OUT__);
  #endif

  return 0;
}