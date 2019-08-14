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
const int N = 1e5+5;

int n, l, r, a[N];
vector<int> v;
int dp[N];

int test(int x) {
  memset(dp, 0, sizeof dp);
  dp[0] = 1;
  int val = v[x];
  //db(val);

  int pre = 0, acc = 0;
  for (int i = 1; i <= n; i++) {
    //db(i _ pre);
    acc += (a[i] >= val);

    if (i-pre > r or !dp[pre]) {
      //db("ok");
      for (; pre < i-r; pre++, acc -= (a[pre] >= val)) ;
      for (; pre < i and !dp[pre]; pre++, acc -= (a[pre] >= val));
    }

    if (i >= l and acc and i-pre>=l) dp[i] = 1;
    //db(i _ acc _ pre _ dp[i]);
  }

  //dbs("");

  return dp[n];
}

int main() {
  scanf("%d%d%d", &n, &l, &r);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]), v.push_back(a[i]);
  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());

  int lo = 0, hi = v.size()-1;
  while (lo < hi) {
    int md = (lo+hi+1)/2;
    //db(lo _ md _ hi _ v[md] _ test(md));
    if (test(md)) lo = md;
    else hi = md-1;
  }

  printf("%d\n", v[lo]);

  return 0;
}
