#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

int main() {
  int n;
  cin >> n;

  vector<vector<pair<int,int>>> a(n);
  int two = 2;
  for (int i = n - 1; i >= 0; i--) {
    a[i].resize(two);
    two *= 2;
  }

  for (int i = 0; i < pow(2, n); i++) {
    cin >> a[0][i].first;
    a[0][i].second = i;
  }

  vector<int> ans(pow(2, n));

  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < (int)a[i].size(); j += 2) {
      int nj = j / 2;
      if(a[i][j].first > a[i][j + 1].first) {
        ans[a[i][j + 1].second] = i + 1;
        a[i + 1][nj].first = a[i][j].first;
        a[i + 1][nj].second = a[i][j].second;
      } else {
        ans[a[i][j].second] = i + 1;
        a[i + 1][nj].first = a[i][j + 1].first;
        a[i + 1][nj].second = a[i][j + 1].second;
      }
    }
  }

  ans[a[n - 1][0].second] = n;
  ans[a[n - 1][1].second] = n;

  for (auto it : ans) {
    cout << it << '\n';
  }

  return 0;
}