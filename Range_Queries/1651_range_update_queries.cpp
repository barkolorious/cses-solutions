#include <bits/stdc++.h>
#define llong long long
using namespace std;

const int N = 2e5 + 5;

llong tree[4 * N], lazy[4 * N];

void build(llong a[], int v, int tl, int tr){
  if(tl == tr) tree[v] = a[tl];
  else{
    int tm = (tl + tr) / 2;
    build(a, 2 * v, tl, tm);
    build(a, 2 * v + 1, tm + 1, tr);
    tree[v] = tree[2 * v] + tree[2 * v + 1];
  }
}

void push(int v){
  tree[2 * v] += lazy[v];
  tree[2 * v + 1] += lazy[v];
  lazy[2 * v] += lazy[v];
  lazy[2 * v + 1] += lazy[v];
  lazy[v] = 0;
}

void update(int v, int tl, int tr, int l, int r, llong val){
  if(l > r) return;
  if(l == tl && r == tr){
    tree[v] += val;
    lazy[v] += val;
  } else{
    push(v);
    int tm = (tl + tr) / 2;
    update(2 * v, tl, tm, l, min(r, tm), val);
    update(2 * v + 1, tm + 1, tr, max(l, tm + 1), r, val);
    tree[v] = tree[2 * v] + tree[2 * v + 1];
  }
}

llong query(int v, int tl, int tr, int pos){
  if(tl == tr) return tree[v];
  int tm = (tl + tr) / 2;
  push(v);
  if(pos <= tm) return query(2 * v, tl, tm, pos);
  else return query(2 * v + 1, tm + 1, tr, pos);
}

int main(){
  int n, q;
  cin >> n >> q;
  llong a[n + 1];
  for(int i = 1; i <= n; i++) cin >> a[i];

  build(a, 1, 1, n);
  for(int i = 0; i < q; i++){
    int type; cin >> type;
    if(type == 1){
      int l, r; llong u;
      cin >> l >> r >> u;
      update(1, 1, n, l, r, u);
    } else{
      int k; cin >> k;
      cerr << ':';
      cout << query(1, 1, n, k) << endl;
    }
  }

	return 0;
}

/*
-- Sample 1 --
Input:
8 3
3 2 4 5 1 1 5 3
2 4
1 2 5 1
2 4
Output:
5
6
*/