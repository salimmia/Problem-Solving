//LCA using sparse table
//solved probelm
//https://www.spoj.com/problems/LCA/
#include<bits/stdc++.h>
using namespace std;

///debug
#define watch(x) cout << __LINE__ << " says: " << #x << " = " << x << "\n"
#define watch2(x,y) cout<< __LINE__ << " says: " <<#x<<" = "<<x<<" "<<#y<<" = "<<y <<endl
#define watch3(x,y,z) cout<< __LINE__ << " says: " <<#x<<" = "<<x<<" "<<#y<<" = "<<y <<" "<<#z<<" = "<<z<<endl

#define mx 1002

int n;
int level[mx]; //level
int P[mx][22]; //sparse table
int par[mx]; //parent
vector <int> g[mx]; //tree

void dfs(int u, int pr, int depth)
{
    par[u] = pr;
    level[u] = depth;

    for(int i=0; i<(int)g[u].size(); i++)
    {
        int v=g[u][i];
        if(v==pr)
        {
            continue;
        } 
        dfs(v, u, depth+1);
    }
}

int lca_query(int p, int q)
{
    int log, i;

    if (level[p] < level[q])
    {
        swap(p, q);
    }

    log=1;

    while(1)
    {
        int next=log+1;
        if((1<<next)>level[p])
            break;
        log++;

    }

    for (i = log; i >= 0; i--)
    {
        if (level[p] - (1 << i) >= level[q])
        {
            p = P[p][i];
        }
    }

    if (p == q)
        return p;

    for (i = log; i >= 0; i--)
        if (P[p][i] != -1 && P[p][i] != P[q][i])
            p = P[p][i], q = P[q][i];

    return par[p];
}

void LCA_Preprocessing()
{
    memset (P,-1,sizeof(P));

    for (int i = 0; i < n; i++)
        P[i][0] = par[i];

    for (int j = 1; (1 << j) < n; j++)
    {
        for (int i = 0; i < n; i++)
        {
            if (P[i][j - 1] != -1)
            {
                P[i][j] = P[P[i][j - 1]][j - 1];
            }
        }
    }
}


void solve_case(int tc)
{

    cin>>n;

    //*** 0 indexed
    for(int i = 0; i < n; i++)
    {
        int m; //number of child nodes of nth node 
        cin>>m;

        for(int e = 0; e < m; e++)
        {
            int c;
            cin>>c;
            c--;
            //*** 0 indexed
            g[i].push_back(c);
            g[c].push_back(i);
        }
    }

    //*** 0 indexed
    dfs(0, 0, 0);

    LCA_Preprocessing();

    int q; 
    cin>>q;

    cout<<"Case "<<tc<<":"<<endl;

    while(q--)
    {
        int u, v;
        cin>>u>>v;
        u--; v--;

        //watch2(u, v);
        cout<<lca_query(u, v) + 1<<endl;
    }


    for(int i = 0; i < n; i++)
    {
        g[i].clear();
    }


    return;
}

int main()
{
    int test_case=1;
    cin>>test_case;
    for(int tc=1 ; tc<=test_case; tc++)
    {
        solve_case(tc);
    }
    return 0;
}

