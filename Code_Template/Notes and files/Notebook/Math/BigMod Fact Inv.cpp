ll bigmod(ll b,ll e){
 ll ans=1;
 while(e){
 if(e&1)ans=(ans*b)%mod;e>>=1;b=b*b%mod;
 }
 return ans;
}
void fact_cal(){
 fact[0]=1,inv[0]=1;
 for(int i=1;i<=mx-3;i++){
  fact[i]=(fact[i-1]*i)%mod;
 }
 inv[mx-3]=bigmod(fact[mx-3],mod-2);
 for(int i=mx-4;i>=1;i--) inv[i]=(inv[i+1]*(i+1))%mod;
}
