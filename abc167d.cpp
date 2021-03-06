#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n, k;
  cin >> n >> k;

  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    a[i]--;
  }

  vector<int> last(n,-1);
  vector<int> root;
  int gap = 0;
  root.push_back(0);
  last[0] = 0;
  int i = 0;
  int from = 0;
  int cnt = 1;
  while(true) {
    if(last[a[i]] != -1) {
      gap = cnt - last[a[i]];
      from = last[a[i]];
      break;
    }
    last[a[i]] = cnt;
    root.push_back(a[i]);
    i = a[i];
    cnt++;
  }


  vector<int> f;
  if(k < cnt) {
    cout << root[k] + 1 << '\n';
  } else {
    k -= (cnt - gap);
    for (int j = from; j < cnt; j++) {
      f.push_back(root[j]);
    }
    k %= gap;
    cout << f[k] + 1 << endl;
  }
  return 0;
}
