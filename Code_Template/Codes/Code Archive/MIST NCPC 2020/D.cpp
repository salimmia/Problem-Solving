#include<bits/stdc++.h>
using namespace std;


///typedef
typedef long long ll;
typedef pair<int, int> pii;

///define constant
const ll mxn = 100005;
const int mod = 1000000007;//1e9+7;

///faster io
#define faster_io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

///debug
#define watch(x) cout << __LINE__ << " says: " << #x << " = " << x << "\n"
#define watch2(x,y) cout<< __LINE__ << " says: " <<#x<<" = "<<x<<" "<<#y<<" = "<<y <<endl
#define watch3(x,y,z) cout<< __LINE__ << " says: " <<#x<<" = "<<x<<" "<<#y<<" = "<<y <<" "<<#z<<" = "<<z<<endl


///program starts...........

int n;
vector<int> g[mxn];
int st[mxn], et[mxn];
int TIME = 0;

void dfs(int u, int p)
{
    st[u] = ++TIME;

    for(int v : g[u])
    {
        if(v == p)
            continue;

        dfs(v, u);
    }

    et[u] = ++TIME;
}


void clr()
{
    TIME = 0;

    for(int i = 1; i <= n; i++)
    {
        g[i].clear();
    }

    
}


void solve_case(int tc)
{
    printf("Case %d:\n", tc);
    //cout<<"Case "<<tc<<":"<<endl;
    //cin>>n;
    scanf("%d", &n);
    



    for(int i = 0; i < n - 1; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);

        //cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    for(int i = 1; i <= n; i++)
    {
        sort(g[i].begin(), g[i].end());
    }

    dfs(1, -1);

    bool finished[TIME + 1] = {false};

    set<int> Set;

    for(int i = 1; i <= n; i++)
    {
        Set.insert(et[i]);
    }


    int q;
     scanf("%d", &q);

    while(q--)
    {
        int type; 

        scanf("%d", &type);

        int u, x;
         scanf("%d", &u);

        if(type == 1)
        {
             scanf("%d", &x);

            if(finished[et[u]])
            {
                continue;
            }
            auto it = Set.upper_bound(st[u]);
            while(x--)
            {
                int end = (*it);

                it=Set.erase(it);

                finished[end] = true;

                if(end == et[u])
                {
                    break;
                }
            }
            
        }
        else
        {
            if(!finished[et[u]])
            {
                printf("0\n");
            }
            else
            {
                printf("1\n");
            }
        }
    }


    clr();


    return;
}

int main()
{
    //faster_io;

//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);


    int test_case=1;
    scanf("%d", &test_case);
    for(int tc=1 ; tc<=test_case; tc++)
    {
        solve_case(tc);
    }
///  KeyPoint


///  Corner Cases




    return 0;
}


