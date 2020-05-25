#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

void solve(){
    int N,M,A,B;
    cin >> N >> M >> A >> B;

    int n = N, m = M, a = A, b = B;

    int GCD = gcd(n, b);
    n /= GCD, b /= GCD;

    GCD = gcd(m, a);
    m /= GCD, a /= GCD;

    if(n != m || a != b) {
      cout << "NO" << '\n';
      return;
    }

    vector<vector<int>> board(N, vector<int> (M, 0));
    vector<int> cnt(M, 0);

    for (int i = 0; i < N; i++) {
      priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> que;
      for (int j = 0; j < M; j++) {
        pair<int,int> p = {cnt[j], j};
        que.push(p);
      }
      int k = A;
      while(k--) {
        int itr = que.top().second;
        que.pop();
        board[i][itr] = 1;
        cnt[itr]++;
      }
    }

    cout << "YES" << '\n';
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
        cout << board[i][j];
      }
      cout << '\n';
    }
    return;
}

int main() {
  int tc;
  cin >> tc;

  while(tc--){
      solve();
  }
}