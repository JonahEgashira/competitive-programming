#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

const int dx[4] = {1,-1,0,0};
const int dy[4] = {0,0,1,-1};

void solve(){
  int n,m;
  cin >> n >> m;

  vector<vector<char>> board(n, vector<char>(m));
  vector<pair<int,int>> good, bad;
  rep(i,n) {
    rep(j,m) {
      cin >> board[i][j];
      if(board[i][j] == 'G') good.emplace_back(i,j);
      if(board[i][j] == 'B') bad.emplace_back(i,j);
    }
  }

  if(good.empty()) {
    cout << "Yes" << '\n';
    return;
  }

  for (int i = 0; i < (int)bad.size(); i++) {
    int x = bad[i].first, y = bad[i].second;
    for (int j = 0; j < 4; j++) {
      int nx = x + dx[j], ny = y + dy[j];
      if(nx >= 0 && nx < n && ny >= 0 && ny < m) {
        if(board[nx][ny] == '.') board[nx][ny] = '#';
        if(board[nx][ny] == 'G') {
          cout << "No" << '\n';
          return;
        }
      }
    }
  }

  queue<pair<int,int>> que;
  vector<vector<int>> dist(n, vector<int>(m,-1));
  if(board[n-1][m-1] != '#') {
    que.emplace(n-1,m-1);
    dist[n-1][m-1] = 0;
  }

  while(!que.empty()) {
    int x = que.front().first;
    int y = que.front().second;
    que.pop();

    for (int i = 0; i < 4; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];

      if(nx >= 0 && nx < n && ny >= 0 && ny < m && board[nx][ny] != '#' && dist[nx][ny] == -1) {
        que.emplace(nx,ny);
        dist[nx][ny] = dist[x][y] + 1;
      }
    }
  }

  rep(i,n) rep(j,m) {
    if(board[i][j] == 'G' && dist[i][j] == -1) {
      cout << "No" << '\n';
      return;
    }
  }

  cout << "Yes" << '\n';
  return;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int tc;
  cin >> tc;

  while(tc--){
    solve();
  }

  return 0;
}