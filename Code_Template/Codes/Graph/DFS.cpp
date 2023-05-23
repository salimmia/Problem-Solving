#define mx 100005

vector<int> g[mx]; //Graph adjacency list
pair<int,int> dfs_time[mx];
bool visited[mx];
int Time = 0;

void dfs(int u){
    visited[u]=1;
    dfs_time[u].first = Time++;
    for(int v:g[u]){
        if(visited[v]) continue;
        dfs(v);
    }
    dfs_time[u].second = Time++;
}


void dfs(int u, int pr)
{
    //do something 

    for(auto v : g[u])
    {
        if(v != pr)
        {
            dfs(v, u);
        }
    }

    // do something..
}
