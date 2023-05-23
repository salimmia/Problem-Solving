https://atcoder.jp/contests/abc141/tasks/abc141_e
/*
backup prime
307,367
1040160883,1066517951
1e9+7,1e9+9,1072857881,1000004249
*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mxn 5003

struct Hashing
{
    ll base, mod;
    int sz;

    vector<int>reverse_hash, forward_hash, base_powers;

    Hashing() {}
    Hashing(const char* s, ll b, ll m)
    {
        sz = strlen(s), base = b, mod = m;
        reverse_hash.resize(sz + 1, 0), forward_hash.resize(sz + 1, 0), base_powers.resize(sz + 1, 1);
        for (int i = 1; i <= sz; i++)
            base_powers[i] = (base * base_powers[i - 1]) % mod;
        for (int i = 1; i <= sz; i++)
            forward_hash[i] = (forward_hash[i - 1] * base + (s[i - 1] - 'a' + 1)) % mod; /// digit hole s[i-1]-'0'
        for (int i = sz; i >= 1; i--)
            reverse_hash[i] = (reverse_hash[i + 1] * base + (s[i - 1] - 'a' + 1)) % mod; ///alphabet hole s[i-1]-'a'
    }
    void singleCharAdd(char c)
    {
        base_powers.push_back((base_powers.back()*base) % mod);
        forward_hash.push_back((forward_hash.back()*base + (c - 'a' + 1)) % mod);
    }
    inline int rangeHash(int l, int r)
    {
        int re_hash = forward_hash[r + 1] - ((ll)base_powers[r - l + 1] * forward_hash[l] % mod);
        if (re_hash < 0)re_hash += mod;
        return re_hash;
    }
    inline int revRangeHash(int l, int r)
    {
        int re_hash = reverse_hash[l + 1] - ((ll)base_powers[r - l + 1] * reverse_hash[r + 2] % mod);
        if (re_hash < 0)re_hash += mod;
        return re_hash;
    }
};
struct Hash
{
    Hashing h1, h2;
    Hash() {}
    Hash(const char* s)
    {
        h1 = Hashing(s, 1949313259, 2091573227);
        h2 = Hashing(s, 1997293877, 2117566807);
    }
    void charAdd(char cc)
    {
        h1.singleCharAdd(cc);
        h2.singleCharAdd(cc);
    }
    inline ll rangeHash(int l, int r) ///*** O base index
    {
        return ((ll)h1.rangeHash(l, r) << 32)^h2.rangeHash(l, r);
    }
    inline ll revRangeHash(int l, int r) ///*** O base index
    {
        return ((ll)h1.revRangeHash(l, r) << 32)^h2.revRangeHash(l, r);
    }
};



void solve()
{
    int n;
    scanf("%d", &n);

    char ch[mxn];

    scanf("%s", ch);

    Hash h1(ch);

    int res = 0;
    int be = 1, en = n / 2;

    while (be <= en)
    {
        int mid = (be + en) / 2;

        map<ll, int> mp;

        for (int i = 0; i + mid - 1 < n; i++)
        {
            ll hash = h1.rangeHash(i, i + mid - 1);
            if (mp.count(hash))
            {
                int previ = mp[hash];

                if (i - previ >= mid)
                {
                    res = mid;
                    break;
                }

            }
            else mp[hash] = i;
        }

        if (res == mid)
        {
            be = mid + 1;
        }
        else
        {
            en = mid - 1;
        }
    }

    cout << res << endl;

}

int main()
{
    solve();

    return 0;
}