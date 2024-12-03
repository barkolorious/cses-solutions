#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){
  int t; cin >> t;
  while(t--){
    int x, y, ans = 0; //x column y row
    cin >> y >> x;
    if(x > y){
      if(x % 2) ans = x * x - y + 1;
      else ans = ((x - 1) * (x - 1)) + y;
    }else{
      if(y % 2) ans = ((y - 1) * (y - 1)) + x;
      else ans = y * y - x + 1;
    }
    cout << ans << endl;
  }
  
  return 0;
}

/*
-- Sample 1 --
Input:
3
2 3
1 1
4 2
Output:
8
1
15
*/
