#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }

const int N = 110;
int board[N][N];
int filled[N][N];

const int odx[6] = {0, 1, 1, -1, 0, 1};
const int ody[6] = {-1, -1, 0, 0, 1, 1};

const int edx[6] = {-1, 0, 1, -1, 0, -1};
const int edy[6] = {-1, -1, 0, 0, 1, 1};

int w, h;
bool is_in(int x, int y, int W, int H) {
  if(0 <= x && x <= W && 0 <= y && y <= H) return true;
  return false;
}

signed main() {
  cin >> w >> h;

  for (int i = 1; i <= h; i++) {
    for (int j = 1; j <= w; j++) {
      cin >> board[i][j];
    }
  }

  using P = pair<int,int>;
  queue<P> que;
  filled[0][0] = 1;

  que.push({0,0});
  while(!que.empty()) {
    int cy = que.front().first;
    int cx = que.front().second;
    que.pop();

    for (int i = 0; i < 6; i++) {
      int nx = cx;
      int ny = cy;
      if(cy % 2 == 0) {
        nx += edx[i];
        ny += edy[i];
      } else {
        nx += odx[i];
        ny += ody[i];
      }

      if(!is_in(nx, ny, N - 1, N - 1)) continue;
      if(filled[ny][nx]) continue;
      if(is_in(nx, ny, w, h) && board[ny][nx] == 1) continue;

      que.push({ny, nx});
      filled[ny][nx] = 1;
    }
  }

  int ans = 0;
  for (int y = 0; y < N; y++) {
    for (int x = 0; x < N; x++) {
      if(!filled[y][x]) continue;

      for (int k = 0; k < 6; k++) {
        int ny = y;
        int nx = x;
        if(y % 2 == 0) {
          ny += edy[k];
          nx += edx[k];
        } else {
          ny += ody[k];
          nx += odx[k];
        }

        if(!is_in(nx, ny, w, h)) continue;
        if(board[ny][nx] == 1) ans++;
      }
    }
  }
  /*
  cout << "BOARD" << endl;
  rep(i,h + 2) {
    rep(j,w + 2) {
      cout << board[i][j] << " ";
    }
    cout << endl;
  }
  cout << "-----------------" << endl;
  cout << "FILLED" << endl;
  rep(i,h + 2) {
    rep(j,w + 2) {
      cout << filled[i][j] << " ";
    }
    cout << endl;
  }
  */

  cout << ans << '\n';

}
