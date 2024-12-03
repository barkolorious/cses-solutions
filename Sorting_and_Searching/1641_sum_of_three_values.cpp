// barkolorious - 03 September 2024
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
g++ -std=c++17 -O2 -Wall -DLOCAL "C:\Users\LENOVO\Desktop\BARKIN\Genel\Programming\Competitive\Questions\CSES\Sorting_and_Searching\1641_sum_of_three_values.cpp" -o _run
*/

pair<int, int>* binarySearch (pair<int, int>* l, pair<int, int>* r, int x) {
  while (l < r) {
    pair<int, int>* m = l + (r - l) / 2;
    if (m->fr < x) l = m + 1;
    else if (m->fr > x) r = m;
    else return l;
  }
  return NULL;
}

void solve () {
  int n, x; cin >> n >> x;
  pair<int, int> a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i].fr;
    a[i].sc = i + 1;
  }

  sort(a, a + n);

  for (int l = 0; l < n; l++) {
    for (int r = l + 1; r < n; r++) {
      int sum = a[l].fr + a[r].fr;

      if (sum >= x) break;

      pair<int, int>* i = binarySearch(a, a + n, x - sum);
      
      if (i && *i != a[l] && *i != a[r] && sum + i->fr == x) {
        cout << a[l].sc << " " << i->sc << " " << a[r].sc << endl;
        return;
      }
    }
  }

  cout << "IMPOSSIBLE" << endl;
}

/*
-- Sample 1 --
Input:
4 8
2 7 5 1
Output:
1 3 4
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
      FILE* __FILE_IN__ = FIN("C:/Users/LENOVO/Desktop/BARKIN/Genel/Programming/Competitive/_run");
      FILE* __FILE_OUT__ = FOUT("C:/Users/LENOVO/Desktop/BARKIN/Genel/Programming/Competitive/_run");
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