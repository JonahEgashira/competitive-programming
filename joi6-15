#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
#define int long long

signed main() {
  int k,n,m;
  cin >> k >> n >> m;

  vector<int> a(k), b(k), c(k);
  rep(i,k) {
    cin >> a[i];
    b[i] = c[i] = a[i];
  }

  if(k == 1) {
    cout << 1 << '\n';
    cout << "--------" << '\n';
    cout << 1 << '\n';
    return 0;
  }

  rep(i,k) {
    c[i] += (n - m)*100LL;
  }

  sort(b.begin(),b.end());
  sort(c.begin(),c.end());

  int gold_n = (k + 12 - 1)/12;
  for (int i = 0; i < k; i++) {
    int min_score = c[k - gold_n];
    int score = a[i];
    if(score + (n - m)*100LL >= min_score) min_score = c[k - gold_n - 1];
    if(score >= min_score) {
      cout << i + 1 << '\n';
    }
  }

  cout << "--------" << '\n';
  for (int i = 0; i < k; i++) {
    int min_score = b[k - gold_n];
    int score = a[i];
    if(score + (n - m)*100LL >= min_score) {
      cout << i + 1 << '\n';
    }
  }
}
