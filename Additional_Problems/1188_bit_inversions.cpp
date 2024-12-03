// barkolorious - 21 September 2024
#include <bits/stdc++.h>
using namespace std;

#define FIN(x) freopen(x ".in", "r", stdin)
#define FOUT(x) freopen(x ".out", "w", stdout)
#define int long long
#define pb  push_back
#define fr  first
#define sc  second

const int N = 2e5 + 5;

/*
g++ -std=c++17 -O2 -Wall -DLOCAL "C:\Users\LENOVO\Desktop\BARKIN\Genel\Programming\Competitive\Questions\CSES\Additional_Problems\1188_bit_inversions.cpp" -o _run
*/

void solve () {
  string bits; cin >> bits;
  int n = bits.size();

  set<int> invs;
  set<pair<int, pair<int, int>>> subs;

  invs.insert(0);

  char last = bits[0];
  for (int i = 1; i < n; i++) {
    if (bits[i] != last) {
      subs.insert({i - *invs.rbegin(), {*invs.rbegin(), i}});
      invs.insert(i);
      last = bits[i];
    }
  }
  subs.insert({n - *invs.rbegin(), {*invs.rbegin(), n}});
  invs.insert(n);

  int q; cin >> q;
  for (int qi = 1; qi <= q; qi++) {
    int x; cin >> x; x--;
    
    set<int>::iterator ITR = invs.lower_bound(x);
    bool flag1 = (*ITR == x), flag2 = (invs.count(x + 1) != 0);
    
    set<int>::iterator ITR_L, ITR_R, ITR_RR;

    if (ITR == invs.begin()) ITR_L =invs.begin();
    else { ITR_L = --ITR; ITR++; }

    ITR_R = ++ITR; ITR--;
    if (ITR_R == invs.end()) ITR_R--;

    ITR_RR = ++ITR_R; ITR_R--;
    if (ITR_RR == invs.end()) ITR_RR--;

    if (flag1 == 0 && flag2 == 0) {
      subs.erase({*ITR - *ITR_L, {*ITR_L, *ITR}});
      subs.insert({x - *ITR_L, {*ITR_L, x}});
      subs.insert({1, {x, x + 1}});
      subs.insert({*ITR - (x + 1), {x + 1, *ITR}});
      invs.insert(x); invs.insert(x + 1);
    } else if (flag1 == 1 && flag2 == 0) {
      subs.erase({*ITR_R - *ITR, {*ITR, *ITR_R}});
      subs.erase({*ITR - *ITR_L, {*ITR_L, *ITR}});
      subs.insert({(x + 1) - *ITR_L, {*ITR_L, x + 1}});
      subs.insert({*ITR_R - (x + 1), {x + 1, *ITR_R}});
      invs.erase(x); invs.insert(x + 1);
    } else if (flag1 == 0 && flag2 == 1) {
      subs.erase({*ITR_R - *ITR, {*ITR, *ITR_R}});
      subs.erase({*ITR - *ITR_L, {*ITR_L, *ITR}});
      subs.insert({x - *ITR_L, {*ITR_L, x}});
      subs.insert({*ITR_R - x, {x, *ITR_R}});
      invs.insert(x); invs.erase(x + 1);
    } else if (flag1 == 1 && flag2 == 1) {
      subs.erase({*ITR_R - *ITR, {*ITR, *ITR_R}});
      subs.erase({*ITR - *ITR_L, {*ITR_L, *ITR}});
      subs.erase({*ITR_RR - *ITR_R, {*ITR_R, *ITR_RR}});
      subs.insert({*ITR_RR - *ITR_L, {*ITR_L, *ITR_RR}});
      invs.erase(x); invs.erase(x + 1);
    }
    invs.insert(0);
    cout << subs.rbegin()->fr << " \n"[qi == q];
  }
}

/*
-- Sample 1 --
Input:
001011
3
3 2 5
Output:
4 2 3
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