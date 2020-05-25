#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

int main() {
  int n;
  cin >> n;

  vector<vector<int>> a(n, vector<int>(n - 1));
  rep(i, n) rep(j, n - 1) {
      cin >> a[i][j];
      a[i][j]--;
  }

  vector<int> itr(n, 0);
  queue<int> que;
  set<int> end;

  for (int i = 0; i < n; i++) que.push(i);

  int day = 0;
  while(end.size() < n) {
    set<int> played;
    que.push(n);
    while(1) {
     int i = que.front();
     que.pop();
     if(i == n) break;

     if(played.count(i)) continue;
     if(end.count(i)) continue;

     int opp = a[i][itr[i]];
     if(played.count(opp)) continue;
     if(end.count(opp)) continue;

     if(a[opp][itr[opp]] == i) {

       que.push(i);
       que.push(opp);

       itr[i]++;
       itr[opp]++;

       if(itr[i] == n - 1) end.insert(i);
       if(itr[opp] == n - 1) end.insert(opp);

       played.insert(i);
       played.insert(opp);
     }
    }
    if(played.empty()) {
      cout << -1 << '\n';
      return 0;
    }
    day++;
  }
  cout << day << '\n';
}