vector<pair<int,int>>g[mx];
int par[mx],sub_sz[mx],T,Rin[mx];;
int Head[mx],st[mx],sesh[mx];
/*In SegTree init Tree[bode]=ar[Rin[be]]*/
using namespace Segment_Tree;
void sz_dfs(int u,int p){
 sub_sz[u]=1; par[u]=p;
 for(auto &v: g[u]){
  if(v.first==p)continue;
  sz_dfs(v.first,u);
  sub_sz[u]+=sub_sz[v.first];
  if(sub_sz[v]>sub_sz[g[u][0].first]) swap(v,g[u][0]);
 }
}
void hld_dfs(int u,int p,int cost){
 st[u]=++T;Rin[st[u]]=u;
 ar[st[u]]=cost;/*not for node value*/
 for(auto v:g[u]){
  if(v.first==p)continue;
  Head[v.first] = (v.first==g[u][0].first ? Head[u]:v.first);
  hld_dfs(v,u,v.second);
 }
 sesh[u]=T;
}
void hld_build(int root){
 T=0;Head[root]=root;
 sz_dfs(root,root); hld_dfs(root,root,0);
}
bool Is_it_parent(int p,int u){
 return st[p]<=st[u] && sesh[u]<=sesh[p];
}
int path_query(int u,int v){
 int re=-inf;
 while(1){
  if(Is_it_parent(Head[u],v))break;
  re=max(re,query(1,1,n,st[Head[u]],st[u]));
  /*for sum just add in all query*/
  u=par[Head[u]];
 }
 swap(u,v);
 while(1){
  if(Is_it_parent(Head[u],v))break;
  re=max(re,query(1,1,n,st[Head[u]],st[u])); 
  u=par[Head[u]];
 }
 if(st[u]>st[v])swap(u,v);
 re=max(re,query(1,1,n,st[u]+1,st[v]));
 /* node hole st[u] theke start*/
 return re;
}
void path_update(int u,int v,int val){
 while(1){
  if(Is_it_parent(Head[u],v))break;
  Rupdate(1,1,n,st[Head[u]],st[u],val);
  u=par[Head[u]];
 }
 swap(u,v);
 while(1){
  if(Is_it_parent(Head[u],v))break;
  Rupdate(1,1,n,st[Head[u]],st[u],val);
  u=par[Head[u]];
 }
 if(st[u]>st[v])swap(u,v);
 Rupdate(1,1,n,st[u]+1,st[v],val);
 /*node hole st[u] theke start*/
}
void update_subtree(int u,int val){
 Rupdate(1,1,n,st[u]+1,sesh[u],val);
 /*node hole st[u] theke start*/
}
