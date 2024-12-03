#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){
  int n; cin >> n;
  int curr_sum = 0, curr_min = 0, ans = INT_MIN;
  for (int i = 0; i < n; i++) {
    int x; cin >> x;
    curr_sum += x;
    ans = max(ans, curr_sum - curr_min);
    curr_min = min(curr_min, curr_sum);
  }

  cout << ans << endl;
  
  return 0;
}

/*
-- Sample 1 --
Input:
8
-1 3 -2 5 3 -5 2 2
Output:
9
*/