#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  string s,t;
  cin >> s >> t;

  int a = 0, b = 0;
  if(s[0] == 'B') {
    a = - (s[1] - '0') + 1;
  } else {
    a = s[0] - '0';
  }
  if(t[0] == 'B') {
    b = - (t[1] - '0') + 1;
  } else {
    b = t[0] - '0';
  }
  cout << abs(a - b) << '\n';
}