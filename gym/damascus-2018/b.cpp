// @subject: 
// @diff: 

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
std::mt19937_64 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define cl(x, v) memset((x), (v), sizeof(x))
#define gcd(x,y) __gcd((x),(y))

#ifndef ONLINE_JUDGE
  #define db(x) cerr << #x << " == " << x << endl
  #define dbs(x) cerr << x << endl
  #define _ << ", " <<
#else
  #define db(x) 42
  #define dbs(x) 42
#endif

typedef long long ll;
typedef long double ld;

typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const ld EPS = 1e-9, PI = acos(-1.);
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 2e3+5;

/*
const ll H[2] = { MOD, MOD+2 };
const ll B[2] = { 61, 7901 };
*/
const ll P = MOD;
const ll B = 7901;

int t, n, x[N];
ll h, p[N];
map<ll, ll> mm;

void update(int x, int v) {
  h += v * p[x];
  mm[h]++;
}

int main() {
  p[0] = 1;
  for (int i = 1; i < N; i++) p[i] = p[i-1] * P;

  scanf("%d", &t);
  while (t--) {
    mm.clear();

    scanf("%d", &n);

    map<pii, int> m;
    int cnt = 0;
    for (int u, v, i = 0; i < n; i++) {
      scanf("%d%d", &u, &v);

      if (u > v) swap(u, v);
      pii p = { u, v };
      if (m.count(p)) x[i] = m[p];
      else x[i] = m[p] = ++cnt;
    }

    for (int i = 0; i < n; i++) {
      h = 0;
      for (int j = i; j < n; j++) update(x[j], 1);
    }

    ll ans = 0;
    for (auto p : mm) {
      ll k = p.nd;
      ans += k*(k-1)/2;
    }

    printf("%lld\n", ans);
  }
  return 0;
}
