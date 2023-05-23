#include<bits/stdc++.h>
using namespace std;


///typedef
typedef long long ll;
typedef pair<int, int> pii;

///define constant
const ll mxn = 200005;
const int mod = 100000007;//1e9+7;

///faster io
#define faster_io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

///debug
#define watch(x) cout << __LINE__ << " says: " << #x << " = " << x << "\n"
#define watch2(x,y) cout<< __LINE__ << " says: " <<#x<<" = "<<x<<" "<<#y<<" = "<<y <<endl
#define watch3(x,y,z) cout<< __LINE__ << " says: " <<#x<<" = "<<x<<" "<<#y<<" = "<<y <<" "<<#z<<" = "<<z<<endl


///program starts...........

int n, K, arr[51], cnt[51];
ll dp[1003][1003];
ll vis[1003][1003];
int test_no;

ll ways(int pos, int k)
{
    if(k == 0) return 1;
    if(pos >= n or k < 0) return 0;

    if(vis[pos][k] == test_no)
    {
        return dp[pos][k];
    }
    vis[pos][k] = test_no;

    ll ans = 0;

    for(int c = 0; c <= cnt[pos]; c++)
    {
        ans += ways(pos + 1, k - c * arr[pos]);
    }



    return dp[pos][k] = ans % mod;

}


void solve_case(int tc)
{
    test_no = tc;
    cout<<"Case "<<tc<<": ";
    cin>>n;
    cin>>K;

    for(int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }

    for(int i = 0; i < n; i++)
    {
        cin>>cnt[i];
    }

    cout<<ways(0, K)<<endl;

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


