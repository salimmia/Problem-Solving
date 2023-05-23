#include<bits/stdc++.h>
using namespace std;


///typedef
typedef long long ll;
typedef pair<int, int> pii;

///define constant
const ll mxn = 100005;
const int mod = 1000000007;//1e9+7;

///faster io
#define faster_io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

///debug
#define watch(x) cout << __LINE__ << " says: " << #x << " = " << x << "\n"
#define watch2(x,y) cout<< __LINE__ << " says: " <<#x<<" = "<<x<<" "<<#y<<" = "<<y <<endl
#define watch3(x,y,z) cout<< __LINE__ << " says: " <<#x<<" = "<<x<<" "<<#y<<" = "<<y <<" "<<#z<<" = "<<z<<endl


///program starts...........


ll add(ll a, ll b) {
    a += b;
    if (a >= mod) a -= mod;
    return a;
}
ll sub(ll a,ll b)
{
    a-=b;
    if(a<0)a+=mod;
    return a;
}
ll mul(ll a, ll b) {
    return a * 1ll * b % mod;
}


ll fact[mxn];
//call calc() from main function 
//T.C: O(n)
void calc()
{
    fact[0] = fact[1] = 1;
    for(int i = 2; i < mxn; i++)
    {
        fact[i] = (fact[i-1] * i) % mod; 
    }
    return;
}

//T.C: O(log(n)) 
ll Bigmod(ll x,ll n)
{
    if(n==0) 
        return 1 % mod;
    ll res = Bigmod(x, n/2);
    res = (res * res) % mod;
    if(n & 1)
        res = (res * x) % mod;
    return res;
}
//T.C: O(log(n)) 
ll modInv(ll x) ///// IF mod is prime using Bigmod()
{
    return Bigmod(x,mod-2)%mod; 
}
//T.C: O(log(n)) 
ll nCr(ll n, ll r) /// *** using movInv() function
{
    return mul(fact[n], mul(modInv(fact[r]), modInv(fact[n - r])));
}

vector<int> g[mxn];

map<pii, bool> mp;
int vis[mxn];
vector <int> cycle;
int  len;
int n, k;

void clr()
{
	len = 0;
	mp.clear();
	cycle.clear();
	for(int i = 1; i <= n; i++)
	{
		g[i].clear();
		vis[i] = 0;
	}
}

void dfs(int u, int p)
{
	if(len) return;

	vis[u] = 1;
	cycle.push_back(u);
	for(auto v : g[u])
	{
		if(len) break;
		if(v == p) continue;

		if(vis[v] == 1)
		{
			while(cycle.back() != v)
			{
				len++;
				cycle.pop_back();
			}
			len++;

			break;
		}
		else if(vis[v] == 0)
		{
			dfs(v, u);
		}
	}
	if(len) return;
	cycle.pop_back();

}

void solve_case(int tc)
{
	cin>>n>>k;

	clr();

	for(int i = 1; i <= n; i++)
	{
		int u, v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);

		if(u > v) swap(u, v);

		if(mp.count({u, v}))
		{
			len = 2;
		}
		if(u == v)
		{
			len = 1;
		}

		mp[{u, v}] = 1;
	}


	if(len == 0) dfs(1, -1);

	ll up = nCr(n, k);

	//watch(up);

	up = add(up, mul(mul(len, n - k), nCr(n - 1, k - 1)));

	ll down = nCr(n, k);
	down = mul(down, down);

	//watch2(up, down);

	ll ans;

	ans  = mul(up, modInv(down));

	ans = sub(1, ans);

	cout<<ans<<endl;

    return;
}

int main()
{
    faster_io;
    calc();
    //fact_cal();

//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);


    int test_case=1;
    cin>>test_case;
    //watch(test_case);
    for(int tc=1 ; tc<=test_case; tc++)
    {
        solve_case(tc);
    }
///  KeyPoint


///  Corner Cases




    return 0;
}


