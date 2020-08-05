#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
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

const int N = 300030;
mint table[N];

void init() {
  table[0] = table[1] = 1;
  for (ll i = 2; i < N; i++) {
    table[i] = table[i - 1] * i;
  }
}

mint nCr(int n, int r) {
  return table[n] / table[r] / table[n - r];
}

signed main() {
  ll n,a,b,k;
  cin >> n >> a >> b >> k;

  init();

  mint answer = 0;
  for (int i = 0; i <= n; i++) {
    ll tmp = k - a * i;
    if (tmp % b != 0) continue;

    ll a_cnt = i;
    ll b_cnt = tmp / b;

    if(b_cnt > n || b_cnt < 0) continue;

    answer = answer + nCr(n, a_cnt) * nCr(n, b_cnt);
  }

  cout << answer.x << '\n';
  return 0;
}

