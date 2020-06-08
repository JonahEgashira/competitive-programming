#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
  int n,m;
  cin >> n >> m;

  vector<vector<int>> board(n,vector<int>(m));
  vector<int> row(n), col(m);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> board[i][j];
      if(board[i][j]) {
        row[i] = 1, col[j] = 1;
      }
    }
  }

  int turn = 0;
  while(true) {
    bool flag = false;
    for (int i = 0; i < n; i++) {
      if(row[i]) continue;
      for (int j = 0; j < m; j++) {
        if(col[j] == 0) {
          flag = true;
          row[i] = 1;
          col[j] = 1;
          break;
        }
      }
      if(flag) break;
    }

    if(flag) turn = turn ^ 1;
    else break;
  }

  if(turn) cout << "Ashish" << '\n';
  else cout << "Vivek" << '\n';

}

int main() {
  int tc;
  cin >> tc;

  while(tc--){
    solve();
  }
  return 0;
}