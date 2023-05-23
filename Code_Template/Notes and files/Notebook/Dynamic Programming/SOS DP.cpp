memset(dp,-1,sizeof(dp));
for(int i=1;i<=n;i++)dp[ar[i]]=ar[i];
for(int i=0;i<22;i++){
 for(int mask=0;mask<(1<<22);mask++){
  if(chk(mask,i))
   dp[mask]=max(dp[mask],dp[mask^(1<<i)]);
 }
}
int boro=(1<<22)-1;
//iterate all the submask of a mask
for(int mask=1;mask<(1<<sz);mask++) {
 int tmask=mask&(mask-1);
 while(tmask) {
  cout<<tmask<<endl;
//dp[mask]=min(dp[mask],dp[tmask]+dp[mask^tmask]);
  tmask=(tmask-1)&mask;
 }
}
