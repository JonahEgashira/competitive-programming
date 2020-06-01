#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define int long long

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  int N = n;
  int ans = 0;
  for (int i = 2; i * i <= N; i++) {
    int cnt = 0;
    while(n % i == 0) {
      n /= i;
      cnt++;
    }
    for (int j = 1; j <= 50; j++) {
      if(cnt < j) break;
      ans++;
      cnt -= j;
    }
  }
  if(n > 1) ans++;
  cout << ans << '\n';
}