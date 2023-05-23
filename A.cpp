///Creater by Salim_JnU

#include<bits/stdc++.h>
using namespace std;

#define mx 200005
#define ll long long
#define mod 1000000007 //998244353

int a[mx];
char ch[mx];
int n, m, tt, k;

void solve()
{
    scanf("%d", &n);

    map<int, int> mp;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mp[a[i]]++;
    }

    int cnt = 0;

    ll ans = 0;

    while (cnt < n) {
        int mn = n;
        ll now = 1;
        for (auto [x, y] : mp) {
            mn =  min(mn, y);
            now *= x;
        }
        ans += mn * now;
        for (auto &[x, y] : mp) {
            y -= mn;
            if (y == 0) mp.erase(mp.find(x));
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
