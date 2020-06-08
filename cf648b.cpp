#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

void solve(){
  int n;
  cin >> n;

  vector<int> a(n), b(n);
  int zero = 0, one = 0;
  rep(i,n) cin >> a[i];
  rep(i,n) {
    cin >> b[i];
    if(b[i] == 0) zero = 1;
    else one = 1;
  }

  if(zero && one) {
    cout << "Yes" << '\n';
    return;
  }

  bool ok = true;
  for (int i = 1; i < n; i++) {
    if(a[i - 1] > a[i]) ok = false;
  }
  if(ok) cout << "Yes" << '\n';
  else cout << "No" << '\n';

}

int main() {
  int tc;
  cin >> tc;

  while(tc--){
    solve();
  }
  return 0;
}