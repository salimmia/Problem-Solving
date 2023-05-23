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

int xx[4]={1, -1, 0, 0};
int yy[4]={0, 0, 1, -1};


void solve_case(int tc)
{
    int R, C;
    cin>>R>>C;

    int arr[R+1][C+1];

    priority_queue<pair<int, pair<int,int>>>pq;
    // priority_queue<type, vector<type>, greater<type>>pq; for min heap   priority_queue <int, vector<int>, greater<int> > pq;

    for(int i=1; i<=R; i++)
    {
        for(int j=1; j<=C; j++)
        {
            cin>>arr[i][j];
            pq.push({arr[i][j], {i,j}});
        }
    }

    ll ans = 0;

    while(!pq.empty())
    {
        int val = pq.top().first;
        int x = pq.top().second.first;
        int y = pq.top().second.second;

        pq.pop();

        if(arr[x][y]>val) continue;

        for(int i=0; i<4; i++)
        {
            int p1 = xx[i]+x;
            int p2 = yy[i]+y;

            if(p1>=1 and p1<=R and p2>=1 and p2<=C and arr[p1][p2]+1<arr[x][y])
            {
                ans+=arr[x][y]-arr[p1][p2]-1;
                arr[p1][p2] = arr[x][y]-1;
                pq.push({arr[p1][p2], {p1, p2}});
            }
        }

    }


    cout<<"Case #"<<tc<<": ";
    cout<<ans<<endl;


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



