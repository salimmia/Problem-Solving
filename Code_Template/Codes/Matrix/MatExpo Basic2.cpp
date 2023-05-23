//https://lightoj.com/problem/nth-term
// Created by Neaj_Morshad_101
#include<bits/stdc++.h>
using namespace std;

///faster io
#define faster_io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

///debug
#define watch(x) cout << __LINE__ << " says: " << #x << " = " << x << "\n"
#define watch2(x,y) cout<< __LINE__ << " says: " <<#x<<" = "<<x<<" "<<#y<<" = "<<y <<endl
#define watch3(x,y,z) cout<< __LINE__ << " says: " <<#x<<" = "<<x<<" "<<#y<<" = "<<y <<" "<<#z<<" = "<<z<<endl


///program starts...........

#define MAX 5
#define ll long long int
ll MOD = 10007;
ll MOD2 = (ll)5e18;
inline ll bigMod(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) res = (res * a) % MOD;
        a = (a * a) % MOD; b >>= 1;
    }
    return res;
}
inline ll inv(ll n) {return bigMod(n, MOD - 2);}
inline ll Mul(ll a, ll b) {return (a * b) % MOD;}
inline ll Div(ll a, ll b) {return Mul(a, inv(b));}
/* 1 base row columun index */
struct Matrix {
    int row, col;
    ll m[MAX][MAX];
    Matrix() {memset(m, 0, sizeof(m));}
    void Set(int r, int c) {row = r; col = c;}
    Matrix(int r, int c) {memset(m, 0, sizeof(m)); Set(r, c);}
    void normalize() {
        for (int i = 1; i <= row; i++) {
            for (int j = 1; j <= col; j++) {
                m[i][j] %= MOD;
                if (m[i][j] < 0) m[i][j] += MOD;
            }
        }
    }
};
Matrix Multiply(Matrix A, Matrix B) {
    Matrix ans(A.row, B.col);
    for (int i = 1; i <= A.row; i++) {
        for (int j = 1; j <= B.col; j++) {
            ans.m[i][j] = 0;
            ll sm = 0;
            for (int k = 1; k <= A.col; k++) {
                sm += (A.m[i][k] * B.m[k][j]);
                if (sm >= MOD2) sm -= MOD2;
            }
            ans.m[i][j] = sm % MOD;
        }
    }
    return ans;
}
Matrix Power(Matrix mat, ll p) {
    Matrix res(mat.row , mat.col);
    Matrix ans(mat.row , mat.col);
    int n = ans.row;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            ans.m[i][j] = 0;
            res.m[i][j] = mat.m[i][j];
        }
        ans.m[i][i] = 1;
    }
    while (p) {
        if (p & 1) ans = Multiply(ans, res);
        res = Multiply(res, res);
        p = p / 2;
    }
    return ans;
}

int tc;

int a, b, n, c;




void solve_case()
{
    cin >> n >> a >> b >> c;

    Matrix mat(4, 4);

    mat.m[1][2] = 1;
    mat.m[2][3] = 1;
    mat.m[3][1] = b;
    mat.m[3][3] = a;
    mat.m[3][4] = 1;
    mat.m[4][4] = 1;

    Matrix matn = Power(mat, n);

    Matrix fib(4, 1);

    fib.m[4][1] = c;

    Matrix res = Multiply(matn, fib);

    cout << "Case " << tc << ": ";

    cout << res.m[1][1] << endl;










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

