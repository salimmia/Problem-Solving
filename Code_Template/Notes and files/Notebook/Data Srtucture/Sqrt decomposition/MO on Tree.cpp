/* Rest of the part include from MO's part*/
namespace MO {
 int l,r,id,lca; node(){}
 node(int l,int r,int lca,int id){
 this->l=l;this->r=r;this->lca=lca;
 this->id=id; }
 vector<int> g[N];
 int Euler[2*N],st[N],en[N],Time;
 int depth[mx],par[mx][25];
 void dfs(int u,int p,int lvl){
  st[u]=++Time; Euler[Time]=u;
  par[u][0]=p; depth[u]=lvl;
  for(int v:g[u]){
    if(v==p)continue;
    dfs(v,u,lvl+1);
  }
  en[u]=++Time; Euler[Time]=u;
 }
 /*Subtree niye kaj korle
  vector<int> g[N];
  int Euler[N],st[N],en[N],Time;
  void dfs(int u,int p){
  st[u]=++Time;Euler[Time]=u;
  for(int v:g[u]){
   f(v==p)continue;
    dfs(v,u);
   }
  en[u]=Time;
  }*/
}
using namespace MO;
/* init_LCA */
LOG=log2(n)+1; Time=0;
for(int i=1;i<n;i++){
 scanf("%d%d",&x,&y);
 g[x].push_back(y);
 g[y].push_back(x);
}
init(root);
for(int i=1;i<=q;i++){
 scanf("%d%d",&x,&y);
 if(st[x]>st[y])swap(x,y); int p=lca(x,y);
 if(x==p)query[i]=node(st[x],st[y],-1,i);
 else query[i]=node(en[x],st[y],p,i);
}
sort(query+1,query+1+q);
int left=query[1].l,right=left-1;
for(int i=1;i<=q;i++){
  node Now=query[i];
  while(left<Now.l)check(Euler[left++]);
  while(left>Now.l)check(Euler[--left]);
  while(right<Now.r)check(Euler[++right]);
  while(right>Now.r)check(Euler[right--]);
  if(Now.lca!=-1)check(Now.lca); 
  ans[Now.id]=re;
  if(Now.lca!=-1)check(Now.lca);
}
