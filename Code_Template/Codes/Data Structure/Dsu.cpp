#include<bits/stdc++.h>
using namespace std;

#define mxn 100005

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

void Union(int a, int b)
{
    int u,v;
    //finding representative
    u = findRep(a);
    v = findRep(b);

    if(u!=v)
    {
        if(Size[u] < Size[v])
            swap(u,v);

        parent[v] = u;
        Size[u] += Size[v];
    }
}



int main()
{
    int n;
    cin>>n;

    int arr[n];

    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    //initialize disjoint set
    for(int i=0;i<n;i++)
    {
        makeset(arr[i]);
    }

    Union(arr[0], arr[1]);

    Union(arr[1], arr[2]);

    for(int i=0; i<n; i++)
    {
        cout<<findRep(arr[i])<<" ";
    }

}
