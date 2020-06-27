#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

int main() {
  int n,m;
  cin >> n >> m;

  if (n % 2 == 1) {
    for (int l = 2, r = n; l <= m + 1; l++, r--) {
      cout << l << " " << r << '\n';
    }
  } else {
    bool flag = true;
    for (int l = 2, r = n; l <= m + 1; l++, r--) {
      if(flag && (r - l) <= n / 2) --r, flag = false;
      cout << l << " " << r << '\n';
    }
  }

  return 0;
}
