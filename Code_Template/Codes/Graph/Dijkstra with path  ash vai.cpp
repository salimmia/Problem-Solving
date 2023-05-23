#include<bits/stdc++.h>
using namespace std;
#define watch(x) cerr << __LINE__ << " says: " << #x << " = " << x << "\n"



const int N = 1e6 + 100;
const int inf =  1e9;

vector<pair<int, int>> g[N];

int dis[N];
int par[N];


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin>>n>>m;

    for(int i=1; i<=m; i++)
    {
        int u, v, w;
        cin>>u>>v>>w;

        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }

    priority_queue<pair<int, int>> pq;

    for(int i=1; i<=n; i++) dis[i] = inf;

    int src = 1;
    dis[src] = 0;
    par[src] = -1;

    pq.push({-dis[src], src});

    while(!pq.empty())
    {
        auto t = pq.top();
        pq.pop();

        int u = t.second, d = -t.first;
        if(dis[u] < d) continue;

        for(int i=0; i<g[u].size(); i++)
        {
            int v = g[u][i].first, w = g[u][i].second;

            if(dis[v] > dis[u] + w)
            {
                dis[v] = dis[u] + w;
                par[v] = u;
                pq.push({-dis[v], v});
            }
        }

    }


//    for(int i=1; i<=n; i++)
//    {
//        cout<<"dis["<<i<<"] = "<<dis[i]<<endl;
//    }

    int tar;
    cin>>tar;

    cout<<"dis : "<<dis[tar]<<endl;

    vector < int > path;

    while(tar != -1)
    {
        path.push_back(tar);
        tar = par[tar];
    }

    reverse(path.begin(), path.end());


    for(auto x: path)
        cout<<x<<" ";

    cout<<endl;

}
