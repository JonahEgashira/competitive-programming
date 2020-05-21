#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  string s;
  cin >> s;

  int n = (int)s.size();
  int a = 0, b = 0, c = 0, maxv = 0;
  for (int i = 0; i < n; i++) {
    if(s[i] == 'a') a++;
    if(s[i] == 'b') b++;
    if(s[i] == 'c') c++;
  }
  maxv = max({a,b,c});
  if(a == maxv) cout << 'a' << '\n';
  if(b == maxv) cout << 'b' << '\n';
  if(c == maxv) cout << 'c' << '\n';
}