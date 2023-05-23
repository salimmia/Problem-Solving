#include<bits/stdc++.h>
using namespace std;


///typedef
typedef long long ll;
typedef pair<int, int> pii;

///define constant
const ll mxn = 1000006;
const int mod = 1000000007;//1e9+7;

///faster io
#define faster_io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

///debug
#define watch(x) cout << __LINE__ << " says: " << #x << " = " << x << "\n"
#define watch2(x,y) cout<< __LINE__ << " says: " <<#x<<" = "<<x<<" "<<#y<<" = "<<y <<endl
#define watch3(x,y,z) cout<< __LINE__ << " says: " <<#x<<" = "<<x<<" "<<#y<<" = "<<y <<" "<<#z<<" = "<<z<<endl


///program starts...........


int parent[mxn];
int Size[mxn];

void makeset(int u)
{
    parent[u] = u;
    Size[u] = 1;
}


int findRep(int u) // TC generally log(n) But if we call it n times we will reach nearly constant time queries.
{
    if(parent[u]==u)
    {
        return u;
    }

    parent[u] = findRep(parent[u]);
    return parent[u];
}

void Union(int a, int b, int u, int v)
{
    // int u,v;
    // //finding representative
    // u = findRep(a);
    // v = findRep(b);

    // if(u!=v)
    {
        if(Size[u] < Size[v])
            swap(u,v);

        parent[v] = u;
        Size[u] += Size[v];
    }
}


void solve_case(int tc)
{
    int n;
    cin>>n;

    ll ans = 0;

    for(int i = 1; i <= n; i++)
    {
        makeset(i);
    }

    for(int i = n / 2; i >= 1; i--)
    {
        for(int j = i + i; j <= n; j += i)
        {
            int u,v;
            u = findRep(i);
            v = findRep(j);

            if(u!=v)
            {
                Union(i, j, u, v);
                ans += i;
            }
        }
    }

    cout<<"Case "<<tc<<": "<<ans<<endl;

    return;
}

int main()
{
    faster_io;

//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);


    int test_case=1;
    cin>>test_case;
    for(int tc=1 ; tc<=test_case; tc++)
    {
        solve_case(tc);
    }
///  KeyPoint


///  Corner Cases




    return 0;
}


