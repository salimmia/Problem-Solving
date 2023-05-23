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
ll fs = 0, sec = 0, th = 0, oo, tw;
ll done[mxn];

void solve()
{
    scanf("%lld%lld", &n, &m);

    ll mxseat = min(n, m);

    set<int> position;
    vector<int> vec;

    fs = 0, sec = 0, th = 0;

    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);

        if (a[i] == -1) fs++;
        else if (a[i] == -2) sec++;
        else position.insert(a[i]);
    }
    oo = fs, tw = sec;
    fs += position.size();
    sec += position.size();

    for (auto x : position) vec.push_back(x);
    ll ans = min(mxseat, max(fs, sec));

    for (ll i = 1; i <= n; i++) {
        if (a[i] > 0) {
            if (done[a[i]])
                continue;
            else {
                int id = lower_bound(vec.begin(), vec.end(), a[i]) - vec.begin();
                ll xtrafs = id;
                ll xtrasec = max(0LL, (ll)vec.size() - id - 1);
                th = max(th, (min(a[i] - 1, oo + xtrafs) + min(m - a[i], tw + xtrasec)) + 1);
                done[a[i]] = true;
            }
        }
    }

    ans = min(mxseat, max(ans, th));

    printf("%lld\n", ans);

    for (int i = 0; i <= m; i++) done[i] = false;

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

