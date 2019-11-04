// @subject: 
// @diff: 

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

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
const int N = 1e5+5;

int di[] = { 1, 1, 0, -1, -1, -1, 0, 1 };
int dj[] = { 0, -1, -1, -1, 0, 1, 1, 1 };

int q;
ll n, m, k;

ll solv(ll n, ll m, ll k) {
  if (n < m) swap(n, m);
  if (n > k) return -1;

  ll res = 0;
  if ((n-m)&1) {
    res = k-1;
  } else {
    if ((k-m)%2 == 0) res = k;
    else res = k-2;
  }

  return res;
}

int main() {
  scanf("%d", &q);
  while (q--) {
    scanf("%lld%lld%lld", &n, &m, &k);
    printf("%lld\n", solv(n, m, k));
  }

  return 0;
}
