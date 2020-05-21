#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

int main() {
  string s;
  cin >> s;

  while(true) {
    bool brace = false;
    string a = "";
    int lst = 0;
    for (int i = 0; i < (int)s.size(); i++) {
      if(s[i] == '(') {
        brace = true;
        a = "";
        lst = i;
      } else if(s[i] == ')') {
        string l = s.substr(0, lst);
        string mid = a;
        reverse(a.begin(),a.end());
        mid += a;
        string r = s.substr(i + 1, (int)s.size() - i);
        s = l + mid + r;
        break;
      } else {
        a += s[i];
      }
    }
    if(!brace) break;
  }

  cout << s << '\n';
  return 0;
}