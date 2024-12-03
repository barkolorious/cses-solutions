#include <bits/stdc++.h>
using namespace std;

/* Solution A */
int main(){
  int n; cin >> n;
  if (n == 1) cout << 1 << endl;
  else if (n == 2 || n == 3)
    cout << "NO SOLUTION" << endl;
  else if (n == 4)
    cout << "3 1 4 2" << endl;
  else {
    int mid = (n + 1) / 2;
    for(int i = 1; i <= mid; i++){
      cout << i << ' ';
      if(mid + i <= n) cout << mid + i << ' ';
      else break;
    }
    cout << endl;
  }

  return 0;
}

/* Solution B */
// int main(){
//   int n; cin >> n;
//   if(n == 1) cout << 1 << endl;
//   else if(n == 2 || n == 3) cout << ns << endl;
//   else{
//     vector<int> ans;
//     for(int i = 2; i <= n; i+=2) ans.push_back(i);
//     for(int i = 1; i <= n; i+=2) ans.push_back(i);
//     for(int x : ans) cout << x << " ";
//     cout << endl;
//   }
// }

/*
-- Sample 1 --
Input:
5
Output:
4 2 5 3 1
-- Sample 2 --
Input:
3
Output:
NO SOLUTION
*/