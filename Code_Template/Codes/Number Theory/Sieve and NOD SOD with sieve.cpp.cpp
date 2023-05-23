
#include<bits/stdc++.h>
using namespace std;




#define mxn 10000009  //1e7
vector<int>prime;

bool vis[mxn];

///Time Complexity : O(N * ln(ln(N)))
///Number of prime upto N is approximately ~ N / ln(N) 

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


ll sod[mxn+1];

///Time Complexity : O(N *(ln(N)))
void SOD_sieve()
{
    for(int i=1; i<=mxn; i++)
    {
        for(int j=i; j<=mxn; j+=i)
        {
            sod[j]+=i;
        }
    }
}


int main()
{
    sieve();

    int limit = 20;
    for(int i=0; ; i++)
    {
        cout<<prime[i]<<" ";

        if(i>limit) break;
    }
    cout<<endl;
}
