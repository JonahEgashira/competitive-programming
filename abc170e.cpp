#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n,q;
  cin >> n >> q;

  vector<int> baby_rate(n + 1);
  vector<int> baby_from(n + 1);

  vector<multiset<int>> st(200020);
  multiset<int> max_rate;

  for (int i = 0; i < 200020; i++) {
    st[i].insert(-1);
  }

  for (int i = 1; i <= n; i++) {
    int a,b;
    cin >> a >> b;

    st[b].insert(a);
    baby_rate[i] = a;
    baby_from[i] = b;
  }

  for (int i = 0; i < 200020; i++) {
    if(*st[i].rbegin() != -1) {
      max_rate.insert(*st[i].rbegin());
    }
  }

  while(q--) {
    int c,to;
    cin >> c >> to;

    int from = baby_from[c];
    int rate = baby_rate[c];
    baby_from[c] = to;

    bool changed = false;
    if(rate == *st[from].rbegin()) {
      max_rate.erase(max_rate.find(rate));
      changed = true;
    }
    int pre_to_max = *st[to].rbegin();
    if(pre_to_max != -1) max_rate.erase(max_rate.find(pre_to_max));
    st[from].erase(st[from].find(rate));
    st[to].insert(rate);

    int from_max = *st[from].rbegin();
    int to_max = *st[to].rbegin();

    if(from_max != -1 && changed) max_rate.insert(from_max);
    max_rate.insert(to_max);

    cout << *max_rate.begin() << '\n';
  }
  return 0;
}
