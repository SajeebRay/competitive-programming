#include <bits/stdc++.h>
using namespace std;

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
  #define db(x) ((void)0)
  #define dbs(x) ((void)0)
#endif

typedef long long ll;
typedef long double ld;

typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const ld EPS = 1e-9, PI = acos(-1.);
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e5+5;

int n, k1, k2, a[N], b[N];
multiset<int> d;

int main() {
  scanf("%d%d%d", &n, &k1, &k2);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  for (int i = 0; i < n; i++) scanf("%d", &b[i]);
  for (int i = 0; i < n; i++) d.insert(abs(a[i] - b[i]));

  int k = k1+k2;
  for (int i = 0; i < k; i++) {
    auto it = d.end();
    it--;
    int v = *it;
    d.erase(it);
    if (v <= 0) d.insert(v+1);
    else d.insert(v-1);
  }

  ll e = 0;
  for (int v : d) e += 1ll*v*v;
  printf("%lld\n", e);

  return 0;
}
