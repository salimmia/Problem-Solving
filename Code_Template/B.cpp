// Created by Neaj_Morshad_101
#include<bits/stdc++.h>
using namespace std;


///typedef
typedef long long ll;
typedef long double ld;
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

int tc;




void solve_case()
{
    ll n, k, b, s;
    cin >> n >> k >> b >> s;

    ll bmin = 0;

    ll baki = s - (n * (k - 1));

    if (baki > 0)
    {
        bmin = max(bmin, (baki + k - 1) / k);
    }

    ll bmax = s / k;

    if (b >= bmin and b <= bmax)
    {
        ll a0 = b * k;
        s -= b * k;

        if (s > 0) a0 += min(s, k - 1);

        s -= k - 1;

        if (s <= 0) s = 0;

        cout << a0;

        for (int i = 1; i < n; i++)
        {
            cout << " " << min(s, k - 1);
            s -= (k - 1);
            if (s < 0) s = 0;
        }
        cout << endl;
    }
    else
    {
        cout << -1 << endl;
    }


    return;
}

int main()
{
    faster_io;

//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);


    int total_test = 1;
    cin >> total_test;
    for (int test_case = 1; test_case <= total_test; test_case++)
    {
        tc = test_case;
        solve_case();
    }
///  KeyPoint


///  Corner Cases




    return 0;
}

