#include<bits/stdc++.h>
using namespace std;


///typedef
typedef long long ll;
typedef pair<int, int> pii;

///define constant
const int mxn = 200005;
const int mod = 1000000007;//1e9+7;

///faster io
#define faster_io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

///debug
#define watch(x) cerr << __LINE__ << " says: " << #x << " = " << x << "\n"
#define watch2(x,y) cout<< __LINE__ << " says: " <<#x<<" = "<<x<<" "<<#y<<" = "<<y <<endl
#define watch3(x,y,z) cout<< __LINE__ << " says: " <<#x<<" = "<<x<<" "<<#y<<" = "<<y <<" "<<#z<<" = "<<z<<endl


///program starts...........

#define Left (node*2)
#define Right (node*2+1)
#define Mid ((b+e)/2)

// struct NODE
// {
//     NODE(int a, int l, int r)
//     {
//         this->a = a;
//         this->l = l;
//         this->r = r;
//     }
//     NODE () {}
//     int a, l, r;

// } tree[4*mxn];

//NODE dummy = {0, 0, 0};
//NODE node = {2, 45, 9};

int n;
ll arr[mxn+2];

ll tree[4*mxn]; // for N size arary segment tree contains 2N-1 nodes if N is a power of 2. so max size will be 4*N (we need to make N a power of 2)
ll lazy[4*mxn];

//Merge complexity will be multiplied by each of the complexity of build, update and query
//Merging Two Nodes Data
ll Merge(ll a, ll b)
{
    return max(a,b); /// *** may change depending on the problem...
}

//O(N) because number of nodes in the segment tree is 2*N.
void build(int node, int b, int e) //current node and node's range (begin to end)
{
    lazy[node] = 0;  /// *** may change depending on the problem...
    if(b==e)
    {
        tree[node] = arr[b];
        return;
    }

    build(Left, b, Mid);
    build(Right, Mid+1, e);

    tree[node] = Merge(tree[Left], tree[Right]);
}

//O(4*log(N))     at most four nodes are visited in the segment tree.
ll query(int node, int b, int e, int l, int r) //current node and node's range (begin to end) and query range (l to r)
{
    if(l<=b and e<=r)
    {
        return tree[node];
    }
    if(b>r or e<l)
    {
        return INT_MIN; /// *** may change depending on the problem...
    }

    ll x = query(Left, b, Mid, l, r);
    ll y = query(Right, Mid +1, e, l, r);

    return Merge(x,y);

}

//O(log(N))
void update(int node, int b, int e, int i, ll val) // current node and node's range (begin to end) and update on index i with value val ( arr[i] = val )
{
    if(i>e || i<b) return;
    if(b==e)
    {
        tree[node] = val; /// *** may change depending on the problem...
        return;
    }

    update(Left,b,Mid,i,val);
    update(Right,Mid+1,e,i,val);


    tree[node]=Merge(tree[Left],tree[Right]);
}




/*
Lazy Propagation
1. Lets define a range update operation on segment tree OP. If there is a lazy
value x in some node u from some updates, its guaranteed that this lazy value
has been already propagated from each node v in the path from root to u. If
there is still some lazy value at in a node v in the path from root to u, then
that is from some later updates which has not been propagated up-to u yet.

2. Let there be multiple type of range updates. Build a struct called LazyStruct
and keep a lazy variable for each type of update. Note that,
a) for ASSIGN update, clear each other type of lazy variables.
b) while handling ADD/SUB/COUNT lazy in a node, first propagate down any ASSIGN
lazy it already has. This ensures the correct order of the updates.
*/


//O(1)
void lazyPropagation(int node,int b,int e)  // current node and node's range (b to e)
{
    if(lazy[node])
    {
        tree[node] += (e-b+1)*lazy[node]; /// *** may change depending on the problem.. //Adding extra sum // for max query  New Max = Max + lazy[node]
        if(b != e)
        {
            lazy[Left] += lazy[node];
            lazy[Right] += lazy[node];
        }
        lazy[node] = 0;
    }
}

//O(4*log(N))     at most four nodes are visited in the segment tree.
void updateRange(int node, int b, int e, int i, int j, int val)   // current node and node's range (b to e) and update on index i to j with value val ( arr[i] = arr[i+1] = .. = arr[j]  will be (+= val ) )
{
    lazyPropagation(node,b,e);
    if(b>e) return;   // invalid update query like -> updateRange(10, 5) here b > e
    else if(b>j || e<i) return;
    if(b>=i && e<=j)
    {
        lazy[node] += val; /// *** may change depending on the problem...
        lazyPropagation(node,b,e);
        return;
    }
    updateRange(Left,b,Mid,i,j,val);
    updateRange(Right,Mid+1,e,i,j,val);
    tree[node] = Merge(tree[Left], tree[Right]);
}

//O(4*log(N))     at most four nodes are visited in the segment tree.
ll queryRange(int node,int b,int e,int i,int j) //current node and node's range (b to e) and query range (i to j)
{
    if(b>e) return 0; /// *** may change depending on the problem...
    else if(b>j || e<i) return 0;   /// *** may change depending on the problem...
    lazyPropagation(node,b,e);
    if(b>=i && e <= j) return tree[node];
    ll p1 = queryRange(Left,b,Mid,i,j);
    ll p2 = queryRange(Right,Mid+1,e,i,j);
    return  Merge(p1, p2);                       //p1 + p2; sum query
}



void solve_case(int tc)
{
    cin>>n;

    for(int i=1; i<=n; i++)
        cin>>arr[i];

    build(1, 1, n); ///*** 1 indexed

    ///*** cin>>n>>q;
    int q; ///*** may change depending on the problem
    cin>>q;
    while(q--)
    {
        int type;
        cin>>type;

        if(type==1) //update
        {
            int idx, val;
            cin>>idx>>val;
            update(1, 1, n, idx, val);
        }
        else if(type==2) //query
        {
            int l, r;
            cin>>l>>r;

            int ans = query(1, 1, n, l, r);

            cout<<ans<<endl;
        }


    }

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
