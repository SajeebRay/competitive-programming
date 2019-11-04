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
const int N = 1e4+5;

int n, k, a[N], ans[N];
set<int> c[N];
set<int> f;

int main() {
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);

  for (int i = 1; i <= k; i++) f.insert(i);

  for (int i = 0; i < n; i++) {
    int ok = 0;
    for (int x : f) if (!c[a[i]].count(x)) {
      c[a[i]].insert(x);
      f.erase(x);

      ans[i] = x;
      ok = 1;

      break;
    }

    if (!ok) {
      for (int j = 1; j <= k; j++) if (!c[a[i]].count(j)) {
        c[a[i]].insert(j);
        ans[i] = j;
        ok = 1;
        break;
      }

      if (!ok) return printf("NO\n"), 0;
    }
  }

  printf("YES\n");
  for (int i = 0; i < n; i++) printf("%d ", ans[i]);
  printf("\n");

  return 0;
}
