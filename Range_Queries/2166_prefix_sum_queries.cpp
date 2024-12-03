#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5 + 5;

struct Node {
  int max = 0, val = 0;
};

Node combine(Node l, Node r){
  Node temp;
  temp.val = l.val + r.val;
  temp.max = max({l.max, l.val + r.max, temp.val, 0LL});
  return temp;
}

Node tree[4 * N];
int x[N];

void build(int v, int tl, int tr){
  if (tl == tr) {
    Node temp; temp.val = x[tl];
    temp.max = max(0LL, x[tl]);
    tree[v] = temp;
  } else {
    int tm = (tl + tr) / 2;
    build(2 * v, tl, tm), build(2 * v + 1, tm + 1, tr);
    tree[v] = combine(tree[2 * v], tree[2 * v + 1]);
  }
}

void update(int v, int tl, int tr, int pos, int val){
  if (tl == tr) {
    Node temp; temp.val = val;
    temp.max = max(0LL, val);
    tree[v] = temp;
  } else {
    int tm = (tl + tr) / 2;
    if (pos <= tm) update(2 * v, tl, tm, pos, val);
    else update(2 * v + 1, tm + 1, tr, pos, val);
    tree[v] = combine(tree[2 * v], tree[2 * v + 1]);
  }
}

Node query(int v, int tl, int tr, int l, int r){
  if (r < tl || tr < l) { Node temp; return temp; }
  if (tl == l && tr == r) return tree[v];
  int tm = (tl + tr) / 2;
  return combine(query(2 * v, tl, tm, l, min(tm, r)),
                 query(2 * v + 1, tm + 1, tr, max(tm + 1, l), r));
}

int32_t main(){
  int n, q; cin >> n >> q;
  for (int i = 1; i <= n; i++) cin >> x[i];
  build(1, 1, n);

  for (int qi = 0; qi < q; qi++){
    char type; cin >> type;
    if (type == '1') {
      int k, u; cin >> k >> u;
      x[k] = u;
      update(1, 1, n, k, u);
    } else if (type == '2') {
      int a, b; cin >> a >> b;
      cerr << ':';
      cout << query(1, 1, n, a, b).max << endl;
    }
  }
  
  return 0;
}

/*
-- Sample 1 --
Input:
8 4
1 2 -1 3 1 -5 1 4
2 2 6
1 4 -2
2 2 6
2 3 4
Output:
5
2
0
*/