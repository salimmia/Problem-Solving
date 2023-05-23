void func(int idx,int cnt,ll lcm){
 if(lcm>n)break;
 if(idx==m) {
  if(cnt==0)return;
  if(cnt & 1)re1+=n/lcm;else re1-=n/lcm;
  return;
 }
 func(idx+1,cnt+1,(lcm*ar[idx])/ __gcd(lcm,(ll)ar[idx]));
 func(idx+1,cnt,lcm);
}
void solve(){
 scanf("%lld%d",&n,&m);
 for(int i=0;i<m;i++)scanf("%d",&ar[i]);
  for(int i=1; i<(1<<m);i++) {
   ll lcm=1;int cnt=0;
   for(int j=0;j<m;j++) {
    if(i & (1<<j)) {
    cnt++;lcm=(lcm*ar[j])/__gcd(lcm,(ll)ar[j]);
     if(lcm>n)break;
    }
   }
   if(cnt&1)re+=n/lcm;
   else re-=n/lcm;
  }
 }
