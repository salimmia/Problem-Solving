// Created by Neaj_Morshad_101
#include<bits/stdc++.h>
using namespace std;


///typedef
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

///define constant
const ll mxn = 1000006;
const int mod = 1000000007;//1e9+7;

///faster io
#define faster_io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

///debug
#define watch(x) cout << __LINE__ << " says: " << #x << " = " << x << "\n"
#define watch2(x,y) cout<< __LINE__ << " says: " <<#x<<" = "<<x<<" "<<#y<<" = "<<y <<endl
#define watch3(x,y,z) cout<< __LINE__ << " says: " <<#x<<" = "<<x<<" "<<#y<<" = "<<y <<" "<<#z<<" = "<<z<<endl


///program starts...........

int tc;

//vector<int> v[1000006];



bitset<mxn>is_composite;
vector<int>prime;
int phi[mxn];
void linearSieve(int n) {
    phi[1] = 1;
    for (int i = 2; i <= n; i++) {
        if (!is_composite[i]) {
            prime.push_back(i);
            phi[i] = i - 1;          ///i is prime
        }
        for (int j = 0; j < prime.size() && i * prime[j] <= n; j++)  {
            is_composite[i * prime[j]] = true;
            if (i % prime[j] == 0) {
                phi[i * prime[j]] = phi[i] * prime[j]; ///prime[j] divides i
                break;
            }
            else {
                phi[i * prime[j]] = phi[i] * phi[prime[j]]; ///prime[j] do not divide i
            }
        }
    }
}

ll val[mxn];

//vector<int> v[mxn];

void allDivisorCalculate()
{
    //int cnt = 0;
    for (ll i = 1; i <= 1000000; i++)
    {
        for (int x = i; x <= 1000000; x += i)
        {
            val[x] += (i * phi[i]);
            //v[x].push_back(i);
            //cnt++;
        }
    }

    //watch(cnt);
}


void solve_case()
{
    int n;
    scanf("%d", &n);

    ll sum = 0;



    sum = (n * val[n] + n) / 2;


    printf("%lld\n", sum);

    //cout << sum << endl;



    return;
}

int main()
{
    //faster_io;
    linearSieve(mxn - 1);
    allDivisorCalculate();


    // for (int i = 1; i <= 10; i++)
    // {
    //     watch2(i, phi[i]);
    // }


//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);


    int total_test = 1;
    //cin >> total_test;
    scanf("%d", &total_test);
    for (int test_case = 1; test_case <= total_test; test_case++)
    {
        tc = test_case;
        solve_case();
    }
///  KeyPoint


///  Corner Cases




    return 0;
}

