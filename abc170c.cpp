#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int x,n;
  cin >> x >> n;

  set<int> st;
  rep(i,n) {
    int p;
    cin >> p;
    st.insert(p);
  }

  int ans = 1e9;
  int min_diff = 1e9;
  for (int i = -1000; i <= 1000; i++) {
    if(st.count(i)) continue;

    if(abs(i - x) < min_diff) {
      ans = i;
      min_diff = abs(i - x);
    }
  }
  cout << ans << '\n';
}
