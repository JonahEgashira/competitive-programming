#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  string s;
  cin >> s;

  int n = (int)s.size();
  int ans = 0;
  // k = 1
  for (int i = 0; i < 27; i++) {
    vector<char> t(1);
    if(i == 26) t[0] = '.';
    else t[0] = (i + 'a');

    bool ok = false;
    for (int j = 0; j < n; j++) {
      if(t[0] == '.' || t[0] == s[j]) ok = true;
    }
    if(ok) ans++;
  }

  if(n >= 2) {
    for (int i = 0; i < 27; i++) {
      for (int j = 0; j < 27; j++) {
        vector<char> t(2);
        if (i == 26) t[0] = '.';
        else t[0] = (i + 'a');
        if (j == 26) t[1] = '.';
        else t[1] = (j + 'a');

        bool ok = false;
        for (int k = 0; k < n - 1; k++) {
          if ((t[0] == '.' || t[0] == s[k]) && (t[1] == '.' || t[1] == s[k + 1])) ok = true;
        }
        if (ok) ans++;
      }
    }
  }

  if(n >= 3) {
    for (int i = 0; i < 27; i++) {
      for (int j = 0; j < 27; j++) {
        for (int k = 0; k < 27; k++) {
          vector<char> t(3);
          if (i == 26) t[0] = '.';
          else t[0] = (i + 'a');
          if (j == 26) t[1] = '.';
          else t[1] = (j + 'a');
          if (k == 26) t[2] = '.';
          else t[2] = (k + 'a');

          bool ok = false;
          for (int l = 0; l < n - 2; l++) {
            if ((t[0] == '.' || t[0] == s[l]) && (t[1] == '.' || t[1] == s[l + 1]) &&
                (t[2] == '.' || t[2] == s[l + 2]))
              ok = true;
          }
          if (ok) ans++;
        }
      }
    }
  }


  cout << ans << '\n';
}