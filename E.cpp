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

ll pre = 0;

void solve()
{
    scanf("%lld", &n);


    ll cnt = 0;

    for (int i = 1; i <= n; i++) {
        int x = i;

        bool f = true;

        while (x) {
            f &= (x % 10 != 4);

            x /= 10;
        }
        cnt += !f;
    }

    cout << cnt << " " << cnt - pre << endl;

    pre = cnt;

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

