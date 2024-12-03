#include <bits/stdc++.h>
using namespace std;

/* Solution A */
int main(){
  int n; cin >> n;
  set<int> s;
  for(int i = 1; i <= n; i++) s.insert(i);
  for(int i = 1; i < n; i++){
    int x; cin >> x; s.erase(x);
  }
  cout << *s.begin() << endl;
  
  return 0;
}

/* Solution B */
// int main(){
// 	int n;
// 	cin >> n;
// 	int arr[n];
// 	for(int i = 1; i < n; i++){
// 		cin >> arr[i];
// 	}
// 	sort(arr + 1, arr + n);
	
// 	for(int i = 1; i <= n; i++){
// 		if(arr[i] != i) {cout << i << endl; return 0;}
// 	}
// }

/*
-- Sample 1 --
Input:
5
2 3 1 5
Output:
4
*/