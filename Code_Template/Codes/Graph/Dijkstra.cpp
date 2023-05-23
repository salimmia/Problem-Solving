#define mx 100005

vector<int> g[mx],cost[mx]; //Graph adjacency list
int dis[mx];

//dijkstra doesn't work when negative cycle exists.  (use bellman ford algo)
//time complexity: O(e + v log v)
int Dijkstra(int src, int dst){
    fill(dis,dis+mx,1e9);
    dis[src]=0;
    //Max Heap
    priority_queue<pair<long long,int> >Q; // first of pair is cost and second is node
    Q.push(make_pair(-0,src));
    while(!Q.empty()){
        int u = Q.top().second;
        Q.pop();
        if(u==dst) return dis[dst];
        for(int i=0;i<g[u].size();i++){
            int c = cost[u][i];
            int v = g[u][i];
            if(dis[v] > dis[u]+c){
                dis[v]=dis[u]+c;
                Q.push(make_pair(-dis[v],v)); // this negation is required for priority_queue order
            }
        }
    }
}
