///LightOJ picks theorem problem solution
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
#define watch(x) cerr << __LINE__ << " says: " << #x << " = " << x << "\n"
#define watch2(x,y) cout<< __LINE__ << " says: " <<#x<<" = "<<x<<" "<<#y<<" = "<<y <<endl
#define watch3(x,y,z) cout<< __LINE__ << " says: " <<#x<<" = "<<x<<" "<<#y<<" = "<<y <<" "<<#z<<" = "<<z<<endl


///program starts...........




void solve_case(int tc)
{
    int n;
    cin>>n;

    ll x[n+1], y[n+1];

    for(int i=0; i<n; i++)
    {
        cin>>x[i]>>y[i];
    }

    x[n] = x[0], y[n] = y[0];

    ll  Half_Area = 0;

    for(int i=0; i<n; i++)
    {
        Half_Area += (x[i]*y[i+1] - x[i+1]*y[i]);
    }

    //watch(Half_Area);

    Half_Area = abs(Half_Area);

    long double Area = Half_Area/2;

    /// We know picks theorem says, A = I + (B/2) - 1; So, I = (A + 1) - (B/2);

    ll B = 0;

    for(int i=0; i<n; i++)
    {
        int xx = x[i+1] - x[i];
        int yy = y[i+1] - y[i];

        xx = abs(xx);
        yy = abs(yy);

        B += __gcd(xx, yy) + 1;
    }

    B -= n;

    ll I = (Area+1) - (B/2);

    //watch(Area);

    cout<<"Case "<<tc<<": "<<I<<endl;



    return;
}

int main()
{
    faster_io;

//    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);


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


