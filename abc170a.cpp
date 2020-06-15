#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int x[5];
  int ans = 0;
  rep(i,5) {
    cin >> x[i];
    if(x[i] == 0) ans = i + 1;
  }
  cout << ans << '\n';
}
