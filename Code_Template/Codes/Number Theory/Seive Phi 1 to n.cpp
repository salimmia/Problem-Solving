#include<bits/stdc++.h>
using namespace std;

#define N 1000009
int phi[5*N];
bool mark[5*N];

void seivePhi()
{
    for(int i=1;i<=N;i++) phi[i]=i;
    phi[1]=1;
    mark[1]=1;
    for(int i=2;i<=N;i++)
    {
        if(!mark[i])//if i is prime
        {
            for(int j=i;j<=N;j+=i)
            {
                mark[j]=1;
                phi[j]=phi[j]/i*(i-1);//n = n - n/i;
            }
        }
    }
}
int main()
{
    seivePhi();
    for(int i=1;i<=10;i++)
    {
        printf("phi[%d] = %d\n",i,phi[i]);
    }

    return 0;
}
