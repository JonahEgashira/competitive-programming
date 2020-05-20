#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  int n;
  cin >> n;

  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  map<int,int> dp;
  int ans = 0;
  int lst = 0;
  for (int i = 0; i < n; i++) {
    int x = a[i];
    dp[x] = dp[x - 1] + 1;
    if (ans < dp[x]) {
      ans = dp[x];
      lst = x;
    }
  }

  vector<int> res;
  for (int i = n - 1; i >= 0; --i) {
    if(a[i] == lst) {
      res.push_back(i);
      --lst;
    }
  }
  reverse(res.begin(), res.end());
  cout << (int)res.size() << '\n';
  for (auto it : res) cout << it + 1 << " ";
  cout << '\n';


}