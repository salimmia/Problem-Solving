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
    ll h, w;
    cin>>h>>w;

    if(h % 3 == 0 or w % 3 == 0)
    {
        cout<<0<<endl;
        return;
    }


    ll left_cut = w / 3;

    ll mxmn = 1e18;




    for(int lc = left_cut; lc <= left_cut + 1; lc++)
    {
        ll mx = -1e18;
        ll mn = -mx;
        mx = max(mx, lc * h);
        mn = min(mn, lc * h);

        //watch(lc);



        int baki = (w - lc);

        if(baki % 2 == 0 or h % 2 == 0)
        {
            mx = max(mx, baki * h / 2);
            mn = min(mn, baki * h / 2);
        }

        else 
        {
            if(baki <= h)
            {
                mx = max(mx, baki * (h + 1) / 2);
                mn = min(mn, (baki) * (h - 1) / 2);
                
            }
            else
            {
                mx = max(mx, (baki + 1) * h / 2);
                mn = min(mn, (baki - 1) * h / 2);
            }
        }

        mxmn = min(mxmn, mx - mn);
    }


    //cout<<mxmn<<endl;

    swap(h, w);


    left_cut = w / 3;

    


    for(int lc = left_cut; lc <= left_cut + 1; lc++)
    {
        ll mx = -1e18;
        ll mn = -mx;
        mx = max(mx, lc * h);
        mn = min(mn, lc * h);



        int baki = (w - lc);

        if(baki % 2 == 0 or h % 2 == 0)
        {
            mx = max(mx, baki * h / 2);
            mn = min(mn, baki * h / 2);
        }

        else 
        {
            if(baki <= h)
            {
                mx = max(mx, baki * (h + 1) / 2);
                mn = min(mn, (baki) * (h - 1) / 2);
                
            }
            else
            {
                mx = max(mx, (baki + 1) * h / 2);
                mn = min(mn, (baki - 1) * h / 2);
            }
        }
        mxmn = min(mxmn, mx - mn);
    }






    cout<<mxmn<<endl;

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


