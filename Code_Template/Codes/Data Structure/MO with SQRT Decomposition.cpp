//MO is very useful when add / remove can be easily handled 
// and Qeury can be handled OFFLINE 
//TC : N * sqrt(N) + Q * sqrt(N)

/// this code is for number of distinct element between l to r 
#include<bits/stdc++.h>
using namespace std;

///faster io
#define faster_io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const int mxn = 1e5 + 100, b_size = 400;
//make block size const and little more than sqrt(n)


struct Query
{
    int l, r, qid;

    bool operator< (const Query &q)
    {
        return make_pair(l/b_size, r) < make_pair(q.l/b_size, q.r);
    }
};


int arr[mxn];
Query Q[mxn];
int distinct; 
int freq[mxn]; //values may need to be companssed for freq[] table.
int ans[mxn];


void add(int idx)
{
    freq[arr[idx]]++;
    if(freq[arr[idx]] == 1) distinct++;
}

void del(int idx)
{
    freq[arr[idx]]--;
    if(freq[arr[idx]] == 0) distinct--;
}





void solve_case(int tc)
{
    memset(freq, 0, sizeof freq);
    distinct = 0;

    int n, q; 
    cin >> n >> q; 

    for(int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }

    for(int i = 0; i < q; i++)
    {
        cin>>Q[i].l >> Q[i].r;
        Q[i].l--; Q[i].r--; ///*** make sure l, r are 0 base indexed

        Q[i].qid = i;
    }

    sort(Q, Q + q);

    int L = 0, R = -1; //current candidate range here it is NULL

    for(int i = 0; i < q; i++)
    {
        ///*** 0 based indexing is used
        int l = Q[i].l, r = Q[i].r; 

        while(l < L) add(--L);
        while(r > R) add(++R);

        while(l > L) del(L++); 
        while(r < R) del(R--);

        ans[Q[i].qid] = distinct;
    }

    cout<<"Case "<<tc<<":"<<endl;

    for(int i = 0; i < q; i++)
    {
        cout << ans[i] << endl;
    }
    //cout<<endl;


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






