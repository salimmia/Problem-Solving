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

ll nCr(ll n, ll r)
{
    ll ans = n;

    for(int i = 1; i < r; i++)
    {
        ans *= (n - i);
        ans /= (i + 1);
    }

    return ans;
}


void solve_case(int tc)
{
    ll n;
    cin>>n;

    cout<<"Case "<<tc<<": ";

    bool ok = false;

    ll v = n;

    if(n >= 4)
    {
        v += nCr(n, 4);
    }

    ll e = n + nCr(n, 2) + 2 * nCr(n, 4);

    ll f = 2 + e - v;

    //watch(f);

    f--;

    if((f & (f - 1)) == 0) ok = true;

    if(ok)
    {
        cout<<"Yes"<<endl;
    }
    else cout<<"No"<<endl;

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


