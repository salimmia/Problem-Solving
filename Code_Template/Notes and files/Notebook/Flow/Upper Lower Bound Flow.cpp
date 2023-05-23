Dinic dc; int x,y; // Source and Sink
struct tem{
    int u,v,a,b;
};
vector<tem>ed;
ll func(ll val){
 dc.init(); dc.s=n+1; dc.t=n+2;
 /*for upperbound(0,val),SSS=SuperSuperSource
 dc.addEdge(y,n+3,val);sink to SSS
 dc.addEdge(n+1,x,0);sink to source
 dc.addEdge(n+3,n+2,0);SSS to super sink
 dc.addEdge(n+3,x,val);SSS to source */
 // for lowerbound(val,inf)
 dc.addEdge(y,n+3,INF); //sink to SSS
 dc.addEdge(n+1,x,val); //sink to source
 dc.addEdge(n+3,n+2,val); //SSS to super sink
 dc.addEdge(n+3,x,INF);  //SSS to source 
 for(auto it:ed){
  dc.addEdge(n+1,it.v,it.a);
  dc.addEdge(it.u,n+2,it.a);
  dc.addEdge(it.u,it.v,it.b-it.a);
 }
 return dc.dinic();
}
void solve(){
 scanf("%d%d",&n,&m); scanf("%d%d",&x,&y);
 dc.addEdge(y,x,INF); dc.s=n+1; dc.t=n+2;
 ll val=0; ll en=0;
 for(int i=1;i<=m;i++){
  int u,v,a,b;
  scanf("%d%d%d%d",&u,&v,&a,&b);
  ed.push_back({u,v,a,b});
  val+=a; en+=b; dc.addEdge(n+1,v,a);
  dc.addEdge(u,n+2,a);dc.addEdge(u,v,b-a);
 }
 if(dc.dinic()<val){
  printf("0\n");
  return;
 }
 ll be=re=val;
 while(be<=en){
  ll mid=(be+en)/2; ll have=func(mid);
  if(have>=mid+val){re=mid;be=mid+1;}
  else en=mid-1;
 }
 printf("%lld\n",re);
}
