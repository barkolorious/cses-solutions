// barkolorious - 03 December 2024
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

const int N = 1e5 + 5;
vector<int> adj[N];
vector<int> topo_sort;
int n, m;
int vis[N];

void dfs (int u) {
  for (int v : adj[u]) {
    if (vis[v]) continue;
    vis[v] = true;
    dfs(v);
  }
  topo_sort.pb(u);
}

void solve () {
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int u, v; cin >> u >> v;
    adj[u].pb(v);
  }
  for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			vis[i] = true;
			dfs(i);
		}
	}

  reverse(topo_sort.begin(), topo_sort.end());

  int idx[n + 1];
  for (int i = 0; i < n; i++) idx[topo_sort[i]] = i + 1;

  for (int u = 1; u <= n; u++) {
    for (int v : adj[u]) {
      if (idx[v] <= idx[u]) {
        cout << "IMPOSSIBLE" << endl;
        return;
      }
    }
  }
  for (int i = 0; i < n; i++) cout << topo_sort[i] << " \n"[i == n - 1];
}

/*
-- Sample 1 --
Input:
5 3
1 2
3 1
4 5
Output:
3 4 1 5 2
*/

/*
g++ -std=c++17 -O2 -Wall -DLOCAL "C:\Users\LENOVO\Desktop\BARKIN\Genel\Programming\Competitive\Questions\CSES\Graph_Algorithms\1679_course_schedule.cpp" -o _run
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