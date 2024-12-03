#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int n, m; 
int hotel[N], tree[4 * N];

void build(int v, int tl, int tr){
  if (tl == tr) tree[v] = hotel[tl];
  else {
    int tm = (tl + tr) / 2;
    build(2 * v, tl, tm), build(2 * v + 1, tm + 1, tr);
    tree[v] = max(tree[2 * v], tree[2 * v + 1]);
  }
}

void update(int v, int tl, int tr, int pos, int val){
  if (tl == tr) tree[v] = val;
  else {
    int tm = (tl + tr) / 2;
    if (pos <= tm) update(2 * v, tl, tm, pos, val);
    else update(2 * v + 1, tm + 1, tr, pos, val);
    tree[v] = max(tree[2 * v], tree[2 * v + 1]);
  }
}

int query(int v, int tl, int tr, int x){
  if (tl == tr) {
    if (tree[v] >= x) {
      hotel[tl] = tree[v] - x;
      update(1, 1, n, tl, hotel[tl]);
      return tl;
    } else return 0;
  } else {
    if (tree[v] < x) return 0;
    int tm = (tl + tr) / 2;
    if (tree[2 * v] >= x) return query(2 * v, tl, tm, x);
    else return query(2 * v + 1, tm + 1, tr, x);
  }
}

int main(){
  cin >> n >> m;
  for (int i = 1; i <= n; i++) cin >> hotel[i];

  build(1, 1, n);

  for(int mi = 1; mi <= m; mi++){
    int r; cin >> r;
    cout << query(1, 1, n, r) << " \n"[mi == m];
  }
  
  return 0;
}

/*
-- Sample 1 --
Input:
8 5
3 2 4 1 5 5 2 6
4 4 7 1 1
Output:
3 5 0 1 1
*/