vector<int>g[mx]; int Time=1;
int articular_point[mx],st[mx],low[mx];
int dfs(int u,int p){
 st[u]=low[u]=Time++; int child=0;
 for(auto it:g[u]) {
  if(it==p)continue;
  if(st[it]==0) {
   child++; dfs(it,u);
   if(st[u]<=low[it])articular_point[u]=1;
   low[u]=min(low[u],low[it]);
  }
  else low[u]=min(low[u],st[it]);
 }
 return child;
}
for(int i=1;i<=n;i++) {
 if(st[i])continue;
 articular_point[i]=(dfs(i,-1)>1);
}
