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

ll fact[mxn];
int c[mxn];

//call calc() from main function 
void calc()
{
    fact[0] = fact[1] = 1;

    for(int i = 2; i < mxn; i++)
    {
        fact[i] = (fact[i-1] * i) % mod; 
    }

    return;
}

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

ll modInv(ll x) ///// IF mod is prime using Bigmod()
{
    return Bigmod(x,mod-2)%mod; 
}

ll add(ll a, ll b) {
    a += b;
    if (a >= mod) a -= mod;
    return a;
}

ll mul(ll a, ll b) {
    return a * 1ll * b % mod;
}



int cnt(int x, int b)
{
    if(x < b) return 0;
    if(c[x] != -1) return c[x];

    int val = x / b;
    
    return c[x] = val + cnt(val, b);
}

///mod Inverse of all fact[i] where i : 1 to N 
///with respect to mod (N < mod and mod is prime)
int inv[mxn];
//Call modInvAll() form main function 
void modInvAll()
{
    for(int i = 0; i < mxn; i++)
    {
        inv[i] = modInv(fact[i]);
    }
}

ll nCr(ll n, ll r)
{
    return mul(fact[n],mul(inv[r], inv[n - r]));
}


void solve_case(int tc)
{
    int n, b;
    scanf("%d %d", &n, &b);

    for(int i = 1; i <= n; i++) c[i] = -1;

    int ans = 0;

    for(int i = 1; i <= n; i++)
    {
        //watch2(i, cnt(i, b));
        //cout<<nCr(n - 1, i - 1)<<endl;
        int a = (cnt(i, b) * nCr(n - 1, i - 1)) % mod;

        ans = add(ans, a);
        //watch2(i, ans);
    }

    printf("Case %d: %lld\n", tc, ans);

    //cout<<"Case "<<tc<<": "<<ans<<endl;

    return;
}

int main()
{
    calc();
    modInvAll();

//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);


    int test_case=1;
    //cin>>test_case;
    scanf("%d", &test_case);
    for(int tc=1 ; tc<=test_case; tc++)
    {
        solve_case(tc);
    }
///  KeyPoint


///  Corner Cases




    return 0;
}


