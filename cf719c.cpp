#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <functional>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <bitset>
#include <math.h>
#include <random>
#include <chrono>
#include <assert.h>
#include <climits>

using namespace std;
#define int long long

void solve(){
  int n;
  cin >> n;

  if (n == 2) {
    cout << -1 << '\n';
    return;
  }

  vector<vector<int>> res(n,vector<int>(n));
  int num = 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      res[(j+i)%n][j] = num;
      num++;
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << res[i][j] << " ";
    }
    cout << '\n';
  }
}

signed main() {
  int tc;
  cin >> tc;

  while(tc--){
    solve();
  }
}
