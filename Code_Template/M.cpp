// Created by Neaj_Morshad_101
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


int dp[10009][10000];


int func(int i, int j)
{
	if (i < 2 and j < 2) return 0;

	if (dp[i][j] != -1) return dp[i][j];

	bool ans = 0;

	for (int ii = 2; ii <= i; ii += 2)
	{
		if (func(i - ii, j + (ii / 2)) == 0)
		{
			ans = 1;
			break;
		}
	}


	for (int ii = 2; ii <= j; ii += 2)
	{
		if (func(i + (ii / 2), j - ii) == 0)
		{
			ans = 1;
			break;
		}
	}

	dp[i][j] = ans;
	return ans;
}



void solve_case(int tc)
{
	memset(dp, -1, sizeof dp);
	int n, m;
	cin >> n >> m;

	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= m; j++)
		{
			if (func(i, j) == 0)
			{
				int dif = abs(i - j);
				//watch(dif);
				if (dif > 1)
				{
					cout << "WHAT!" << endl;
				}
				//watch3(i, j, func(i, j));
			}
		}
	}


	return;
}

int main()
{
	faster_io;

//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);


	int test_case = 1;
	//cin>>test_case;
	for (int tc = 1 ; tc <= test_case; tc++)
	{
		solve_case(tc);
	}
///  KeyPoint


///  Corner Cases




	return 0;
}


