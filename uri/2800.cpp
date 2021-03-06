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


int n, q, a[N];
ordered_set s[N];

int main() {
  scanf("%d%d", &n, &q);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    s[a[i]].insert(i);
  }

  for (int t, x, y, w, i = 0; i < q; i++) {
    scanf("%d", &t);
    if (t == 1) {
      scanf("%d%d", &x, &w);
      s[a[x]].erase(x);
      a[x] = w;
      s[a[x]].insert(x);
    } else {
      scanf("%d%d%d", &x, &y, &w);
      printf("%d\n", y-x+1 - (int)(s[w].order_of_key(y+1) - s[w].order_of_key(x)));
    }
  }
  return 0;
}
