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

int add(int a, int b)
{
    a += b;
    if (a >= mod)a -= mod;
    return a;
}
int sub(int a, int b)
{
    a -= b;
    if (a < 0)a += mod;
    return a;
}
int mul(int a, int b)
{
    ll res = a;
    res *= b;
    if (res >= mod) res %= mod;
    return res;
}

/// bigmod iterative
int bigmodIter(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) res = mul(res, a);
        a = mul(a, a);
        b >>= 1;
    }
    return res;
}

//T.C: O(log(n))
int modInv(int x) ///// IF mod is prime using Bigmod()
{
    return bigmodIter(x, mod - 2);
}

int div24, div2;


void solve_case(int tc)
{
    int n;
    scanf("%d", &n);

    ///*** See Eulers Characteristics Formula For Regions

    int E = mul(mul(n, n - 1), mul(n - 2, n - 3));
    E = mul(E, div24);

    int V = E;

    E = mul(E, 4);

    E = add(mul(n, n - 1), E);
    E = mul(E, div2);

    V = add(V, n);

    int ans = add(sub(E, V), n + 1);

    printf("Case %d: %d\n", tc, ans);

    //cout << "Case " << tc << ": " << ans << endl;








    return;
}

int main()
{
    div24 = modInv(24);
    div2 = modInv(2);


//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);


    int test_case = 1;
    scanf("%d", &test_case);
    for (int tc = 1 ; tc <= test_case; tc++)
    {
        solve_case(tc);
    }
///  KeyPoint


///  Corner Cases




    return 0;
}


