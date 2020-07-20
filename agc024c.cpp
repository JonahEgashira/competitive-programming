#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<int> a(n);
  rep(i,n) cin >> a[i];

  bool flag = true;
  if(a[0] != 0) flag = false;

  long long answer = 0;
  for (int i = 1; i < n; i++) {
    if(a[i] > a[i - 1] + 1) {
      flag = false;
      break;
    }

    if(a[i] <= a[i - 1]) {
      if(a[i] == 0) continue;
      answer += (a[i] - 1);
    }
    answer++;
  }

  if(!flag) answer = -1;
  cout << answer << '\n';

  return 0;
}
