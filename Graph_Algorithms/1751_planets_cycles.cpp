// barkolorious - 11 October 2024
#include <bits/stdc++.h>
using namespace std;

#define FIN(x) freopen(x ".in", "r", stdin)
#define FOUT(x) freopen(x ".out", "w", stdout)
#define int long long
#define pb  push_back
#define fr  first
#define sc  second

const int N = 2e5 + 5;
int n, t[N], ans[N];
bool vis[N];
vector<int> rt[N];

void back_propagation (int a, int d, bool is_root) {
  if (!is_root && vis[a]) return;
  vis[a] = true;
  ans[a] = d;
  for (int b : rt[a]) {
    back_propagation(b, d + 1, 0);
  }
}

int cycle (int a, int b, int d) {
  vis[a] = true;
  if (a != b) ans[a] = cycle(t[a], b, d + 1); 
  else ans[a] = d;
  back_propagation(a, ans[a], 1);
  return ans[a];
}

void solve () {
  cin >> n;
  for (int i = 1; i <= n; i++) { cin >> t[i]; rt[t[i]].pb(i); }
  for (int i = 1; i <= n; i++) {
    if (vis[i]) continue;
    int a = i, b = i;
    do a = t[a], b = t[t[b]]; while (a != b);
    cycle(t[a], b, 1);

    // cout << i << endl;
    // for (int j = 1; j <= n; j++) cout << vis[j] << " \n"[j == n];
    // for (int j = 1; j <= n; j++) cout << ans[j] << " \n"[j == n];
  }
  
  for (int j = 1; j <= n; j++) cout << ans[j] << " \n"[j == n];
}

/*
-- Sample 1 --
Input:
5
2 4 3 1 4
Output:
3 3 1 3 4
*/

/*
g++ -std=c++17 -O2 -Wall -DLOCAL "C:\Users\LENOVO\Desktop\BARKIN\Genel\Programming\Competitive\Questions\CSES\Graph_Algorithms\1751_planets_cycles.cpp" -o _run
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