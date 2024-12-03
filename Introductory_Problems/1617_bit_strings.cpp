#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mod = 1e9 + 7;

int pwr(int a, int b){
  int ans = 1;
  while(b){
    if(b & 1) ans = (ans % mod) * (a % mod) % mod;
    a = (a % mod) * (a % mod) % mod;
    b >>= 1;
  }
  return ans;
}

int32_t main(){
  int n; cin >> n;
  
  cout << pwr(2, n) << endl;

  return 0;
}

/*
-- Sample 1 --
Input: 
3
Output:
8
*/