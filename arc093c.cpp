#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  int n;
  cin >> n;

  vector<int> a(n + 2);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }

  int sum = 0;
  for (int i = 1; i < n + 2; i++) {
    sum += abs(a[i] - a[i - 1]);
  }

  for (int i = 1; i <= n; i++) {
    int cur = a[i];
    int from = a[i - 1];
    int nxt = a[i + 1];

    int tmp = -abs(cur - from) - abs(cur - nxt) + abs(nxt - from);
    cout << sum + tmp << '\n';
  }

  return 0;
}
