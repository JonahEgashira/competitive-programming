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
#include <fstream>

using namespace std;
#define int long long

signed main() {
  int n,l,k;
  cin >> n >> l >> k;
  vector<int> a(n);
  for (auto &it : a) cin >> it;
  a.push_back(l);
  n++;

  int mi = 0, ma = INT_MAX;
  while(ma - mi > 1) {
    int mid = (mi + ma) / 2;
    int prev = 0;
    int cut = 0;
    for (int i = 0; i < n; i++) {
      if (a[i] - prev >= mid) {
        cut++;
        prev = a[i];
      }
    }
    if (cut >= k + 1) mi = mid;
    else ma = mid;
  }
  cout << mi << '\n';
}