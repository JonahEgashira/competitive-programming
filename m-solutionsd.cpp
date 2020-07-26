#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
  int n;
  cin >> n;

  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  int answer = 1000;
  int stock = 0;

  for (int i = 1; i < n; i++) {
    if(a[i] > a[i - 1]) {
      stock = answer / a[i - 1];
      answer -= stock * a[i - 1];
    }
    answer += stock * a[i];
    stock = 0;
  }
  cout << answer << '\n';
  return 0;
}