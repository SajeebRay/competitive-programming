#include <bits/stdc++.h>
using namespace std;

#define pb push_back

typedef long long ll;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

const int N = 1e7;

int n, m, l, s, res;
int a[10000000];

int main() {
  scanf("%d%d", &n, &m);
  n*=2, m*=3;
  for (int i = 6; i <= min(n, m); i+=6) {
    if (n+2 < m+3) n+=2;
    else m+=3;
  }

  printf("%d\n", max(n, m));

  return 0;
}
