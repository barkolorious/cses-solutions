#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

int tree[4 * N];

void build(int a[], int v, int tl, int tr){
  if(tl == tr) tree[v] = a[tl];
  else{
    int tm = (tl + tr) / 2;
    build(a, 2 * v, tl, tm);
    build(a, 2 * v + 1, tm + 1, tr);
    tree[v] = tree[2 * v] ^ tree[2 * v + 1];
  }
}

void update(int v, int tl, int tr, int pos, int val){
  if(tl == tr) tree[v] = val;
  else{
    int tm = (tl + tr) / 2;
    if(pos <= tm) update(2 * v, tl, tm, pos, val);
    else update(2 * v + 1, tm + 1, tr, pos, val);
    tree[v] = tree[2 * v] ^ tree[2 * v + 1];
  }
}

int query(int v, int tl, int tr, int l, int r){
  if(r < tl || l > tr) return 0;
  if(tl == l && tr == r) return tree[v];
  int tm = (tl + tr) / 2;
  return query(2 * v, tl, tm, l, min(tm, r)) ^
         query(2 * v + 1, tm + 1, tr, max(tm + 1, l), r);
}

int main(){
  int n, q;
  cin >> n >> q;
  int a[n + 1];
  for(int i = 1; i <= n; i++) cin >> a[i];

  build(a, 1, 1, n);
  for(int i = 0; i < q; i++){
    int l, r; cin >> l >> r;
    cerr << ':';
    cout << query(1, 1, n, l, r) << endl;
  }

	return 0;
}

/*
-- Sample 1 --
Input:
8 4
3 2 4 5 1 1 5 3
2 4
5 6
1 8
3 3
Output:
3
0
6
4
*/