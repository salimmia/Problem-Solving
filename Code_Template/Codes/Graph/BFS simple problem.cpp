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


int xx[]= {1, -1, 0, 0, 1, -1, 1, -1};
int yy[]= {0, 0, 1, -1, 1, 1, -1, -1};


int main()
{
    faster_io;

//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);


    int R, C, cx, cy;
    cin>>R>>C>>cx>>cy;

    queue<pair<int,int>>Q;

    bool vis[R][C];
    int dis[R][C];

    dis[cx][cy]=0;

    memset(vis, false, sizeof vis);

    Q.push({cx, cy});

    while(!Q.empty())
    {
        int ix = Q.front().first;
        int iy = Q.front().second;

        Q.pop();

        vis[ix][iy]=true;

        for(int i=0; i<8; i++)
        {
            int x = xx[i]+ix;
            int y = yy[i]+iy;

            if(x>=0 and x<R and y>=0 and y<C and !vis[x][y])
            {

                vis[x][y]=true;

                dis[x][y]=dis[ix][iy]+1;
                Q.push({x,y});
            }



        }



    }


    for(int i=0; i<R; i++)
    {
        for(int j=0; j<C; j++)
        {
            cout<<dis[i][j]<<" ";
        }
        cout<<endl;
    }



    return 0;
}


