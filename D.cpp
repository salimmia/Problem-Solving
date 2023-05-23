///Created by Salim_JnU

#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef unsigned long long ull;
typedef long double lld;
#define ff first
#define ss second

int const mxn = 30000;
ll const mod = 1000000007; //998244353

#define mt make_tuple
#define eb emplace_back
#define pb push_back

#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define INF 1e18
#define nl "\n"
#define PI 3.141592653589793238462

pair<int, int>a[mxn];
ll n, m, tt, k;
int const LOG = 20;

ll rmq[mxn][LOG][2];
ll lg[mxn];

void preprocess() {
	for (int i = 1; i <= n; i++) rmq[i][0][0] = rmq[i][0][1] = a[i].first;
	for (int j = 1; j < LOG; j++) {
		for (int i = 1; i <= n; i++) {
			if (i + (1 << j) - 1 <= n) {
				rmq[i][j][0] = min(rmq[i][j - 1][0], rmq[i + (1 << (j - 1))][j - 1][0]);
				rmq[i][j][1] = max(rmq[i][j - 1][1], rmq[i + (1 << (j - 1))][j - 1][1]);
			}
			else break ;
		}
	}
	for (int i = 2; i < mxn; i++) {
		lg[i] = lg[i / 2] + 1;
	}
}

ll query (int i , int j, int mn) {
	int k = lg[j - i + 1];
	ll ans;
	if (mn == 0) ans = min(rmq[i][k][mn], rmq[j - (1 << k) + 1][k][mn]);
	else ans = max(rmq[i][k][mn], rmq[j - (1 << k) + 1][k][mn]);
	return ans;
}

void solve()
{
	scanf("%lld", &n);

	for (int i = 1; i <= n; i++) {
		cin >> a[i].first;
		a[i].second = i;
	}

	sort(a + 1, a + n + 1);

	for (int i = 1; i <= n; i++) {
		a[i].first = i;
	}

	preprocess();

	ll ans = 0;

	for (int i = 1; i < n; i++) {
		for (int j = i + 1; j <= n; j++) {
			int mn = min(i, j, 0);

			int lo = i, hi = j - i + 1, re = -1;

			while (lo <= hi) {
				int mid = (lo + hi) >> 1;

				if (query())
				}
		}
	}

	return;
}

int main()
{
	int t = 1;
	scanf("%d", &t);
	for (int i = 1; i <= t; i++) {
		tt++;
		// printf("Case %d: ", i);
		solve();
	}
	return 0;
}

