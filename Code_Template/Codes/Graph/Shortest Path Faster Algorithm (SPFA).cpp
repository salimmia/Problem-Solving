#define mx 100005

vector<int> g[mx],cost[mx]; //Graph adjacency list
int dis[mx], inQueue[mx], cntPushQueue[mx];
int NODE;

/*SPFA is faster than bellman ford algorithm, can detect negative cycle also, used in Min Cost Max Flow

*/
///Time Complexity: O(VE) which is similar to bellman ford but It's faster than bellman ford algorithm.
int SPFA(int src, int dst) {
    fill(dis,dis+mx,1e9);
    memset(inQueue,0,sizeof inQueue);
    memset(cntPushQueue,0,sizeof cntPushQueue);

    dis[src]=0;
    inQueue[src]=1; // inQueue[u] indicate that whether u is currently inside of Queue or not.
    cntPushQueue[src]=1;

    queue<int>Q;
    Q.push(src);
    while(!Q.empty()) {
        int u = Q.front();
        Q.pop();
        inQueue[u]=0;
        if(cntPushQueue[u]>=NODE){ //Negative cycle detected
            return -1;
        }
        for(int i=0; i<g[u].size(); i++) {
            int c = cost[u][i];
            int v = g[u][i];
            if(dis[v] > dis[u]+c) {
                dis[v]=dis[u]+c;
                if(inQueue[v]==0) {
                    Q.push(v);
                    inQueue[v]=1;
                    cntPushQueue[v]++;
                }
            }
        }
    }
    return dis[dst];
}
