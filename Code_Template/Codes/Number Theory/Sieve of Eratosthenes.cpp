#include<bits/stdc++.h>
using namespace std;

#define mxn 100005
#define ll long long
#define faster_io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

bool isPrime[mxn];

void sieve()
{
    //isPrime[i] = 0 means prime 
    isPrime[0] = isPrime[1] = 1;
    for(int i = 4; i < mxn; i += 2) isPrime[i] = 1;
    ll root=sqrt(mxn + 5);

    for(ll i = 3; i <= root; i += 2)
    {
        if(isPrime[i] == false)
        {
            for(ll j = i * i; j < mxn; j += i) isPrime[j] = 1;
        }
    }
}
int main()
{
    faster_io;
    sieve();
    cout<<"Enter number to check prime or not"<<endl;
    ll x;
    while(scanf("%d",&x)!=EOF)
    {
        if(isPrime[x]==false) cout<<"Prime"<<endl;
        else cout<<"Not Prime"<<endl;
    }
    return 0;
}


