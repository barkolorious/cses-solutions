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
const int mod = 1e9 + 7;

struct FenwickTree {
  int n;
  vector<int> tree;

  FenwickTree (int __n) {
    n = __n;
    tree.assign(n + 1, 0);
  }

  void add (int idx, int val) {
    while (idx <= n) {
      tree[idx] = (tree[idx] + val) % mod;
      idx += (idx & -idx);
    }
  }

  int query (int idx) {
    int res = 0;
    while (idx > 0) {
      res = (res + tree[idx]) % mod;
      idx -= (idx & -idx);
    }
    return res;
  }
};

vector<int> comp;

int find (int val) {
  return upper_bound(all(comp), val) - comp.begin();
}

void solve () {
  int n; cin >> n;
  vector<int> arr(n);
  comp.assign(n, 0);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    comp[i] = arr[i];
  }
  
  sort(all(comp));
  comp.erase(unique(all(comp)), comp.end());

  for (int& x : arr) x = find(x);

  FenwickTree BIT(n);
  int ans = 0;

  for (int x : arr) {
    int subsequence = 1 + BIT.query(x - 1);
    ans = (ans + subsequence) % mod;
    BIT.add(x, subsequence);
  }

  cout << ans << endl;
}

/*
-- Sample 1 --
Input:
3
2 1 3
Output:
5
*/

/*
g++ -std=c++17 -O2 -Wall -DLOCAL "C:\Users\LENOVO\Desktop\BARKIN\Genel\Programming\Competitive\Questions\CSES\Additional_Problems\1748_increasing_subsequence_II.cpp" -o _run
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