#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define int long long

signed main() {
  int n,a,b;
  cin >> n >> a >> b;

  int c = a - b;
  vector<int> h(n);
  rep(i,n) cin >> h[i];

  int ng = 0, ok = 1e9;
  while(ok - ng > 1) {
    int mid = (ok + ng) / 2;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      int val = h[i] - b*mid;
      if(val > 0) {
        cnt += (val + c - 1) / c;
      }
    }
    if(cnt <= mid) ok = mid;
    else ng = mid;
  }
  cout << ok << '\n';
  return 0;
}