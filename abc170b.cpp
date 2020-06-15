#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int x,y;
  cin >> x >> y;

  bool ok = false;
  for (int i = 0; i <= x; i++) {
    int tmp = i * 2 + (x - i) * 4;
    if(tmp == y) ok = true;
  }
  if(ok) cout << "Yes" << '\n';
  else cout << "No" << '\n';
}
