//*** range update is possible in O(sqrt(n)) 
//lazy type implementation... watch ash vai class 22
// use a to_add[] array with block_sum[] for maintaining the range update, 
//actual a[i] = a[i] + to_add[i/block_size] 
// actual block_sum[i] = block_sum[i] + to_add[i] * block_size
#include <bits/stdc++.h>
using namespace std;

#define NUM_OF_BLOCK 100
#define mxn 200005

int n;
int b_sum[NUM_OF_BLOCK]; // array for storing result for each block
int to_add[NUM_OF_BLOCK]; // for range update
int b_size;
int a[mxn];


///O(n)
void precalculate()
{
    for(int i=0; i<n; i++)
    {
        b_sum[i/b_size] += a[i];
    }
}

///O(sqrt(n))
int query(int l,int r)
{
    int sum=0;

    //First Part partially overlapped
    while(l<=r && l%b_size!=0)
    {
        sum += a[l] + to_add[l / b_size];
        ++l;
    }
    // Second Part Fully overlapped
    while(l+b_size<=r)
    {
        sum+=b_sum[l/b_size] + to_add[l/b_size] * b_size;
        l+=b_size;
    }
    //Third part partially overlapped
    while(l<=r)
    {
        sum += a[l] + to_add[l / b_size];
        l++;
    }

    return sum;
}

///O(1)
void update(int i, int val)
{
    b_sum[i / b_size] += (-a[i] + val);
    a[i] = val;
}

void updateRange(int l, int r, int x)
{
    //First Part partially overlapped
    while(l<=r && l%b_size!=0)
    {
        update(l, x);
        ++l;
    }
    // Second Part Fully overlapped
    while(l+b_size<=r)
    {
        to_add[l/b_size] += x;
        l+=b_size;
    }
    //Third part partially overlapped
    while(l<=r)
    {
        update(l, x);
        l++;
    }

}

void init_to_add()
{
    for(int i = 0; i < NUM_OF_BLOCK; i++)
    {
        to_add[i] = 0;
    }
}


int main()
{
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }

    b_size = sqrt(n);

    precalculate();
    init_to_add();

    int q;
    cin>>q;

    while(q--)
    {
        int ch;
        cin>>ch;

        if(ch == 1)
        {
            int idx, val;
            cin>>idx>>val;

            ///*** make sure idexing is 0 based

            update(idx, val);
        }
        else if(ch == 2)
        {
            int l, r, x;
            cin>>l>>r>>x;
            ///*** make sure idexing is 0 based

            updateRange(l, r, x);
        }
        else // ch == 3
        {
            int l, r;
            cin>>l>>r;

            ///*** make sure idexing is 0 based

            int sum = query(l, r);

            cout<<sum<<endl;
        }

        for(int i = 0; i < n; i++)
        {
            cout<<a[i] + to_add[i/b_size]<< " ";
        }
        cout<<endl;
    }
}
