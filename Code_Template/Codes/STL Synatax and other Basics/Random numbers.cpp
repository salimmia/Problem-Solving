#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;


mt19937 rng(chrono::steady_clock::now().time_since_epoch().count()); /// MUST ADD

ll my_rand(ll l, ll r) {
    return uniform_int_distribution<ll>(l, r) (rng);
}

//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
int main()
{
    int line = 5;
    int numbers=8;
    bool pos=false;
    ll mxvalue = 100;
    ll minvalue = -100;
    while(line--)
    {
        for(int i=0; i<numbers; i++)
        {
            int x = my_rand(-10, 10);

            cout<<x<<" ";
        }
        cout<<endl;
    }

//1 0 9 9 5
//3 4 5 7 2
//9 8 4 1 6
//0 2 4 4 3
//3 0 4 0 2
//
//1 0 9 9 5 3
//4 5 7 2 9 8
//4 1 6 0 2 4
//4 3 3 0 4 0
//2 5 6 0 4 6


//1 0 9 9 5 3 4 5 7 2
//9 8 4 1 6 0 2 4 4 3
//3 0 4 0 2 5 6 0 4 6
//7 0 0 6 7 0 9 8 0 3
//2 0 0 6 5 7 7 4 2 1

// between 0 to 4
//3 0 2 2 1 3 3 1 2 0
//1 2 1 0 2 1 2 0 0 3
//0 1 0 2 3 2 1 0 2 3
//3 3 3 2 2 3 0 0 3 1
//2 1 2 2 1 0 1 2 3 2


    return 0;
}

