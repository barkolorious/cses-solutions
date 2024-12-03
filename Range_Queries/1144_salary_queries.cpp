#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 4e6 + 5;
int tree[N];
int n, q; 
vector<int> salaries;

int Find(int x){
  return upper_bound(salaries.begin(), salaries.end(), x) - salaries.begin();
}

void Update(int p, int v){
  while (p <= N) {
    tree[p] += v;
    p += p & -p;
  }
}

int Query(int p){
  int res = 0;
  while (p) {
    res += tree[p];
    p -= p & -p;
  }
  return res;
}

int32_t main(){
  cin >> n >> q;

  vector<tuple<char, int, int>> queries;
  int p[n];

  for (int i = 0; i < n; i++) {
    cin >> p[i]; salaries.push_back(p[i]);
  }

  for (int qi = 0; qi < q; qi++) {
    char type; int a, b;
    cin >> type >> a >> b;
    queries.push_back({type, --a, b});
    if(type == '!') salaries.push_back(b);
  }

  sort(salaries.begin(), salaries.end());
  salaries.erase(unique(salaries.begin(), salaries.end()), salaries.end());

  for (int i = 0; i < n; i++) Update(Find(p[i]), 1);

  for (auto query : queries) {
    char type; int a, b; 
    type = get<0>(query);
    a = get<1>(query);
    b = get<2>(query);
    if (type == '!') {
      Update(Find(p[a]), -1);
      p[a] = b;
      Update(Find(p[a]), 1);
    } else if (type == '?') {
      cout << Query(Find(b)) - Query(Find(a)) << endl;
    }
  }
  
  return 0;
}

/*
-- Sample 1 --
Input:
5 3
3 7 2 2 5
? 2 3
! 3 6
? 2 3
Output:
3
2
*/