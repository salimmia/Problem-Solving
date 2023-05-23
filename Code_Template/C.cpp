// Fast FTT /// For Mod use NTT...
// Tested : https://atcoder.jp/contests/abc149/tasks/abc149_e
// Choose m pairs (a[i], a[j]) such that
// sum of all (a[i], a[j]) is maximum possible
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

namespace FFT
{
#define ll long long
#define VI vector<ll>
#define op operator
#define ld long double
#define CN complex<double>
#define eps 1e-8
const double PI = 2 * acos( 0.0 );
struct base {
    typedef double T; T re, im;
    base() : re(0), im(0) {}
    base(T re) : re(re), im(0) {}
    base(T re, T im) : re(re), im(im) {}
    base op + (const base& o) const { return base(re + o.re, im + o.im); }
    base op - (const base& o) const { return base(re - o.re, im - o.im); }
    base op * (const base& o) const { return base(re * o.re - im * o.im, re * o.im + im * o.re); }
    base op * (ld k) const { return base(re * k, im * k) ;}
    base conj() const { return base(re, -im); }
};
const int N = 21; /// check before coding
// N denotes log2(mx degree)  or log2(mx element)
const int MAXN = (1 << N);
base w[MAXN];
base f1[MAXN];
ll rev[MAXN];
void build_rev(int k) {
    static int rk = -1;
    if ( k == rk )return ; rk = k;
    for (int i = 1; i <= (1 << k); i++) {
        int j = rev[i - 1], t = k - 1;
        while ( t >= 0 && ((j >> t) & 1) ) { j ^= 1 << t; --t; }
        if ( t >= 0 ) { j ^= 1 << t; --t; }
        rev[i] = j;
    }
}
void fft(base *a, ll k) {
    build_rev(k);
    ll n = 1 << k;
    for (ll i = 0; i < n; i++) if ( rev[i] > i ) swap(a[i], a[rev[i]]);
    for (ll l = 2, llo = 1; l <= n; l += l, llo += llo) {
        if ( w[llo].re == 0 && w[llo].im == 0 ) {
            ld angle = M_PI / llo;
            base ww( cosl(angle), sinl(angle) );
            if ( llo > 1 ) for (ll j = 0; j < llo; ++j) {
                    if ( j & 1 ) w[llo + j] = w[(llo + j) / 2] * ww;
                    else w[llo + j] = w[(llo + j) / 2];
                }
            else w[llo] = base(1, 0);
        }
        for (ll i = 0; i < n; i += l) {
            for (ll j = 0; j < llo; j++) {
                base v = a[i + j], u = a[i + j + llo] * w[llo + j];
                a[i + j] = v + u;
                a[i + j + llo] = v - u;
            }
        }
    }
}

VI Multiply(VI& a, VI& b) {
    ll k = 1;
    while ( (1 << k) < (a.size() + b.size()) ) ++k;
    ll n = (1 << k);
    for (ll i = 0; i < n; i++) f1[i] = base(0, 0);
    for (ll i = 0; i < a.size(); i++) f1[i] = f1[i] + base(a[i], 0);
    for (ll i = 0; i < b.size(); i++) f1[i] = f1[i] + base(0, b[i]);
    fft(f1, k);
    for (ll i = 0; i < 1 + n / 2; i++) {
        base p = f1[i] + f1[(n - i) % n].conj();
        base _q = f1[(n - i) % n] - f1[i].conj();
        base q(_q.im, _q.re);
        f1[i] = (p * q) * 0.25;
        if ( i > 0 ) f1[(n - i)] = f1[i].conj();
    }
    for (ll i = 0; i < n; i++) f1[i] = f1[i].conj();
    fft(f1, k);
    VI res(a.size() + b.size());
    for (ll i = 0; i < res.size(); i++) {
        if (fabs(f1[i].re) < eps) res[i] = 0;
        else res[i] = f1[i].re / fabs(f1[i].re) * (ll) (abs(f1[i].re / n) + 0.5);
    }
    return res;
}
VI bigMod(VI& n, ll p) {
    VI res = n;
    VI Ans; Ans.push_back(1);
    while (p) {
        if (p % 2 == 1) Ans = Multiply(Ans, res);
        res = Multiply(res, res);
        p = p / 2;
    }
    return Ans;
}
}
using namespace FFT;



void solve_case()
{
    // given an array a, of length n
    // Choose m pairs (a[i], a[j]) such that
    // sum of all (a[i], a[j]) is maximum possible
    ll n, m;
    cin >> n >> m;

    ll arr[n];

    //Polynomial : a0*x^0 + a1*x^1 + a2*x^2 + .....
    VI pol(100001, 0); /// Indices are degree / powers of x
    /// values are co-efficient of x^(degree)

    /// pol[0] = a0; pol[1] = a1 ...

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        pol[arr[i]]++;
        /// arr[i] is degree of the polynomial
        //  and co-efficient of the polynomial is frequency
        //  of the arr[i] / degree
    }

    VI mul = Multiply(pol, pol);
    /// mul = pol * pol
    /// degree or powers of mul denotes arr[i] + arr[j]
    //  and co-efficient of that degree denotes
    //  how many pairs gives the sum (arr[i] + arr[j])


    ll res = 0;

    // now choose m best pairs for maximum result

    for (int i = mul.size() - 1; i >= 0; i--)
    {
        if (m >= mul[i])
        {
            m -= mul[i];
            res += i * mul[i];
        }
        else
        {
            res += m * i;
            break;
        }


    }

    cout << res << endl;






    return;
}

int main()
{
    faster_io;

//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);


    int total_test = 1;
    //cin >> total_test;
    for (int test_case = 1; test_case <= total_test; test_case++)
    {
        tc = test_case;
        solve_case();
    }
///  KeyPoint


///  Corner Cases




    return 0;
}

