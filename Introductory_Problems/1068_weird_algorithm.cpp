#include <bits/stdc++.h>
using namespace std;

int main(){
  long long n; cin >> n;
  while(n != 1){
    cout << n << ' ';
    if(n % 2) n = 3 * n + 1;
    else n /= 2;
  }
  cout << 1 << endl;
  
  return 0;
}

/*
-- Sample 1 --
Input:
3
Output:
3 10 5 16 8 4 2 1
*/