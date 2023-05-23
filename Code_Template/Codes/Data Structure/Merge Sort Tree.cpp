///Merge Sort Tree
//tested : https://www.spoj.com/problems/INVCNT/
#include<bits/stdc++.h>
using namespace std;

#define faster_io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

///typedef
typedef long long ll;

///define constant
const ll mxn = 200005;

int n, k, arr[mxn];
vector < int > treeNode[mxn*4];

//TC: O(NlogN) 
//MC: O(NlogN)
void build(int node, int b, int e)
{
    if(b == e){
        treeNode[node].push_back(arr[b]);
        return;
    }

    int mid = (b+e)/2;
    int left = node*2;
    int right = left+1;

    build(left, b, mid);
    build(right, mid+1, e);

    ///merge two sorted vector in sorted order 
    ///O(n1 + n2)
    merge(treeNode[left].begin(), treeNode[left].end(),
        treeNode[right].begin(), treeNode[right].end(),
        back_inserter(treeNode[node]));

    ///we could use treeNode[node].begin() instead of back_inserter(treeNode[node])
}

//TC: O(logN)^2 because of binary search inside the query 
ll query(int node, int b, int e, int i, int j) // query in range i to j
{

    if(i>e || j<b) 
        return 0;

    if(b>=i && e<=j)
    {

        ll cnt = treeNode[node].end() - upper_bound(treeNode[node].begin(),
            treeNode[node].end(), k);
        return cnt;
    }

    int mid=(b+e)/2;
    int left=node*2;
    int right=left+1;

    ll p=query(left,b,mid,i,j);
    ll q=query(right,mid+1,e,i,j);

    return p+q;
}

void clr()
{
    for(int i = 0; i < mxn * 4; i++)
    {
        treeNode[i].clear();
    }
}

void solve_case(int tc)
{
    clr();
    cin>>n;

    for(int i = 1; i <= n; i++)
    {
        cin>>arr[i];
    }

    build(1, 1, n);

    ll inv_cnt = 0; 

    for(int i = 2; i <= n; i++)
    {
        k = arr[i];
        int inv = query(1, 1, n, 1, i-1);

        //cout<<"i : "<<i<<" inv : "<<inv<<endl;
        inv_cnt += inv;
    }

    cout<<inv_cnt<<endl;


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


