#include <bits/stdc++.h>
using namespace std;

int main(){
  int n; cin >> n;
  int ans = 0;
  while (n) ans += n /= 5;
  cout << ans << endl;
  return 0;
}

/*
-- Sample 1 --
Input:
20
Output:
4
*/