///Tested : https://codeforces.com/contest/1200/problem/E

/*
backup prime
307,367
1040160883,1066517951
1e9+7,1e9+9,1072857881,1000004249
*/


#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mxn 1000006

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
		h1 = Hashing(s, 1949313259, 2091573227); ///explanation: h3 = Hashing(s, 1949313259, 2091573227); h1 = h3;
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

	char ch[mxn], ch2[mxn];

	scanf("%s", ch);

	string res = ch;

	Hash hash1(ch);

	int sz = res.size();

	for (int i = 2; i <= n; i++)
	{
		scanf("%s", ch2);
		Hash hash2(ch2);

		int sz2 = strlen(ch2);

		int bad_jabe = 0;
		for (int j = 1; j <= min(sz, sz2); j++)
		{
			if (hash1.rangeHash(sz - j, sz - 1) == hash2.rangeHash(0, j - 1))
			{
				bad_jabe = j;
			}
		}
		for (int j = bad_jabe; j < sz2; j++)
		{
			hash1.charAdd(ch2[j]);
			sz++;
			res += ch2[j];
		}
	}

	cout << res << "\n";

}

int main()
{
	solve();

	return 0;
}