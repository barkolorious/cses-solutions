// barkolorious - 30 November 2024
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

const int N = 5e2 + 5;
const int mod = 1e9 + 7;
const int phi = mod - 1;

int fac[N], inv[N];
int dp[N][N];

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

void precalc () {
  fac[0] = 1;
  for (int i = 1; i < N; i++) fac[i] = fac[i - 1] * i % mod;
  inv[N - 1] = pwr(fac[N - 1], mod - 2);
  for (int i = N - 2; i >= 0; i--) inv[i] = inv[i + 1] * (i + 1) % mod;
}

int comb (int n, int k) {
  return fac[n] * inv[k] % mod * inv[n - k] % mod;
}


void solve () {
  precalc();

  string s; cin >> s;
  int n = s.length();

  for (int i = 0; i <= n; i++) dp[i][i] = 1;

  for (int len = 2; len <= n; len += 2) {
    for (int start = 0; start <= n - len; start++) {
      int end = start + len;
      dp[start][end] = dp[start][end - 1];

      for (int mid = start + 1; mid < end; mid += 2) {
        if (s[mid] == s[start]) {
          int temp = dp[start + 1][mid] * dp[mid + 1][end] % mod;
          temp = temp * comb(len / 2, (mid - start + 1) / 2) % mod;
          dp[start][end] = (dp[start][end] + temp) % mod;
        }
      } 
    }
  }

  // for (int start = 0; start <= n; start++) {
  //   for (int end = 0; end <= n; end++) cout << dp[start][end] << " \n"[end == n];
  // }
  cout << dp[0][n] << endl;
}

/*
-- Sample 1 --
Input:
aabccb
Output:
3
*/

/*
g++ -std=c++17 -O2 -Wall -DLOCAL "C:\Users\LENOVO\Desktop\BARKIN\Genel\Programming\Competitive\Questions\CSES\Additional_Problems\1080_empty_string.cpp" -o _run
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