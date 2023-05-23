//Problem: https://www.spoj.com/problems/PR003004/
//sum of digits form a to b
// a, b <= 10^15

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

ll dp[18][2][170];

ll func(int pos, int isSmall, int sum, string str)
{
    if(pos == str.size()) return sum;

    if(dp[pos][isSmall][sum] != -1)
    {
        return dp[pos][isSmall][sum];
    }

    int lo = 0, hi = str[pos] - '0';

    if(isSmall) hi = 9;

    ll total = 0;

    for(int i = lo; i <= hi; i++)
    {
        total += func(pos + 1, isSmall | (i < hi), sum + i, str);
    }

    return dp[pos][isSmall][sum] = total;

}

void solve_case(int tc)
{
    ll a, b;
    cin>>a>>b;
    if(a == -1)
    {
        return;
    }

    if(a != 0) a--;

    string s = to_string(a);
    memset(dp, -1, sizeof dp);
    ll L = func(0, 0, 0, s);
    string ss = to_string(b);
    memset(dp, -1, sizeof dp);
    ll R = func(0, 0, 0, ss);

    cout<<R - L<<endl;
    

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


