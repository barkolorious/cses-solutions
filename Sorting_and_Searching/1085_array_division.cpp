// barkolorious - 29 September 2024
#include <bits/stdc++.h>
using namespace std;

#define FIN(x) freopen(x ".in", "r", stdin)
#define FOUT(x) freopen(x ".out", "w", stdout)
#define int long long
#define pb  push_back
#define fr  first
#define sc  second

const int N = 2e5 + 5;
int x[N], n, k;

/*
g++ -std=c++17 -O2 -Wall -DLOCAL "C:\Users\LENOVO\Desktop\BARKIN\Genel\Programming\Competitive\Questions\CSES\Sorting_and_Searching\1085_array_division.cpp" -o _run
*/

bool check (int sum) {
  int curr = 0, sub = 0;

  for (int i = 0; i < n; i++) {
    if (x[i] > sum) return false;
  
    if (curr + x[i] > sum) {
      sub++;
      curr = x[i];
    } else { 
      curr += x[i];
    }
  }
  if (curr > 0) sub++;

  return sub <= k;
}

void solve () {
  cin >> n >> k;
  int total = 0;
  for (int i = 0; i < n; i++) { cin >> x[i]; total += x[i]; }

  int l = 0, r = total;

  while (l < r) {
    int m = (l + r) / 2;
    if (check(m)) r = m;
    else l = m + 1;
  }
  
  cout << l << endl;
}

/*
-- Sample 1 --
Input:
5 3
2 4 7 3 5
Output:
8
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