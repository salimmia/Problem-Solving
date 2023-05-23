#define mx 100005
vector<int>prime;

bool vis[mx];

void sieve() {
    int x=sqrt((int)mx);
    for(int i=3; i<=x; i+=2) {
        if(vis[i]==0) {
            for(int j=i*i; j<mx; j+=2*i)
                vis[j]=1;
        }
    }
    prime.pb(2);
    for(int i=3; i<mx; i+=2)
        if(vis[i]==0)
            prime.pb(i);
}


int segmented_sieve(int a, int b) {
    memset(vis,0,sizeof vis);
    if(b<2) return 0;
    if(a<2) a=2;
    int xx=sqrt((double)b)+1;
    for(ll i=0; i<SZ(prime) && prime[i]<=xx; i++) {
        ll j=(a/prime[i]);
        if(a%prime[i]!=0) j++;
        j*=prime[i];
        if(j==prime[i]) j+=prime[i];
        for(; j<=b; j+=prime[i])
            vis[j-a]=1;
    }
    int cnt=0;
    for(ll i=a; i<=b; i++)
        if(vis[i-a]==0) cnt++;
    return cnt;
}
