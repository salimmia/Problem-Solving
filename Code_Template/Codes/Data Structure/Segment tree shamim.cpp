#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mx 200005
#define mod 1000000007

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)



ll a[mx],tree[4*mx],lazy[4*mx];

ll Merge(ll lft, ll rgt)
{
    return lft+rgt;
}

void relax(ll node, ll b, ll e)
{
    tree[node]+=(e-b+1)*lazy[node];
    ll mid=(b+e)/2;
    ll left=node*2;
    ll right=left+1;
    if(b!=e)
    {
        lazy[left]+=lazy[node];
        lazy[right]+=lazy[node];
    }
    lazy[node]=0;
}

void updateRange(ll node, ll b, ll e, ll i, ll j, ll val)
{
    if(lazy[node]!=0)relax(node,b,e);
    if(i>e || j<b)return;
    if(b>=i && e<=j){
        lazy[node]=val;
        relax(node,b,e);
        return;
    }
    ll mid=(b+e)/2;
    ll left=node*2;
    ll right=left+1;
    updateRange(left,b,mid,i,j,val);
    updateRange(right,mid+1,e,i,j,val);
    tree[node]=Merge(tree[left],tree[right]);
}

void update(ll node, ll b, ll e, ll i, ll val)
{
    if(i>e || i<b)return;
    if(b>=i && e<=i){
        tree[node]+=val;
        return;
    }
    ll mid=(b+e)/2;
    ll left=node*2;
    ll right=left+1;
    update(left,b,mid,i,val);
    update(right,mid+1,e,i,val);
    tree[node]=Merge(tree[left],tree[right]);
}

ll Query(ll node, ll b, ll e, ll i, ll j)
{
    relax(node,b,e);
    if(i>e || j<b)return 0;
    if(b>=i && e<=j)return tree[node];

    ll mid=(b+e)/2;
    ll left=node*2;
    ll right=left+1;
    ll p=Query(left,b,mid,i,j);
    ll q=Query(right,mid+1,e,i,j);
    return Merge(p,q);
}

void clr() { memo(tree, 0), memo(lazy, 0), memo(a, 0); }

void solve(int kk)
{
    clr();
    int n,q;
    scanf("%d %d", &n, &q);

    printf("Case %d:\n", kk);

    while(q--){
        int aa,bb,cc;
        ll val;
        scanf("%d %d %d", &aa, &bb, &cc);
        if(aa == 0){
            scanf("%lld", &val);
            updateRange(1,1,n,bb+1,cc+1,val);
        }
        else printf("%lld\n", Query(1,1,n,bb+1,cc+1));
    }

}

int main()
{
   //fast;
   int t=1,kk=0;
   scanf("%d", &t);
   while(++kk<=t) solve(kk);

   return 0;
}
