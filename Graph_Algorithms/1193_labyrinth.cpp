// barkolorious - 01 December 2024
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

const int N = 1e3 + 5;
char grid[N][N];
int dist[N][N], vis[N][N], par[N][N];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
char steps[4] = {'D', 'U', 'R', 'L'};
int w, h;

#define check(x, y) ((1 <= x && x <= w) && (1 <= y && y <= h))

void solve () {
  cin >> h >> w;

  pair<int, int> A, B;
  for (int y = 1; y <= h; y++) {
    for (int x = 1; x <= w; x++) {
      cin >> grid[x][y];
      if (grid[x][y] == 'A') A = {x, y};
      if (grid[x][y] == 'B') B = {x, y};
    }
  }

  queue<pair<int, int>> bfs;
  bfs.push(A);
  vis[A.fr][A.sc] = true;

  while (!bfs.empty()) {
    int x = bfs.front().fr, y = bfs.front().sc;
    bfs.pop();

    for (int i = 0; i < 4; i++) {
      int xx = x + dx[i], yy = y + dy[i];

      if (!check(xx, yy)) continue;
      if (grid[xx][yy] == '#') continue;
      if (vis[xx][yy]) continue;

      vis[xx][yy] = true;
      par[xx][yy] = i;
      bfs.push({xx, yy});
    }
  }

  if (!vis[B.fr][B.sc]) {
    cout << "NO" << endl;
    return;
  }

  vector<int> route;
  pair<int, int> ptr = B;
  while (ptr != A) {
    int step = par[ptr.fr][ptr.sc];
    route.pb(step);
    ptr.fr -= dx[step];
    ptr.sc -= dy[step];
  }
  cout << "YES" << endl << route.size() << endl;
  for (int i = route.size() - 1; i >= 0; i--) cout << steps[route[i]];
  cout << endl;
}

/*
-- Sample 1 --
Input:
5 8
########
#.A#...#
#.##.#B#
#......#
########
Output:
YES
9
LDDRRRRRU
*/

/*
g++ -std=c++17 -O2 -Wall -DLOCAL "C:\Users\LENOVO\Desktop\BARKIN\Genel\Programming\Competitive\Questions\CSES\Graph_Algorithms\1193_labyrinth.cpp" -o _run
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