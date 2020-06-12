#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

int main() {
  int n;
  cin >> n;

  vector<int> a(n);
  rep(i,n) {
    cin >> a[i];
    a[i]--;
  }

  vector<int> p(n);
  for (int i = 0; i < n; i++) {
    p[a[i]] = i;
  }
  int max_len = 0;
  int minv = -1;
  int tmp = 0;
  for (int i = 0; i < n; i++) {
    if(p[i] > minv){
      minv = p[i];
      tmp++;
      if(i == n - 1) max_len = max(max_len, tmp);
    } else {
      max_len = max(max_len, tmp);
      minv = p[i];
      tmp = 1;
    }
  }
  cout << n - max_len << '\n';
}