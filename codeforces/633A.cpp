#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define mp make_pair
#define pb push_back

#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define _ << ", " <<

typedef long long ll;
typedef long double ld;

typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef vector<int> vi;
typedef vector<vi> vvi;

const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e7;

int a, b, c;

int main() {
  scanf("%d%d%d", &a, &b, &c);
  for (int i = 0; i <= 10000 and a*i <= c; ++i)
    if ((c-i*a)%b == 0) { printf("Yes\n"); return 0; }
  printf("No\n");
  return 0;
}
