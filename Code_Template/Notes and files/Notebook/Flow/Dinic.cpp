// Complexity O(V^2E)
const ll eps = 0; #define INF 1e12
struct edge {
 int a, b,yo, x, y; ll cap,flow;
};
struct Dinic {
 int s,t,d[mx], ptr[mx] ; //int Id[mx][mx];
 vector<edge>e;
 vector<int>g[mx];
 void init() {
  e.clear(); memset(d,0,sizeof(d));
  for(int i = 0; i < mx ; i++)g[i].clear();
  // for(int i=0;i<mx;i++)
  //  for(int j=0;j<mx;j++)Id[i][j]=0;
 }
 void addEdge(int a,int b,ll cap, int x = -1, int y= -1) {
  edge e1={a, b, cap, 0, 1, x, y } ;
  edge e2={b,a,0,0,0,x,y};//Id[a][b]=e.size();
  g[a].push_back((int)e.size());
  e.push_back(e1); //Id[b][a]=e.size();
  g[b].push_back((int)e.size());
  e.push_back(e2);
 }
 bool bfs() {
  queue < int > Q ; Q.push(s);
  memset(d,-1,sizeof(d)); d[s]=0 ;
  while (!Q.empty()) {
   int u=Q.front() ; Q.pop() ;
   for(int i=0; i<g[u].size(); i++) {
    int id=g[u][i], v=e[id].b;
    if(d[v]==-1&&e[id].flow<e[id].cap) {
      Q.push(v); d[v]=d[u]+1 ;
    }}
  } 
  return d[t]!=-1 ;
 }
 ll dfs(int u,ll flow) {
  if (flow<=eps)  return 0 ;
  if ( u==t )  return flow ;
  for(int& i = ptr[u] ; i<g[u].size(); i++) {
   int id = g[u][i], v =  e[id].b ;
   if ( d[v] != d[u]+1 )  continue ;
   ll pushed = dfs (v,min (flow,e[id].cap-e[id].flow)) ;
   if (pushed>eps){e[id].flow+=pushed;
    e[id^1].flow-=pushed;return pushed;
   }
  } return 0 ;
 }
 ll dinic(){ ll flow = 0 ;
  while(true) {
   if(!bfs())  break ;
   memset(ptr, 0, sizeof(ptr)) ;
   while (true){
    ll pushed = dfs(s,INF );
    if(pushed<=eps)break; flow+=pushed;
  } } 
  return flow ;
 }
};
Dinic dc;
