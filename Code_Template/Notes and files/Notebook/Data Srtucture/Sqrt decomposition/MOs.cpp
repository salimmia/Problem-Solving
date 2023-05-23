namespace MO{
 const int N=100005;const int Q=100005;
 int BlockId[N],ans[Q]; bool vis[N];
 struct node{
  int l,r,id; node(){}
  node(int l,int r,int id){
   this->l=l;this->r=r;this->id=id;
  }
  bool operator < (const node& u){
   int a=BlockId[l],b=BlockId[u.l];
   if(a==b)return (a&1?(r > u.r):(r < u.r));
   else return a<b;
  }
 }query[Q];
 void check(int pos){
  if(vis[pos]){}
  else{}
  vis[pos]^=1;
 }
}
using namespace MO;
int sz=sqrt(n);
for(int i=1;i<=n;i++){
 BlockId[i]=i/sz;vis[i]=false;
}
for(int i=1;i<=q;i++){
 int x,y;scanf("%d%d",&x,&y);
 query[i]=node(x,y,i);
}
sort(query+1,query+q+1);
int left=query[1].l,right=left-1;
for(int i=1;i<=q;i++){
 node Now=query[i];
 while(left<Now.l)check(left++);
 while(left>Now.l)check(--left);
 while(right<Now.r)check(++right);
 while(right>Now.r)check(right--);
 ans[Now.id]=boro;
}
