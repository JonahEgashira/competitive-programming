#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

int main() {
  int n;
  cin >> n;

  vector<int> a(n), b(n);
  rep(i,n) cin >> a[i] >> b[i];

  sort(a.begin(),a.end());
  sort(b.begin(),b.end());

  if(n % 2 == 1) {
    int l = a[n/2], r = b[n/2];
    cout << r - l + 1 << '\n';
  } else {
    int l = a[n/2 - 1] + a[n/2];
    int r = b[n/2 - 1] + b[n/2];
    cout << r - l + 1 << '\n';
  }
  return 0;
}