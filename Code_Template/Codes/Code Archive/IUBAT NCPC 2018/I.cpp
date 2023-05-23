#include<bits/stdc++.h>
using namespace std;


///typedef
typedef long long ll;
typedef pair<int, int> pii;

///define constant
const ll mxn = 10005;
const int mod = 1000000007;//1e9+7;

///faster io
#define faster_io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

///debug
#define watch(x) cout << __LINE__ << " says: " << #x << " = " << x << "\n"
#define watch2(x,y) cout<< __LINE__ << " says: " <<#x<<" = "<<x<<" "<<#y<<" = "<<y <<endl
#define watch3(x,y,z) cout<< __LINE__ << " says: " <<#x<<" = "<<x<<" "<<#y<<" = "<<y <<" "<<#z<<" = "<<z<<endl


///program starts...........

int n, m, k;

int arr[mxn];

bool ok(int x)
{
	int need = 0;

	int upto = 0;

	for(int i = 0; i < m; i++)
	{
		if(arr[i] <= upto) continue;

		need++;

		//watch3(i, arr[i], need);

		upto = arr[i] + 2 * x;
	}

	return need <= k;

}


void solve_case(int tc)
{
	cin>>n>>m>>k;

	for(int i = 0; i < m; i++)
	{
		cin>>arr[i];
	}

	int tlo = 0, thi = n;
	ll ans = n;

	while(tlo <= thi)
	{
		int mid = (tlo + thi) / 2;
		//watch(mid);

		if(ok(mid))
		{
			ans = mid;
			//watch(ans);
			thi = mid - 1;
		}
		else 
		{
			tlo = mid + 1;
		}
	}

	cout<<"Case "<<tc<<": ";

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


