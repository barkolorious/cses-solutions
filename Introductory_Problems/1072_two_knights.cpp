#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){
  int n; cin >> n;
  
  for(int i = 1; i <= n; i++){
    int ans = (i * i) * (i * i - 1) / 2;
    ans -= 2 * (2 * (i - 2 + 1) * (i - 3 + 1));
    cout << ans << endl;
  }
  
  return 0;
}
/*
-- Sample 1 --
Input:
8
Output:
0
6
28
96
252
550
1056
1848
*/