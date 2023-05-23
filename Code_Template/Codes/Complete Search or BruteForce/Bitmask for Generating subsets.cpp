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




void solve_case(int tc)
{
    int n;
    cin>>n;

    int arr[n];

    for(int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }

    bool ok = false;

    for(int num = 0; num <(1<<n); num++)
    {
        int sum = 0;

        for(int i = 0; i < n; i++)
        {
            if(num & (1<<i))
            {
                sum += arr[i];
            }
            else sum -= arr[i];
        }

        sum = abs(sum);

        if(sum % 360 == 0)
        {
            cout<<"YES"<<endl;
            ok = true;
            break;
        }
        
    }

    if(!ok)
    {
     cout<<"NO"<<endl;
    }

    return;
}

int main()
{
    faster_io;

//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);


    int test_case=1;
    //cin>>test_case;
    for(int tc=1 ; tc<=test_case; tc++)
    {
        solve_case(tc);
    }
///  KeyPoint


///  Corner Cases




    return 0;
}