#include <bits/stdc++.h>
#define llong long long
using namespace std;

int main(){
  int n, q;
  cin >> n >> q;
  llong a[n], prefix[n + 1];
  prefix[0] = 0;
  for(int i = 0; i < n; i++){
    cin >> a[i];
    prefix[i + 1] = prefix[i] + a[i];
  }

  for(int i = 0; i < q; i++){
    int l, r; cin >> l >> r;
    cerr << ':';
    cout << prefix[r] - prefix[l - 1] << endl;
  }

	return 0;
}

/*
-- Sample 1 --
Input:
8 4
3 2 4 5 1 1 5 3
2 4
5 6
1 8
3 3
Output:
11
2
24
4
*/