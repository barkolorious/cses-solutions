#include <bits/stdc++.h>
using namespace std;

#define FIN(x) freopen((string(x) + ".in").c_str(), "r", stdin)
#define FOUT(x) freopen((string(x) + ".out").c_str(), "w", stdout)
#define int long long
#define pb  push_back
#define fr  first
#define sc  second

const int N = 2e5 + 5;

/*
g++ -std=c++17 -O2 -Wall -DLOCAL "1662_subarray_divisibility.cpp" -o _run
g++ -std=c++17 -O2 -Wall -DUSACO "1662_subarray_divisibility.cpp" -o _run
*/

int mod (int a, int m) {
  while (a < 0) a += m;
  return a % m;
}

void solve () {
  int n; cin >> n;
  int curr = 0, ans = 0;

  map<int, int> freq;
  freq[0] = 1;

  for (int i = 0; i < n; i++) {
    int a; cin >> a;
    curr += a;
    curr = mod(curr, n);
    ans += freq[curr];
    freq[curr]++;
  }
  
  cout << ans << endl;
  
}

/*
-- Sample 1 --
Input:
5
3 1 2 7 4
Output:
1
*/

int32_t main () {
  #ifndef LOCAL
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
  #endif

  #ifdef LOCAL
    clock_t __START__ = clock();

    FILE* __FILE_IN__ = FIN("_run");
    FILE* __FILE_OUT__ = FOUT("_run");
  #elif USACO
    FILE* __FILE_IN__ = FIN("wormsort");
    FILE* __FILE_OUT__ = FOUT("wormsort");
  #endif

  solve();

  #ifdef LOCAL
    fclose(__FILE_IN__);
    fclose(__FILE_OUT__);

    cerr << "Executed in: " << (double) (clock() - __START__) / CLOCKS_PER_SEC << "seconds" << endl;
  #elif USACO
    fclose(__FILE_IN__);
    fclose(__FILE_OUT__);
  #endif

  return 0;
}