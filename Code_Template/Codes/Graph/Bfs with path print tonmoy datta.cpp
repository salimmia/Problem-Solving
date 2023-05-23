#define mx 100005

vector<int> g[mx],cost[mx]; //Graph adjacency list
int dis[mx], par[mx];


///time complexity: O(n+e)
int bfs(int src, int dst){
    memset(dis,-1,sizeof dis);
    dis[src]=0;
    par[src]=-1; //Required for path print
    queue<int>Q;
    Q.push(src);
    while(!Q.empty()){
        int u = Q.front();
        Q.pop();
        if(u==dst) return dis[dst];
        for(int v:g[u]){
            if(dis[v]==-1){
                dis[v]=dis[u]+1;
                par[v]=u;
                Q.push(v);
            }
        }
    }
}

//Run bfs() before executing this function
void path_print(int src, int dst){
    vector<int>path;
    int u = dst;
    while(u!=-1){
        path.push_back(u);
        u=par[u];
    }
    reverse(path.begin(),path.end());
    for(int u:path){
        cout<<u<<" ";
    }
    cout<<endl;
}
