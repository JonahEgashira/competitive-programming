#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

signed main() {
   int n;
   string s;
   cin >> n >> s;

   for (int i = 1; i < n - 1; i++) {
     if(s[i - 1] == 'j' && s[i] == 'o' && s[i + 1] == 'i') {
       s[i - 1] = 'J';
       s[i] = 'O';
       s[i + 1] = 'I';
     }
   }

   cout << s << '\n';
}

