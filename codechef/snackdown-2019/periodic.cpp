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

int t, n, a[N];

int mod(int x, int k) {
  return (x%k + k)%k;
}

int verify(int k) {
  //db(k);
  int shift = 0;
  for (int i = 0; i < n; i++)
    if (a[i] != -1)
      shift = mod(i-a[i]+1, k);
  //db(shift);

  for (int i = 0; i < n; i++)
    if (a[i] != -1 and a[i] != mod(i-shift, k) + 1)
      return 0;
  //db("ok");
  return 1;
}

int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);

    vector<int> v;
    for (int i = 0; i < n; i++) if (a[i] != -1) {
      v.push_back(i-a[i]+1);
      //db(i _ a[i] _ i-a[i]+1);
    }

    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    /*
    for (int x : v) db(x);
    dbs("");
    */

    if (v.size() <= 1) printf("inf\n");
    else {
      int k = 0;
      for (int i = 1; i < (int)v.size(); i++)
        k = gcd(k, v[i]-v[i-1]);

      int ans = 0;
      for (int i = 1; i*i <= k; i++) if (k%i == 0) {
        if (verify(i)) ans = max(ans, i);
        if (verify(k/i)) ans = max(ans, k/i);
      }

      if (ans == 0) printf("impossible\n");
      else printf("%d\n", ans);
    }
  }
  return 0;
}
