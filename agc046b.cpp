#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

const int mod = 998244353;

struct mint {
    ll x;

    mint(ll x = 0) : x((x % mod + mod) % mod) {}

    mint operator-() const { return mint(-x); }

    mint &operator+=(const mint a) {
      if ((x += a.x) >= mod) x -= mod;
      return *this;
    }

    mint &operator-=(const mint a) {
      if ((x += mod - a.x) >= mod) x -= mod;
      return *this;
    }

    mint &operator*=(const mint a) {
      (x *= a.x) %= mod;
      return *this;
    }

    mint operator+(const mint a) const {
      mint res(*this);
      return res += a;
    }

    mint operator-(const mint a) const {
      mint res(*this);
      return res -= a;
    }

    mint operator*(const mint a) const {
      mint res(*this);
      return res *= a;
    }

    mint pow(ll t) const {
      if (!t) return 1;
      mint a = pow(t >> 1);
      a *= a;
      if (t & 1) a *= *this;
      return a;
    }

    mint inv() const {
      return pow(mod - 2);
    }

    mint &operator/=(const mint a) {
      return (*this) *= a.inv();
    }

    mint operator/(const mint a) const {
      mint res(*this);
      return res /= a;
    }
};

mint dp[3030][3030];

int main() {
  int a,b,c,d;
  cin >> a >> b >> c >> d;

  rep(i,3030) rep(j,3030) dp[i][j] = 0;
  dp[a][b] = 1;

  for (int h = a; h <= c; h++) {
    for (int w = b; w <= d; w++) {
      if(h > a) dp[h][w] += dp[h - 1][w] * w;
      if(w > b) dp[h][w] += dp[h][w - 1] * h;
      if(h > a && w > b) dp[h][w] -= dp[h - 1][w - 1] * (h - 1) * (w - 1);
    }
  }

  cout << dp[c][d].x << '\n';
  return 0;
}
