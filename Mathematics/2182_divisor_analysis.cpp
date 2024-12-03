// barkolorious - 19 November 2024
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
const int mod = 1e9 + 7;
const int phi = mod - 1;

int pwr (int x, int y) {
  int res = 1;
  x %= mod;
  while (y) {
    if (y & 1) res = res * x % mod;
    x = x * x % mod;
    y >>= 1; 
  }
  return res;
}

void ext (int a, int b, int& x, int& y) {
  if (!b) { x = 1, y = 0; return; }
  ext(b, a % b, x, y);
  int new_x = y, new_y = x - (a / b) * y;
  x = new_x;
  y = new_y;
}

int inverse (int a, int m) {
  int x = 0, y = 0;
  ext(a, m, x, y);
  return (x + m) % m;
}

void solve () {
  int n; cin >> n;
  int num = 1, sum = 1, prod = 1, prod_power = 1;
  for (int i = 0; i < n; i++) {
    int x, k; cin >> x >> k;
    num = num * (k + 1) % mod;
    sum = sum * (((pwr(x, k + 1) - 1 + mod) % mod) * inverse((x - 1 + mod) % mod, mod) % mod) % mod;
    prod = pwr(prod, k + 1) * pwr(pwr(x, k * (k + 1) / 2), prod_power) % mod;
    prod_power = prod_power * (k + 1) % phi;
  }
  cout << num __ sum __ prod << endl;
  // cout << number __ prod_power << endl;
}

/*
-- Sample 1 --
Input:
2
2 2
3 1
Output:
6 28 1728
*/

/*
g++ -std=c++17 -O2 -Wall -DLOCAL "C:\Users\LENOVO\Desktop\BARKIN\Genel\Programming\Competitive\Questions\CSES\Mathematics\2182_divisor_analysis.cpp" -o _run
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