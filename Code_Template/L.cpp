// Created by Neaj_Morshad_101
#include<bits/stdc++.h>
using namespace std;


///typedef
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

///define constant
const ll mxn = 1000006;
const int mod = 1000000007;//1e9+7;

///faster io
#define faster_io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

///debug
#define watch(x) cout << __LINE__ << " says: " << #x << " = " << x << "\n"
#define watch2(x,y) cout<< __LINE__ << " says: " <<#x<<" = "<<x<<" "<<#y<<" = "<<y <<endl
#define watch3(x,y,z) cout<< __LINE__ << " says: " <<#x<<" = "<<x<<" "<<#y<<" = "<<y <<" "<<#z<<" = "<<z<<endl


///program starts...........


const int N = mxn - 1;
int lp[N + 1];
vector<int> pr; // prs

void sieve()
{
	//cout<<"He"<<endl;
	for (int i = 2; i <= N; ++i) {
		if (lp[i] == 0) {
			lp[i] = i;
			pr.push_back (i);
		}
		for (int j = 0; j < (int)pr.size() && pr[j] <= lp[i] && i * pr[j] <= N; ++j)
		lp[i * pr[j]] = pr[j];
	}

	
}

vector<pair<ll, int>> prFactorize(ll num)
{
	int sq = sqrtl(num + 0.99);
	vector<pair<ll, int>> res;
	for (int i = 0; pr[i] <= sq; i++)
	{
		if(num % pr[i]) continue;

		int cnt = 0;

		while(num % pr[i] == 0)
		{
			cnt++;
			num /= pr[i];
		}


		res.push_back({pr[i], cnt});
	}

	if(num > 1) res.push_back({num, 1});

	return res;
}

void solve_case(int tc)
{
	memset(lp, 0, sizeof lp);
	pr.clear();
	cout<<"hell"<<endl;

	int a, b;
	cin >> a >> b;
	ll L;
	cin >> L;

	ll c = 1;

	vector<pair<ll, int>> va = prFactorize(a);
	vector<pair<ll, int>> vb = prFactorize(b);
	vector<pair<ll, int>> vL = prFactorize(L);


	vector<pair<ll, int>> ab;

	int i = 0, j = 0;

	while(i < va.size() and j < vb.size())
	{
		if(va[i].first == vb[j].first)
		{
			ab.push_back({va[i].first, max(va[i].second, vb[i].second)});
			i++; j++;
		}
		else if(va[i].first < vb[j].first)
		{
			ab.push_back(va[i]);
			i++;
		}
		else 
		{
			ab.push_back(vb[j]);
			j++;
		}
	}

	while(i < va.size())
	{
		ab.push_back(va[i]);
		i++;
	}
	while(j < vb.size())
	{
		ab.push_back(vb[j]);
		j++;
	}

	i = 0; j = 0;

	bool ok = true;

	while(i < ab.size() and j < vL.size())
	{
		int extra;
		if(ab[i].first == vL[j].first)
		{
			if(ab[i].second > vL[j].second)
			{
				ok = false;
				break;
			}
			else
			{
				extra = vL[j].second - ab[i].second;

				for(int cnt = 0; cnt < extra; cnt++)
				{
					c *= ab[i].first;
				}
			}
			i++; j++;
		}
		else if(ab[i].first < vL[j].first)
		{
			extra = ab[i].second;

			for(int cnt = 0; cnt < extra; cnt++)
			{
				c *= ab[i].first;
			}
			i++;
		}
		else
		{
			extra = vL[j].second;

			for(int cnt = 0; cnt < extra; cnt++)
			{
				c *= vL[j].first;
			}
			j++;
		}
	}

	cout<<"hell"<<endl;

	cout<<c<<endl;



	return;
}

int main()
{
	faster_io;
	sieve();

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


