#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;

const int mod = 1000000007;
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

signed main() {
  int n;
  cin >> n;

  mint fact = 1;
  for (ll i = 1; i <= n - 1; i++) fact *= i;

  vector<ll> a(n);
  vector<mint> cnt(n);
  rep(i,n) cin >> a[i];

  for (int i = 1; i < n; i++) {
    cnt[i] += fact/i + cnt[i - 1];
  }

  mint ans = 0;
  for (int i = 1; i < n; i++) {
    mint dist = a[i] - a[i - 1];
    ans += dist * cnt[i];
  }
  cout << ans.x << '\n';
}