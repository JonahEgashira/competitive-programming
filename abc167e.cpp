#include <bits/stdc++.h>
using namespace std;
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

mint table[200020];
void init() {
  table[0] = table[1] = 1;
  for (int i = 2; i < 200020; i++) {
    table[i] = table[i - 1] * i;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n, m, k;
  cin >> n >> m >> k;

  init();
  mint ans = 0;

  for (ll d = n - k - 1; d <= n - 1; d++) {
    mint comb = table[n - 1] / table[n - 1 - d] / table[d];
    mint p = mint(m - 1).pow(d);
    p *= m;
    mint tmp = comb * p;
    ans += tmp;
  }
  cout << ans.x << endl;
  return 0;
}
