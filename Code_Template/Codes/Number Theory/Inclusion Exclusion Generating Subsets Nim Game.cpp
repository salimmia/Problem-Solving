https://toph.co/p/towers-of-doom
inclusion Exclusion and Nim Game (If xor == 0 then first player wins)
// Created by Neaj_Morshad_101
#include<bits/stdc++.h>
using namespace std;


///typedef
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pii;

///define constant
const ll mxn = 200005;
const ll mod = 1000000007;//1e9+7;

///faster io
#define faster_io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

///debug
#define watch(x) cout << __LINE__ << " says: " << #x << " = " << x << "\n"
#define watch2(x,y) cout<< __LINE__ << " says: " <<#x<<" = "<<x<<" "<<#y<<" = "<<y <<endl
#define watch3(x,y,z) cout<< __LINE__ << " says: " <<#x<<" = "<<x<<" "<<#y<<" = "<<y <<" "<<#z<<" = "<<z<<endl


///program starts...........




void solve_case(ll tc)
{
	ll n, s;
	cin >> n >> s;

	ll ans = 0;

	ll h[n];

	for (ll i = 0; i < n; i++)
		cin >> h[i];

	ll ss[s];

	for (ll i = 0; i < s; i++)
	{
		cin >> ss[i];
	}

	ll power2ofs = (1ll << s);

	for (ll i = 0; i < n; i++)
	{
		ll stonei = 1;
		for (ll nibo = 1; nibo < power2ofs; nibo++)
		{
			ll lcm = 1;

			for (ll j = 0; j < s; j++)
			{
				//watch2(nibo, j);
				if ((nibo & (1ll << j)))
				{
					//cout << "dukce" << endl;
					//watch2(j, ss[j]);

					lcm = ((ss[j] * lcm) / __gcd(ss[j], lcm));

				}
			}
			//cout << "nibo : " << nibo << " " << "lcm : " << lcm << endl;

			if (__builtin_popcount(nibo) & 1)
			{
				stonei += (h[i] / lcm);
			}
			else
			{
				stonei -= (h[i] / lcm);
			}
			//cout << endl << endl;
		}
		//cout << "ans : " << stonei << endl;


		ans = ans ^ stonei;
	}

	cout << "Case " << tc << ": ";

	if (ans)
	{
		cout << "Alice" << endl;
	}
	else
	{
		cout << "Bob" << endl;
	}



	return;
}

int main()
{
	faster_io;

//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);


	ll test_case = 1;
	cin >> test_case;
	for (ll tc = 1 ; tc <= test_case; tc++)
	{
		solve_case(tc);
	}
///  KeyPoll


///  Corner Cases




	return 0;
}


