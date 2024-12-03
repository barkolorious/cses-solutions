#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){
  int n; cin >> n;
  int x[n];
  for(int i = 0; i < n; i++) cin >> x[i];
  
  int ans = 0;
  for(int i = 0; i < n - 1; i++){
    if(x[i] > x[i + 1]){
      ans += x[i] - x[i + 1];
      x[i + 1] = x[i];
    }
  }

  cout << ans << endl;
  return 0;
}
/*
-- Sample 1 --
Input:
5
3 2 5 1 7
Output:
5
*/