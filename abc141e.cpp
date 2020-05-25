#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

int main() {
  int n;
  string s;
  cin >> n >> s;

  int ans = 0;
  for (int j = 1; j < n - 1; j++) {
    int tmp = 0;
    for (int i = 0; i + j < n; i++) {
      if(s[i] == s[i + j]) {
        tmp++;
        tmp = min(tmp, j);
        ans = max(ans, tmp);
      }
      else tmp = 0;
    }
  }
  cout << ans << '\n';
}