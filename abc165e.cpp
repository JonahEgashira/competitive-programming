#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define int long long

signed main() {
  int n,m;
  cin >> n >> m;

  if(n % 2 == 1) {
    for (int i = 1; i <= m; i++) {
      cout << i << " " << n - i + 1 << '\n';
    }
  } else {
    int add = 0;
    for (int i = 1; i <= m; i++) {
      if((n - i + 1) - i <= n/2) add = -1;
      cout << i << " " << n - i + 1 + add << '\n';
    }
  }
}
