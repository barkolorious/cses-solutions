#include <bits/stdc++.h>
using namespace std;

/* Solution A */
int main(){
  int n; cin >> n;

  if((n * (n + 1) / 2) % 2) {
    cout << "NO" << endl;
  } else {
    cout << "YES" << endl;
    cout << (n + 1) / 2 << endl;

    for(int i = 1; i <= (n + 1) / 2; i++)
      cout << (n / 4) + i << " \n"[i == (n + 1) / 2];
    
    cout << n - (n + 1) / 2 << endl;

    for(int i = 1; i <= n / 4; i++)
      cout << i << ' ';
    
    for(int i = (n / 4) + (n + 1) / 2 + 1; i <= n; i++)
      cout << i << " \n"[i == n];
  }
  return 0;
}

/* Solution B */
// int main(){
//   int n; cin >> n;
//   if(((n * (n + 1)) / 2) % 2) {cout << "NO" << endl; return 0;}

//   cout << "YES" << endl;
//   int chalf = ceil((float) n / 2);
//   int fquar = n / 4;
//   cout << chalf << endl;
//   for(int x = fquar + 1; x <= fquar + chalf; x++) cout << x << sp;
//   cout << endl;
//   cout << n - chalf << endl;
//   for(int x = 1; x <= n; x++) if((x < fquar + 1) || (fquar + chalf < x)) cout << x << sp;
//   cout << endl;
// }

/*
-- Sample 1 --
Input:
7
Output:
YES
4
1 2 4 7
3
3 5 6

-- Sample 2 --
Input:
6
Output:
NO
*/