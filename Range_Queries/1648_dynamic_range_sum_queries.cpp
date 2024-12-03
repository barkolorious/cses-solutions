#include <bits/stdc++.h>
#define llong long long
using namespace std;

const int N = 2e5 + 5;

llong tree[4 * N];

void build(llong a[], int v, int tl, int tr){
  if(tl == tr) tree[v] = a[tl];
  else{
    int tm = (tl + tr) / 2;
    build(a, 2 * v, tl, tm);
    build(a, 2 * v + 1, tm + 1, tr);
    tree[v] = tree[2 * v] + tree[2 * v + 1];
  }
}

void update(int v, int tl, int tr, int pos, llong val){
  if(tl == tr) tree[v] = val;
  else{
    int tm = (tl + tr) / 2;
    if(pos <= tm) update(2 * v, tl, tm, pos, val);
    else update(2 * v + 1, tm + 1, tr, pos, val);
    tree[v] = tree[2 * v] + tree[2 * v + 1];
  }
}

llong query(int v, int tl, int tr, int l, int r){
  if(r < tl || l > tr) return 0;
  if(tl == l && tr == r) return tree[v];
  int tm = (tl + tr) / 2;
  return query(2 * v, tl, tm, l, min(tm, r)) +
         query(2 * v + 1, tm + 1, tr, max(tm + 1, l), r);
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
      int k, u; cin >> k >> u;
      update(1, 1, n, k, u);
    } else{
      int a, b; cin >> a >> b;
      cerr << ':';
      cout << query(1, 1, n, a, b) << endl;
    }
  }

	return 0;
}

/*
-- Sample 1 --
Input:
8 4
3 2 4 5 1 1 5 3
2 1 4
2 5 6
1 3 1
2 1 4
Output:
14
2
11
*/