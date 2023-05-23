#define mx 100005



vector<int> g[mx],cost[mx]; //Graph adjacency list
int dis[mx];

int bfs(int src, int dst){
    fill(dis,dis+mx,1e9);
    dis[src]=0;
    deque<int>Q;
    Q.push_back(src);
    while(!Q.empty()){
        int u = Q.front();
        Q.pop_front();
        if(u==dst) return dis[dst];
        for(int i=0;i<g[u].size();i++){
            int c = cost[u][i];
            int v = g[u][i];
            if(dis[v] > dis[u]+c){
                dis[v]=dis[u]+c;
                if(c==0) // Push front if cost is 0
                    Q.push_front(v);
                else // Push back if cost is 1
                    Q.push_back(v);
            }
        }
    }
}
