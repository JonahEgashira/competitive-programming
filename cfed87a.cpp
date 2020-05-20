#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  ll a,b,c,d;
  cin >> a >> b >> c >> d;

  ll res = b;
  ll need = a - b;
  ll cycle = c - d;

  if(need <= 0) {
    cout << res << '\n';
    return;
  }

  if(cycle <= 0) {
    if(need > 0) {
      cout << -1 << '\n';
    } else {
      cout << res << '\n';
    }
    return;
  }

  ll cnt = (need + cycle - 1) / cycle;
  res += cnt * c;

  cout << res << '\n';
}

int main(){
  int tc;
  cin >> tc;

  while(tc--) {
    solve();
  }

  return 0;
}