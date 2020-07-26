#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
  int n,k;
  cin >> n >> k;

  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  for (int i = k + 1; i <= n; i++) {
    if(a[i] > a[i - k]) {
      cout << "Yes" << '\n';
    } else {
      cout << "No" << '\n';
    }
  }

}