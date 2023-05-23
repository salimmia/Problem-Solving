#include<bits/stdc++.h>
using namespace std;


///typedef
typedef long long ll;
typedef pair<int, int> pii;

///define constant
const ll mxn = 200005;
const int mod = 1000000007;//1e9+7;

///faster io
#define faster_io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

///debug
#define watch(x) cout << __LINE__ << " says: " << #x << " = " << x << "\n"
#define watch2(x,y) cout<< __LINE__ << " says: " <<#x<<" = "<<x<<" "<<#y<<" = "<<y <<endl
#define watch3(x,y,z) cout<< __LINE__ << " says: " <<#x<<" = "<<x<<" "<<#y<<" = "<<y <<" "<<#z<<" = "<<z<<endl


///program starts...........


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



void solve_case(int tc)
{
    ll n, m;
    cin>>n>>m;


    ll ans = Bigmod(n - 1, m);
    ll temp = Bigmod(n, m);

    ans = mul(ans, modInv(temp));

    ans = sub(1, ans);

    ans = mul(ans, n);

    

    cout<<"Case "<<tc<<": ";

    cout<<ans<<endl;



    return;
}

int main()
{
    faster_io;

//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);


    int test_case=1;
    cin>>test_case;
    for(int tc=1 ; tc<=test_case; tc++)
    {
        solve_case(tc);
    }
///  KeyPoint


///  Corner Cases




    return 0;
}


