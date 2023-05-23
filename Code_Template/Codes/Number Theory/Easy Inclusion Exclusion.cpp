//Easy Inclusion Exclusion: https://lightoj.com/problem/helping-cicada
//Created by Neaj_Morshad_101
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




void solve_case(int tc)
{
	int n, k;
	cin >> n >> k;

	int arr[k];

	for (int i = 0; i < k; i++)
	{
		cin >> arr[i];
	}

	int power_k = (1 << k);

	ll ans = n;

	for (int i = 1; i < power_k; i++)
	{
		int cnt = 0;
		ll lcm = 1;
		bool need = true;
		for (int j = 0; j < k; j++)
		{
			if (i & (1 << j))
			{
				cnt++;

				lcm = ((lcm * arr[j]) / (__gcd(lcm, (ll)arr[j])));
				if (lcm > n)
				{
					need = false;
					break;
				}

			}
		}

		if (need)
		{
			if (cnt & 1)
			{
				ans -= (n / lcm);
			}
			else
			{
				ans += (n / lcm);
			}
		}
	}

	cout << "Case " << tc << ": ";

	cout << ans << endl;



	return;
}

int main()
{
	faster_io;

//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);


	int test_case = 1;
	cin >> test_case;
	for (int tc = 1 ; tc <= test_case; tc++)
	{
		solve_case(tc);
	}
///  KeyPoint


///  Corner Cases




	return 0;
}


