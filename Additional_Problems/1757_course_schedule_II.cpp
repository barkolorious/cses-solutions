// barkolorious - 07 December 2024
// in god, do we trust? 
#include <bits/stdc++.h>
using namespace std;

#define FIN(x) freopen(x ".in", "r", stdin)
#define FOUT(x) freopen(x ".out", "w", stdout)
#define all(v) (v).begin(), (v).end()
#define int long long
#define pb  push_back
#define sz  size
#define fr  first
#define sc  second
#define __  << " " << 

const int N = 2e5 + 5;
vector<int> adj[N], radj[N];
int outdeg[N];

void solve () {
  int n, m; cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int u, v; cin >> u >> v;
    adj[u].pb(v);
    radj[v].pb(u);
    outdeg[u]++;
  }
  
  vector<int> topo;
  priority_queue<int> pq;
  for (int i = 1; i <= n; i++) 
    if (outdeg[i] == 0) pq.push(i);

  while (!pq.empty()) {
    int u = pq.top(); pq.pop();
    topo.pb(u);
    for (int v : radj[u]) {
      if (--outdeg[v] == 0) pq.push(v);
    }
  }
  reverse(all(topo));

  for (int u : topo) cout << u << " ";
  

  cout.flush();
}

/*
-- Sample 1 --
Input:
4 2
2 1
2 3
Output:
2 1 3 4
*/

/*
g++ -std=c++17 -O2 -Wall -DLOCAL "C:\Users\LENOVO\Desktop\BARKIN\Genel\Programming\Competitive\Questions\CSES\Additional_Problems\1757_course_schedule_II.cpp" -o _run
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