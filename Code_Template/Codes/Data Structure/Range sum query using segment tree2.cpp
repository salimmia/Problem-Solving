#include<bits/stdc++.h>
using namespace std;


///typedef
typedef long long ll;
typedef pair<int, int> pii;

///define constant
const ll mxn = 200005;
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

ll tree[100*mxn];

ll Merge(ll a, ll b)
{
    return a+b; //may change depending on the problem...
}


void build(int node, int b, int e)
{
    if(b==e)
    {
        tree[node] = arr[b];
        return;
    }

    int mid = (b+e)/2;
    int left = 2*node;
    int right = left + 1;

    build(left, b, mid);
    build(right, mid+1, e);

    tree[node] = Merge(tree[left], tree[right]);
}

ll query(int node, int b, int e, int l, int r)
{
    if(l<=b and e<=r)
    {
        return tree[node];
    }
    if(b>r or e<l)
    {
        return 0; //may change depending on the problem...
    }

    int mid = (b+e)/2;
    int left = 2*node;
    int right = left + 1;

    ll x = query(left, b, mid, l, r);
    ll y = query(right, mid +1 , e, l, r);

    return Merge(x,y);

}

void solve_case(int tc)
{
    cin>>n;
    int q;
    cin>>q;
    for(int i=1; i<=n; i++)
        cin>>arr[i];


    build(1, 1, n);

    int l, r;
    while(q--)
    {
        cin>>l>>r;

        cout<<query(1, 1, n, l, r)<<endl;
    }

    return;
}

int main()
{
    faster_io;

//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);


    int test_case=1;
    //cin>>test_case;
    for(int tc=1 ; tc<=test_case; tc++)
    {
        solve_case(tc);
    }
///  KeyPoint


///  Corner Cases




    return 0;
}



