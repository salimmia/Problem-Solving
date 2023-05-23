// for weighted lightoj 1150 solution,O(VE)
struct BPM{
 bool Done[mx];vector<int>g[mx];int macth[mx];
 void addEdge(int u,int v) g[u].push_back(v);
 void init(){for(int i=0;i<mx;i++)g[i].clear();}
 bool Tem_Matching(int u){
  for(int i=0;i<(int)g[u].size();i++){
   int v=g[u][i];if(Done[v])continue;Done[v]=1;
    if(macth[v]==-1 ||Tem_Matching(macth[v]))
      {macth[v] = u; return true;}
  }return false;
 }
 int Max_Matching(int num){
//Be Carefull when passing the num.
  memset(macth,-1,sizeof(macth));int re=0;
   for(int i=1;i<=num;i++){
    memset(Done,false,sizeof(Done));
    if(Tem_Matching(i)) re++;
   }return re;
 }
};
/*Maximum Independent Set in Bipartite Graph
-> Largest set of nodes who do not have any edge between themselves 
-> Solution: V- Max Matching 
Minimum Vertex Cover in Bipartite Graph 
-> Smallest set of nodes where at least one end-point of each edge is present 
-> Solution: Max Matching 
Minimum Edge Cover in General Graph 
-> Smallest set of edges where each vertex is end-point of at least one edge
-> V- Matching(if edge cover exists)
Minimum Path Cover(Vertex Disjoint) in DAG
-> Minimum number of vertex disjoint paths that visit all nodes 
Minimum Path Cover(Vertex Not Disjoint) in General Graph 
-> Minimum number paths that visit all nodes*/
