// barkolorious - 06 October 2024
#include <bits/stdc++.h>
using namespace std;

#define FIN(x) freopen(x ".in", "r", stdin)
#define FOUT(x) freopen(x ".out", "w", stdout)
#define int long long
#define pb  push_back
#define fr  first
#define sc  second

const int N = 1e3 + 5;
int n, m;
char grid[N][N];
int vis[N][N];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

bool isGrid (int x, int y) {
  return (x > 0) && (x <= m) && (y > 0) && (y <= n);
}

void dfs (int x, int y) {
  vis[x][y] = true;
  for (int i = 0; i < 4; i++) {
    if (grid[x + dx[i]][y + dy[i]] == '#') continue;
    if (vis[x + dx[i]][y + dy[i]]) continue;
    if (isGrid(x + dx[i], y + dy[i])) dfs(x + dx[i], y + dy[i]);
  }
}

void solve () {
  cin >> n >> m;
  for (int y = 1; y <= n; y++) {
    for (int x = 1; x <= m; x++) {
      cin >> grid[x][y];
    }
  }

  int ans = 0;
  for (int y = 1; y <= n; y++) {
    for (int x = 1; x <= m; x++) {
      if (grid[x][y] == '#') continue;
      if (vis[x][y]) continue;
      dfs(x, y);
      ans++;
    }
  }
  
  cout << ans << endl;
}

/*
-- Sample 1 --
Input:
5 8
########
#..#...#
####.#.#
#..#...#
########
Output:
3
*/

/*
g++ -std=c++17 -O2 -Wall -DLOCAL "C:\Users\LENOVO\Desktop\BARKIN\Genel\Programming\Competitive\Questions\CSES\Graph_Algorithms\1192_counting_rooms.cpp" -o _run
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