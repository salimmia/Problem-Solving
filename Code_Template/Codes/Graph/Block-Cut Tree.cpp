/**
    1. Take input the graph in g[].
    2. Call find_BCC() to determine biconnected components which are stored in BCC.
    3. Call build_BCTree() to get block cut tree in tree[].
    4. Always remember to clear BCC and AP before buld tree.
*/

#define mx 10004

vector<int>g[mx];
int disc[mx],low[mx],dfs_time;
bool vis[mx],isAP[mx];
stack<int>st;

vector<vector<int> > BCC; ///Store Biconnected components.
vector<int> AP; ///Store articulation points.

///Return number of node in current component
int find_BCC(int u, int p)
{
    vis[u]=1;
    disc[u]=low[u]=++dfs_time;
    st.push(u);
    int child=1;
    for(int v:g[u])
    {
        if(v==p) continue;
        if(vis[v]==0)
        {
            child+=find_BCC(v,u);
            low[u]=min(low[u],low[v]);
            if(low[v]>=disc[u])
            {
                isAP[u]=(disc[u]>1 || disc[v]>2);
                if(isAP[u]) AP.pb(u);
                BCC.pb({});
//                cout<<"--------------------"<<endl;
                while(true)
                {
                    int cur=st.top();
//                    cout<<cur<<endl;
                    BCC.back().pb(cur);
                    st.pop();
                    if(cur==v)break;
                }
                BCC.back().pb(u);
//                cout<<u<<endl;
            }
        }
        else
        {
            low[u]=min(low[u],disc[v]);
        }
    }
    if(u==p)
    {
        if(SZ(BCC)==0)
        {
            BCC.pb({});
            BCC.back().pb(u);
        }
    }
    return child;
}

///Block cut tree can hold 2*n node where all vertex are cut vertex
vector<int>tree[2*mx];
int tree_node_cnt;
int node_mark[mx];
int elem_cnt[2*mx];

void build_BCTree()
{

    ///Clearing the tree
    for(int i=0; i<=tree_node_cnt+2; i++)
    {
        tree[i].clear();
        elem_cnt[i]=0;
    }
    tree_node_cnt=0;

    for(int u:AP)
    {
        node_mark[u]=++tree_node_cnt; ///Creating node for every AP.
        elem_cnt[tree_node_cnt]=1;
    }

    for(int i=0; i<SZ(BCC); i++)
    {
        tree_node_cnt++; /// Creating block node.
        elem_cnt[tree_node_cnt]=SZ(BCC[i]);
        for(int u:BCC[i])
        {
            if(!isAP[u])
                node_mark[u]=tree_node_cnt;
            else        ///Adding edge between a block and AP node.
            {
                tree[tree_node_cnt].pb(node_mark[u]);
                tree[node_mark[u]].pb(tree_node_cnt);
//                elem_cnt[tree_node_cnt]--;
            }
        }
    }
}

void allclear(int n)
{
    for(int i=0; i<=n; i++)
    {
        g[i].clear();
        vis[i]=0;
        isAP[i]=0;
    }
    while(!st.empty()) st.pop();
    dfs_time=0;
}
