#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

void solve(){
  int n,x;
  cin >> n >> x;

  int even = 0, odd = 0;
  rep(i,n) {
    int a; cin >> a;
    if(a % 2 == 0) even++;
    else odd++;
  }

  bool ok = false;
  if(x % 2 == 1 && odd >= x) ok = true;
  while(even > 0) {
    x--;
    even--;
    if(odd >= x && x % 2 == 1) {
      ok = true;
      break;
    }
  }
  if(ok) cout << "Yes" << '\n';
  else cout << "No" << '\n';
}

signed main() {
  int tc;
  cin >> tc;

  while(tc--){
    solve();
  }
}
