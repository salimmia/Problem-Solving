///Created by Salim_JnU

#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef unsigned long long ull;
typedef long double lld;
#define ff first
#define ss second

int const mxn = 300500;
ll const mod = 1000000007; //998244353

#define mt make_tuple
#define eb emplace_back
#define pb push_back

#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define INF 1e18
#define nl "\n"
#define PI 3.141592653589793238462

ll a[mxn];
ll n, m, tt, k;
int const LOG = 20;

ll rmq[mxn][LOG];
ll lg[mxn];

void preprocess() {
    for (int i = 1; i <= n; i++) rmq[i][0] = a[i] ;
    for (int j = 1; j < LOG; j++) {
        for (int i = 1; i <= n; i++) {
            if (i + (1 << j) - 1 <= n) {
                rmq[i][j] = max(rmq[i][j - 1], rmq[i + (1 << (j - 1))][j - 1]) ;
            }
            else break ;
        }
    }
    for (int i = 2; i < mxn; i++) {
        lg[i] = lg[i / 2] + 1;
    }
}

ll query (int i , int j) {
    int k = lg[j - i + 1];
    ll ans = max(rmq[i][k], rmq[j - (1 << k) + 1][k]);
    return ans;
}

int pos[mxn];

void solve()
{
    scanf("%lld", &n);

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pos[a[i]] = i;
    }

    preprocess();

    int l = 1, r = n;

    while (l != r) {
        int mxval = query(l, r);

        if (r - l + 1 == mxval && mxval != n) break;

        if (pos[mxval] > pos[1]) {
            r = pos[mxval] - 1;
        }
        else l = pos[mxval] + 1;
    }

    cout << r - l + 1 << endl;

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

