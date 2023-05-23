#include<bits/stdc++.h>
using namespace std;


#define mxn 5000006
vector<int>prime;

bool vis[mxn];

void sieve() {
    int x=sqrt((int)mxn);
    for(int i=3; i<=x; i+=2) {
        if(vis[i]==0) {
            for(int j=i*i; j<mxn; j+=2*i)
                vis[j]=1;
        }
    }
    prime.push_back(2);
    for(int i=3; i<mxn; i+=2)
        if(vis[i]==0)
            prime.push_back(i);
}

///Time Complexity : O(sqrt(N)/ln(sqrt(N)))
long long euler_totient(long long n) {
    int root=sqrt(n);
    long long ret=n;
    for(int i=0; i<prime.size() && prime[i]<=root; i++) {
        if(n%prime[i]==0) {
            while(n%prime[i]==0)
                n/=prime[i];
            root=sqrt(n);
            ret-=(ret/prime[i]);
        }
    }
    if(n>1) {
        ret-=(ret/n);
    }
    return ret;
}

//Euler Totient Precompute

#define mxn 100005
int phi[mxn];

void euler_totient() {
    for(int i=0; i<mxn; i++) phi[i]=i;
    for(int i=2; i<mxn; i++) {
        if(phi[i]==i) {
            for(int j=i; j<mxn; j+=i)
                phi[j]-=(phi[j]/i);
        }
    }
}

int main()
{
    sieve();
    int n;
    cin>>n;

    cout<<euler_totient(n)<<endl;
}
