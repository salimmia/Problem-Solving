int mu[mx];

void mobius() {
    for(int i=1; i<mx; i++) mu[i]=1;
    int root=sqrt((int)mx);
    for(int i=0; i<prime.size() && prime[i]<=root; i++) {
        int x=prime[i];
        x=x*x;
        for(int j=x; j<mx; j+=x)
            mu[j]=0;
    }
    for(int i=0; i<prime.size(); i++) {
        int x=prime[i];
        for(int j=x; j<mx; j+=x)
            mu[j]*=-1;
    }
}
