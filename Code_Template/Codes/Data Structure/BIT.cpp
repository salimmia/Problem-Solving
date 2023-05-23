#include<bits/stdc++.h>
using namespace std;

//tested : https://lightoj.com/problem/curious-robin-hood

#define mxn 200005
#define ll long long

ll n, arr[mxn], bit[mxn];


void update(int idx, int x) //n is the size of the array, x is the number to add
{
       while(idx <= n)
       {
             bit[idx] += x;
             idx += idx & (-idx);
       }
}

ll query(int idx) /// sum fo arr[1] to arr[idx];
{
       ll sum=0;
       while(idx > 0)
       {
             sum += bit[idx];
             idx -= idx & (-idx);
       }
       return sum;
}

ll Rquery(int l, int r)
{
    if(r < l) return 0;
    return query(r) - query(l - 1);
}


void solve_case(int tc)
{
    cout<<"Case "<<tc<<":"<<endl;
    cin>>n;

    int q; 
    cin>>q;

    memset(bit, 0, sizeof bit);

    ///*** Here BIT is 1 indexed, so be careful

    for(int i = 1; i <= n; i++)
    {
        cin>>arr[i];
        update(i, arr[i]);
    }

    // for(int i = 1; i <= n; i++)
    // {
    //     cout<<bit[i]<<" ";
    // }
    // cout<<endl;



    while(q--)
    {
        int type; 
        cin>>type;

            ///*** Here BIT is 1 indexed, so be careful

        if(type == 1)
        {
            int idx;
            cin>>idx;
            cout<<arr[idx + 1]<<endl;
            update(idx + 1 , -arr[idx + 1]);
            arr[idx + 1] = 0;
        }
        else if(type == 2)
        {
            int idx, val;
            cin>>idx>>val;

            update(idx + 1 , val);
            arr[idx + 1] += val;
        }
        else 
        {
            int l, r;
            cin>>l>>r;

            ///*** Here BIT is 1 indexed, so be careful

            cout<<Rquery(l + 1, r + 1)<<endl;

        }
    }

}

int main()
{

    int test_case=1;
    cin>>test_case;
    for(int tc=1 ; tc<=test_case; tc++)
    {
        solve_case(tc);
    }

    return 0;
}