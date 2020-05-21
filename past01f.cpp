#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;

  vector<pair<int,int>> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i].first >> a[i].second;
    a[i].second = -a[i].second;
  }

  sort(a.begin(),a.end());
  priority_queue<int> que;
  int sum = 0;
  int day = 1;
  int i = 0;
  int j = 0;
  while(j < n) {
    while(i < n && a[i].first <= day) {
      que.push(-a[i].second);
      i++;
      if(i == n) break;
    }
    sum += que.top();
    que.pop();
    cout << sum << '\n';
    day++;
    j++;
  }
}