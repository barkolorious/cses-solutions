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

struct FenwickTree {
  int n;
  vector<int> tree;

  FenwickTree (int __n) {
    n = __n; tree.assign(n + 1, 0);
  }

  FenwickTree (FenwickTree& __tree) {
    n = __tree.n;
    tree = __tree.tree;
  }

  void add (int idx, int val) {
    while (idx <= n) {
      tree[idx] += val;
      idx += idx & -idx;
    }
  }

  int prefix_sum (int idx) {
    int res = 0;
    while (idx) {
      res += tree[idx];
      idx -= idx & -idx;
    }
    return res;
  }
};

void solve () {
  int n, q; cin >> n >> q;
  vector<int> arr(n);
  // one indexed l, r zero indexed idx
  vector<pair<int, int>> queries[n + 1]; // l -> {r, idx}

  for (int i = 0; i < n; i++) cin >> arr[i];
  for (int i = 0; i < q; i++) {
    int l, r; cin >> l >> r;
    queries[l].pb({r, i});
  }

  FenwickTree BIT(n);
  map<int, int> last_idx;
  int ans[q];

  for (int l = n ; l > 0; l--) {
    int val = arr[l - 1];

    if (last_idx[val] > 0) BIT.add(last_idx[val], -1);
    last_idx[val] = l;
    BIT.add(l, 1);

    for (auto query : queries[l]) {
      ans[query.sc] = BIT.prefix_sum(query.fr);
    }
  }
  
  for (int i = 0; i < q; i++) cout << ans[i] << endl;
}

/*
-- Sample 1 --
Input:
5 3
3 2 3 1 2
1 3
2 4
1 5
Output:
2
3
3
*/

/*
g++ -std=c++17 -O2 -Wall -DLOCAL "C:\Users\LENOVO\Desktop\BARKIN\Genel\Programming\Competitive\Questions\CSES\Range_Queries\1734_distinct_values_queries.cpp" -o _run
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