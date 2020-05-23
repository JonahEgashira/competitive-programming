#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
#define P pair<int,pair<int,int>>

const int dx[4] = {1,-1,0,0};
const int dy[4] = {0,0,1,-1};

const int mod = 1e9 + 7;

int main() {
  int h,w;
  cin >> h >> w;

  vector<vector<int>> a(h, vector<int> (w));
  priority_queue<P, vector<P>, greater<>> que;
  rep(i, h) rep(j, w) {
    int x;
    cin >> x;

    a[i][j] = x;
    P p = {x, {i, j}};
    que.push(p);
  }

  vector<vector<int>> cnt(h, vector<int> (w,1));
  while(!que.empty()) {
    int i = que.top().second.first;
    int j = que.top().second.second;

    que.pop();
    for (int k = 0; k < 4; k++) {
      int ni = i + dx[k];
      int nj = j + dy[k];

      if(ni >= 0 && ni < h && nj >= 0 && nj < w && a[ni][nj] > a[i][j]) {
        cnt[ni][nj] += cnt[i][j];
        cnt[ni][nj] %= mod;
      }
    }
  }


  int res = 0;
  rep(i,h) rep(j,w) {
    res += cnt[i][j];
    res %= mod;
  }
  cout << res << '\n';
}