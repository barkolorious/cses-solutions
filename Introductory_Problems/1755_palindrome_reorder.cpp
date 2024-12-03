// barkolorious - 21 September 2024
#include <bits/stdc++.h>
using namespace std;

#define FIN(x) freopen(x ".in", "r", stdin)
#define FOUT(x) freopen(x ".out", "w", stdout)
#define int long long
#define pb  push_back
#define fr  first
#define sc  second

const int N = 2e5 + 5;

/*
g++ -std=c++17 -O2 -Wall -DLOCAL "C:\Users\LENOVO\Desktop\BARKIN\Genel\Programming\Competitive\Questions\CSES\Introductory_Problems\1755_palindrome_reorder.cpp" -o _run
*/

/* Solution A */
void solve () {
  string s; cin >> s;
  int odd_letter = -1;

  int freq[26]{};
  for (char c : s) freq[c - 'A']++;

  for (int i = 0; i < 26; i++) {
    if (freq[i] % 2) {
      if (odd_letter != -1) {
        cout << "NO SOLUTION" << endl;
        return;
      }
      odd_letter = i;  
    }
  }

  string ans;
  if (odd_letter != -1) ans = string(freq[odd_letter], odd_letter + 'A');
  else ans = "";
  
  for (int i = 0; i < 26; i++) {
    if (i == odd_letter) continue;
    if (!freq[i]) continue;
    string temp((freq[i] / 2), (i + 'A'));
    ans = temp + ans + temp;
  }
  
  cout << ans << endl;
}

/*
-- Sample 1 --
Input:
AAAACACBA
Output:
AACABACAA
*/

/* Solution B */
// void solve () {
//   string s; cin >> s;
// 
//   map<char, ll> mp;
//   for(char c : s) mp[c]++;
// 
//   char c = '\0'; s = "";
// 
//   int odd = 0;
//   for(auto x : mp) if(x.second & 1) {odd++; c = x.first;}
//   if(odd > 1) {cout << "NO SOLUTION" << endl; return 0;}
// 
//   if(c) {s += c; mp[c]--;}
//   mp.erase(c);
// 
//   for(auto x : mp){
//     for(int i = 0; i < x.second / 2; i++) s = x.first + s + x.first;
//   }
//   cout << s << endl;
// }

int32_t main () {
  #ifndef LOCAL
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
  #endif

  #ifdef LOCAL
    clock_t __START__ = clock();
    FILE* __FILE_IN__ = FIN("C:/Users/LENOVO/Desktop/BARKIN/Genel/Programming/Competitive/_run");
    FILE* __FILE_OUT__ = FOUT("C:/Users/LENOVO/Desktop/BARKIN/Genel/Programming/Competitive/_run");
  #else
    #ifndef ONLINE_JUDGE
      FILE* __FILE_IN__ = FIN("usaco");
      FILE* __FILE_OUT__ = FOUT("usaco");
    #endif
  #endif

  solve();

  #ifdef LOCAL
    fclose(__FILE_IN__);
    fclose(__FILE_OUT__);
    cerr << "Executed in: " << fixed << setprecision(3) << (double) (clock() - __START__) / CLOCKS_PER_SEC << "seconds" << endl;
  #else
    #ifndef ONLINE_JUDGE
      fclose(__FILE_IN__);
      fclose(__FILE_OUT__);
    #endif
  #endif

  return 0;
}