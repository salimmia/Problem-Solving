#include<bits/stdc++.h>
using namespace std;
#define mxn 1000099
#define faster_io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
bool vis[mxn];
vector<int>prime;

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


long long NOD(long long n) {
    int root=sqrt(n);
    long long ret=1;
    for(int i=0; i<prime.size() && prime[i]<=root; i++) {
        if(n%prime[i]==0) {
            int cnt=1;
            while(n%prime[i]==0) {
                cnt++;
                n/=prime[i];
            }
            ret*=cnt;
            root=sqrt(n);
        }
    }
    if(n>1)
        ret*=2;
    return ret;
}


int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt","w",stdout);


    faster_io;
    sieve();

    int t;
    cin>>t;
    for(int tc=1; tc<=t; tc++)
    {
        long long N;
        cin>>N;

        cout<<"Case "<<tc<<": "<<NOD(N)-1<<"\n";
    }


}

