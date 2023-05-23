https://lightoj.com/problem/how-many-zeroes
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

string s;

ll dp2[11][2];
ll dp[11][2][2];

ll func2(int pos, int isSmall)
{
    //watch2(pos, isSmall);
    if(pos == s.size()) return 1;

    if(dp2[pos][isSmall] != -1)
    {
        return dp2[pos][isSmall];
    }

    ll lo = 0, hi = (s[pos] - '0'), re = 0;
    if(isSmall) hi = 9;



    for(int i = 0; i <= hi; i++)
    {
        re += func2(pos + 1, isSmall | (i < hi));
    }

    return dp2[pos][isSmall] = re;
}


ll func(int pos, bool isSmall, bool hasStared)
{
    if(pos == s.size()) return 0;

    if(dp[pos][isSmall][hasStared] != -1)
    {
        return dp[pos][isSmall][hasStared];
    }

    ll lo = 0, hi = (s[pos] - '0'), re = 0;

    if(isSmall) hi = 9;

    for(int i = lo; i <= hi; i++)
    {
        re += func(pos + 1, isSmall | (i < hi), hasStared | (i != 0));

        if(hasStared and (i == 0))
        {
            re += func2(pos + 1, isSmall | (i < hi));
        }
    }

    return dp[pos][isSmall][hasStared] = re;
}

void solve_case(int tc)
{
    cout<<"Case "<<tc<<": ";


    ll a, b;
    cin>>a>>b;
    a--;

    s = to_string(b);

    memset(dp, -1, sizeof dp);
    memset(dp2, -1, sizeof dp2);

    ll cnt = func(0, 0, 0) + 1;

    if(a >= 0)
    {
        s = to_string(a);

        memset(dp, -1, sizeof dp);
        memset(dp2, -1, sizeof dp2);

        cnt -= func(0, 0, 0) + 1;
    }

    cout<<cnt<<endl;

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


