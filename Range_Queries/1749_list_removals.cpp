#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int x[N], tree[4 * N];
int n;

void build(int v, int tl, int tr){
  if (tl == tr) tree[v] = 1;
  else {
    int tm = (tl + tr) / 2;
    build(2 * v, tl, tm), build(2 * v + 1, tm + 1, tr);
    tree[v] = tree[2 * v] + tree[2 * v + 1];
  }
}

void update(int v, int tl, int tr, int pos, int val){
  if (tl == tr) tree[v] = val;
  else {
    int tm = (tl + tr) / 2;
    if (pos <= tm) update(2 * v, tl, tm, pos, val);
    else update(2 * v + 1, tm + 1, tr, pos, val);
    tree[v] = tree[2 * v] + tree[2 * v + 1];
  }
}

int query(int v, int tl, int tr, int val){
  if (tl == tr) {
    update(1, 1, n, tl, 0);
    return tl;
  } else {
    int tm = (tl + tr) / 2;
    if (tree[2 * v] >= val) return query(2 * v, tl, tm, val);
    else return query(2 * v + 1, tm + 1, tr, val - tree[2 * v]);
  }
}

int main(){
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> x[i];
  build(1, 1, n);

  for (int i = 1; i <= n; i++) {
    int p; cin >> p;
    cout << x[query(1, 1, n, p)] << " \n"[i == n];
  }
  
  return 0;
}

/*
-- Sample 1 --
Input:
5
2 6 1 4 2
3 1 3 1 1
Output:
1 2 2 6 4
*/