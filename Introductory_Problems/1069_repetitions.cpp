#include <bits/stdc++.h>
using namespace std;

/* Solution A */
int main(){
  string s; cin >> s;
  int n = s.length();
  int mx = 1, curr = 1;
  char last = s[0];
  for(int i = 1; i < n; i++){
    if(s[i] == last) curr++;
    else{
      mx = max(mx, curr);
      curr = 1;
      last = s[i];
    }
  }
  mx = max(mx, curr);

  cout << mx << endl;
  
  return 0;
}

/* Solution B */
// int main(){
// 	string s;
// 	cin >> s;
// 	int n = s.length();
// 	int start = 0;
// 	int mx = -1;
// 	char last = s[0];
// 	for(int i = 1; i < n; i++){
// 		if(s[i] != last){
// 			mx = max(mx, i - start);
// 			start = i;
// 			last = s[i];
// 		}
// 	}
// 	mx = max(mx, n - start);

// 	cout << mx;
// }

/*
-- Sample 1 --
Input:
ATTCGGGA
Output:
3
*/