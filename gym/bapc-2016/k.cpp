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
const int INF = 0x3f3f3f3f, MOD = 123456789;
const int N = 1e6+5;

int l, s;
int dp[N], p2[N];

int add(ll a, ll b) {
  a += b;
  if (a >= MOD) a -= MOD;
  return a;
}

int sub(ll a, ll b) {
  a -= b;
  if (a < 0) a += MOD;
  return a;
}

int mul(ll a, ll b) {
  return (a*b)%MOD;
}

int main() {
  scanf("%d%d", &l, &s);

  p2[0] = 1;
  for (int i = 1; i < l; i++)
    p2[i] = add(p2[i-1], p2[i-1]);

  dp[0] = 1;
  int sum = 1;
  for (int i = 1; i <= l; i++) {
    int d = i > s ? dp[i-s-1] : 0;
    dp[i] = sub(sum, d);
    sum = sub(add(sum, dp[i]), d);
  }

  int ans = dp[l];
  for (int i = 3; i <= s+1; i++)
    ans = add(ans, mul(i-2, dp[l-i+1]));

  printf("%d\n", ans);
  return 0;
}
