#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define cl(x, v) memset((x), (v), sizeof(x))

#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define _ << ", " <<

typedef long long ll;
typedef long double ld;

typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const ld EPS = 1e-9, PI = acos(-1.);
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e5+5;

int a[4];

int main() {
  for (int i = 0; i < 4; ++i) scanf("%d", &a[i]);
  int ans = INF;
  do {
    ans = min(ans, abs(a[3]+a[0]-a[1]-a[2]));
  } while (next_permutation(a,a+4));
  printf("%d\n", ans);

  return 0;
}
