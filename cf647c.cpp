#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define int long long

void solve(){
  int n;
  cin >> n;

  n++;
  int res = 0;
  for (int i = 0; i < 64; i++) {
    int d = (1LL << i);
    if(d > n) break;
    res += ((n + d - 1) / d) - 1;
  }
  cout << res << '\n';
}

signed main() {
  int tc;
  cin >> tc;

  while(tc--){
    solve();
  }
}
