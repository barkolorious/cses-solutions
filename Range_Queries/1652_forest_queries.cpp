#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;

char forest[N][N];
int prefix[N][N];

int main(){
  int n, q; cin >> n >> q;
  for(int i = 0; i <= n; i++) prefix[i][0] = prefix[0][i] = 0;

  for(int y = 1; y <= n; y++){
    for(int x = 1; x <= n; x++){
      cin >> forest[y][x];
      prefix[y][x] = (forest[y][x] == '*') + prefix[y-1][x] + prefix[y][x-1] - prefix[y-1][x-1];
    }
  }

  for(int qi = 0; qi < q; qi++){
    int y1, x1, y2, x2;
    cin >> y1 >> x1 >> y2 >> x2;
    cerr << ':';
    cout << prefix[y2][x2] - prefix[y1-1][x2] - prefix[y2][x1-1] + prefix[y1-1][x1-1] << endl;
  }
  
  
  return 0;
}

/*
-- Sample 1 --
Input:
4 3
.*..
*.**
**..
****
2 2 3 4
3 1 3 1
1 1 2 2
Output:
3
1
2
*/