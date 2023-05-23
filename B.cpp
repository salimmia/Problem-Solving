#include<bits/stdc++.h>
using namespace std;

#define ll long long

int const mx = 200500;

ll ar[mx], n, m;

int main()
{
    int t = 1;
    cin >> t;

    while (t--) {
        cin >> n >> m;

        ll xx = min(n, m);

        vector<bool>used(m + 1);

        set<int>st;
        vector<int>v;

        ll one = 0, two = 0, three = 0, oo, tw;

        for (int i = 1; i <= n; i++) {
            cin >> ar[i];

            if (ar[i] == -1) {
                one++;
            }
            else if (ar[i] == -2) {
                two++;
            }
            else st.insert(ar[i]);
        }

        for (auto x : st) {
            v.push_back(x);
        }

        oo = one, tw = two;

        one = one + (int)st.size();
        two = two + (int)st.size();

        for (ll i = 1; i <= n; i++) {

            if (ar[i] > 0) {
                if (used[ar[i]]) continue;
                int x = lower_bound(v.begin(), v.end(), ar[i]) - v.begin();

                ll xtrafs = x, xtrasec = max(0LL, (ll)v.size() - x - 1);

                three = max(three, (min(ar[i] - 1, oo + xtrafs) + min(m - ar[i], tw + xtrasec)) + 1);
                used[ar[i]] = true;
            }
        }
        // cout << endl;

        ll ans = min(xx, max({one, two, three}));

        cout << ans << endl;
    }
    return 0;
}