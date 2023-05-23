https://toph.co/p/uncle-m



#include<bits/stdc++.h>
using namespace std;


///typedef
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

///define constant
const ll mxn = 200005;
const int mod = 1000000007;//1e9+7;

///faster io
#define faster_io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

///debug
#define watch(x) cout << __LINE__ << " says: " << #x << " = " << x << "\n"
#define watch2(x,y) cout<< __LINE__ << " says: " <<#x<<" = "<<x<<" "<<#y<<" = "<<y <<endl
#define watch3(x,y,z) cout<< __LINE__ << " says: " <<#x<<" = "<<x<<" "<<#y<<" = "<<y <<" "<<#z<<" = "<<z<<endl


///program starts...........


int r, c;




void solve_case(int tc)
{
    cin>>r>>c;
    ll arr[r + 1][c + 1] = {0};
    ll sq_arr[r + 1][c + 1] = {0};
    ll pref_arr[r + 1][c + 1] = {0};
    ll pref_sq_arr[r + 1][c + 1] = {0};

    //watch2(r, c);


    for(int i = 1; i <= r; i++)
    {
        for(int j = 1; j <= c; j++)
        {
            cin>>arr[i][j];
            int x = i, y = j;
            sq_arr[i][j] = arr[i][j] * arr[i][j];
            pref_arr[i][j] = pref_arr[x - 1][y] + pref_arr[x][y - 1] - pref_arr[x - 1][y - 1] + arr[i][j];
            pref_sq_arr[i][j] = pref_sq_arr[x - 1][y] + pref_sq_arr[x][y - 1] - pref_sq_arr[x - 1][y - 1] + sq_arr[i][j];
            //watch3(i, j, pref_arr[i][j]);
        }
    }

    int q;
    cin>>q;

    while(q--)
    {
        int x1, y1, x2, y2;
        cin>>x1>>y1>>x2>>y2;

        ll m = x2 - x1 + 1;
        ll n = y2 - y1 + 1;

        ll sum = pref_arr[x2][y2] - pref_arr[x1 - 1][y2] - pref_arr[x2][y1 - 1] + pref_arr[x1 - 1][y1 - 1];
        ll sq_sum = pref_sq_arr[x2][y2] - pref_sq_arr[x1 - 1][y2] - pref_sq_arr[x2][y1 - 1] + pref_sq_arr[x1 - 1][y1 - 1];

        ld miu = (ld)sum / (m * n);

        ld ans = (sq_sum - 2 * miu * sum +  (m * n ) * miu * miu) / (m * n);

        //watch3(sum, sq_sum, miu);


        cout<<fixed<<setprecision(10)<<ans<<endl;



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


