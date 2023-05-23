bitset<mx>is_composite;vector<int>prime;
int phi[mx],mobius[mx];
void seive(int n){
phi[1]=mobius[1]=1;
for(int i=2; i<=n; i++){
 mobius[i]=1;
 if(!is_composite[i]){
  prime.push_back(i); phi[i]=i-1;
 }
 for(int j=0;j<prime.size()&& i*prime[j]<=n;j++){
  is_composite[i*prime[j]]=true;
  if(i%prime[j]==0){
   phi[i*prime[j]]=phi[i]*prime[j];
   break;
  }
  else{
   phi[i*prime[j]]=phi[i]*phi[prime[j]];
  }
 }
}
 for(int val:prime){
  int temp=val*val;if(temp>n)break;
  for(int j=temp; j<=n; j+=temp)mobius[j]=0;
 }
 for(int val:prime){
  for(int j=val; j<=n; j+=val)mobius[j]*=-1;
 }
}
