struct DSU{
 vector<int>sz,rnk,par; int c;
 DSU(int n):par(n+1),sz(n+1,1),rnk(n+1,0){
  for(int i=1;i<=n;i++)par[i]=i;c=n;
 }
 int pfind(int u){
 return (par[u]==u?u:(par[u]=pfind(par[u])));
 }
 int get_sz(int u){ return sz[pfind(u)];}
 int Components(){ return c;}
 int Union(int u,int v){
 if((u=pfind(u))==(v=pfind(v)))return -1;
 else --c;
 if(rnk[u]>rnk[v])swap(u,v);par[u]=v;
  sz[v]+=sz[u];if(rnk[u]==rnk[v])rnk[v]++;
  return v;
 }
};