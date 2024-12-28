// barkolorious - 09 December 2024
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

const int MAXN = 2e5 + 5;

void solve () {
  int n; cin >> n;
  stack<pair<int, int>> st;
  st.push({0, 0});
  for (int i = 1; i <= n; i++) {
    int a; cin >> a;
    while (!st.empty() && st.top().fr >= a) st.pop();
    cout << st.top().sc << " \n"[i == n];
    st.push({a, i});
  }
}

/*
-- Sample 1 --
Input:
8
2 5 1 4 8 3 2 5
Output:
0 1 0 3 4 3 3 7
*/

/*
g++ -std=c++17 -O2 -Wall -DLOCAL "C:\Users\LENOVO\Desktop\BARKIN\Genel\Programming\Competitive\Questions\CSES\Sorting_and_Searching\1645_nearest_smaller_values.cpp" -o _run
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