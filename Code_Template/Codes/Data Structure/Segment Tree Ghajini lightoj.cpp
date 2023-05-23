#include<bits/stdc++.h>
using namespace std;


///typedef
typedef long long ll;
typedef pair<int, int> pii;

///define constant
const ll mxn = 200009;
const int mod = 1000000007;//1e9+7;

///faster io
#define faster_io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

///debug
#define watch(x) cerr << __LINE__ << " says: " << #x << " = " << x << "\n"
#define watch2(x,y) cout<< __LINE__ << " says: " <<#x<<" = "<<x<<" "<<#y<<" = "<<y <<endl
#define watch3(x,y,z) cout<< __LINE__ << " says: " <<#x<<" = "<<x<<" "<<#y<<" = "<<y <<" "<<#z<<" = "<<z<<endl


///program starts...........


int n, d;
ll arr[mxn+2];

ll tree1[4*mxn];
ll tree2[4*mxn];

ll Merge1(ll a, ll b)
{
    return max(a,b); //may change depending on the problem...
}

ll Merge2(ll a, ll b)
{
    return min(a,b); //may change depending on the problem...
}

void build1(int node, int b, int e)
{
    if(b==e)
    {
        tree1[node] = arr[b];
        return;
    }

    int mid = (b+e)/2;
    int left = 2*node;
    int right = left + 1;

    build1(left, b, mid);
    build1(right, mid+1, e);

    tree1[node] = Merge1(tree1[left], tree1[right]);
}

void build2(int node, int b, int e)
{
    if(b==e)
    {
        tree2[node] = arr[b];
        return;
    }

    int mid = (b+e)/2;
    int left = 2*node;
    int right = left + 1;

    build2(left, b, mid);
    build2(right, mid+1, e);

    tree2[node] = Merge2(tree2[left], tree2[right]);
}

ll query1(int node, int b, int e, int l, int r)
{
    if(l<=b and e<=r)
    {
        return tree1[node];
    }
    if(b>r or e<l)
    {
        return INT_MIN; //may change depending on the problem...
    }

    int mid = (b+e)/2;
    int left = 2*node;
    int right = left + 1;

    ll x = query1(left, b, mid, l, r);
    ll y = query1(right, mid +1, e, l, r);

    return Merge1(x,y);

}

ll query2(int node, int b, int e, int l, int r)
{
    if(l<=b and e<=r)
    {
        return tree2[node];
    }
    if(b>r or e<l)
    {
        return INT_MAX; //may change depending on the problem...
    }

    int mid = (b+e)/2;
    int left = 2*node;
    int right = left + 1;

    ll x = query2(left, b, mid, l, r);
    ll y = query2(right, mid +1, e, l, r);

    return Merge2(x,y);

}

void solve_case(int tc)
{
    cin>>n>>d;

    for(int i=1; i<=n; i++)
        cin>>arr[i];

    build1(1, 1, n);
    build2(1, 1, n);

    int ans = -1;
    for(int i=1; i+d-1<=n; i++)
    {
        int l = i;
        int r = i+d-1;

        int mx = query1(1, 1, n, l, r);
        int mn = query2(1, 1, n, l, r);
        if(ans < mx - mn)
        {
            ans = mx-mn;
        }
    }
    cout<<"Case "<<tc<<": "<<ans<<endl;

    return;
}

int main()
{
    faster_io;
    int test_case=1;
    cin>>test_case;
    for(int tc=1 ; tc<=test_case; tc++)
    {
        solve_case(tc);
    }

    return 0;
}


