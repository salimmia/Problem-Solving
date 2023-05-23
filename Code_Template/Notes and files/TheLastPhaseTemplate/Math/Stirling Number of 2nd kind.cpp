ll dp[mx][mx];
ll func(int nn,int kk){
 if(kk==1)return 1;
 if(nn==kk)return 1;
 if(kk==0)return 0;
 ll &val=dp[nn][kk];
 if(val!=-1)return val;
 val=func(nn-1,kk-1) + 1LL*kk*func(nn-1,kk);
 return val;
}