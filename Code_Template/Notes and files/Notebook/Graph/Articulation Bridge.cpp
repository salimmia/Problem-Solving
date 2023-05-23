vector<int>g[mx];int Time=1;int st[mx];
vector<pair<int,int>>Bridge;int low[mx];
void dfs(int u,int p){
 st[u]=low[u]=Time++;int child=0;
 for(auto it:g[u]) {
  if(it==p)continue;
  if(st[it]==0){
   dfs(it,u);
  if(st[u]<low[it])Bridge.push_back({u,it});
  low[u]=min(low[u],low[it]);
  }
  else low[u]=min(low[u],st[it]);
 }
}
