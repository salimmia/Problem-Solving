
#include<bits/stdc++.h>
using namespace std;

#define ll long long

#define debug() cerr<<"LINE "<<__LINE__<<" >> ", printer()
#define dbg(x) "[",#x,": ",(x),"] "




mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll my_rand(ll l, ll r) {
	return uniform_int_distribution<ll>(l, r) (rng);
}

long long random(long long a, long long b) {
	return a + rng() % (b - a + 1);
}

void solve()
{
	///For Stress Testing for Windows
	//first run brute.cpp and solution.cpp and testGenerator.cpp file
	//run this command : cd C:\Users\pikter\Dropbox\Code Template
	//run this command : checker.bat
	// to clear the display use command: cls


	///For Stress Testing for Linux
	//first run brute.cpp and solution.cpp and testGenerator.cpp file
	//run this command : cd /home/ashik/Dropbox/Code_Template
	//then run this command : /Dropbox/Code_Template$ bash s.sh
	// to clear the display use command: clear

	//Input Output for Linux : testInput solutionOutput BruteOutput (without extension .txt)

	int t = my_rand(1, 1);
	cout << t << endl;
	while (t--)
	{
		int n = my_rand(2, 10);
		cout << n << " ";

		// cout<<my_rand(1, n - 1)<<endl;
		// // int m = my_rand(1, 3);
		// // cout<<m<<" ";
		// // cout<<my_rand(1, min(n,m))<<endl;

		// for(int i = 0; i < n; i++)
		// {
		// 	cout<<my_rand(-10, 10)<<" ";
		// }
		// cout<<endl;

		// int n = my_rand(1, 20);
		// cout<<n<<endl;
		//int M = my_rand(10, 150);

		//int k=my_rand(1,n);
		//int s=my_rand(1,10000);
		//cout<<n<<" "<<k<<" "<<s<<endl;

		//int n = 10;

		//int q = my_rand(1, 5);
		//cout<<n<<" "<<q<<endl;

		//ll sum = 0;

		//vector<int>v;



		// for(int i = 0; i < n; i++)
		// {
		// 	int x = my_rand(1, 1000000000);
		// 	//cout<<x<<" ";

		// 	//sum += x;
		// 	//v.push_back(min(x, M));
		// }
		//sort(v.begin(), v.end());
		// for(int i = 0; i < n; i++)
		// {
		// 	cout<<v[i]<<" ";
		// }
		//cout<<endl;
		// sum %= 3;
		// cout<<3 - sum<<endl;

		// 	// k = my_rand(1, 10);

		// 	// for(int i = 0; i < k; i++)
		// 	// {
		// 	// 	int x = my_rand(1, 100);
		// 	// 	if(x&1) cout<<1;
		// 	// 	else cout<<0;
		// 	// }
		// 	// cout<<endl;
		// 	// cout<<endl;
		// }
		// int n = 30;
		// //for(int i=1;i<=n;i++) cout<<my_rand(1,100) % 2<<" ";


		// int q = my_rand(1, 5);

		// cout<<q<<endl;

		// while(q--)
		// {
		// 	cout<<my_rand(1, 1000000) % n + 1;
		// 	cout<<" "<<my_rand(0, 10)<<endl;
		// }

		ll a = my_rand(1, 1000000000000000000ll);
		ll b = my_rand(a + 1, 1000000000000000100ll);
		ll c = my_rand(b + 1, 1000000000000000900ll);

		cout << a << " " << b << " " << c << endl;


	}


}

int main()
{
	int t = 1;
	//scanf("%d",&t);
	while (t--)solve();
	return 0;
}