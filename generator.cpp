#include<bits/stdc++.h>
using namespace std;
#define ll long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll my_rand(ll l, ll r) {
	return uniform_int_distribution<ll>(l, r) (rng);
}

// int main()
// {
// 	int tt = my_rand(1, 5);
// 	cout << tt << endl;
// 	while (tt--) {
// 		int n = my_rand(1, 6);
// 		cout << n << endl;
// 	}
// 	return 0;
// }


/// Array
int main()
{
	int t = my_rand(1, 5);
	cout << t << endl;
	while (t--) {
		int n = my_rand(1, 10);
		int k = my_rand(1, 10);
		cout << n << " " << k << endl;

		for (int i = 1; i <= n; i++) {
			ll x = my_rand(-2, k);
			if (x == 0) {
				x = my_rand(1, k);
			}
			cout << x << " ";
		}
		cout << endl;
	}
	return 0;
}

/// Tree
// int main()
// {
// 	ll t = my_rand(5, 5);
// 	t = 1;
// 	// cout << t << endl << endl;

// 	while (t--) {
// 		int n = my_rand(2, 100);
// 		cout << n << endl;
// 		int val[n + 5];
// 		for (int i = 0; i < n; i++) {
// 			val[i] = my_rand(0, 1000);
// 			// cout << val[i] << " ";
// 		}
// 		// cout << endl;
// 		vector<pair<int, int>> edges;
// 		for (int i = 2; i <= n; ++i) {
// 			edges.emplace_back(my_rand(1, i - 1), i);
// 		}

// 		vector<int> perm(n + 1); // re-naming vertices
// 		for (int i = 1; i <= n; ++i) {
// 			perm[i] = i;
// 		}
// 		random_shuffle(perm.begin() + 1, perm.end());

// 		random_shuffle(edges.begin(), edges.end()); // random order of edges

// 		for (pair<int, int> edge : edges) {
// 			int a = edge.first, b = edge.second;
// 			if (my_rand(a, b) % 2) {
// 				swap(a, b); // random order of two vertices
// 			}
// 			cout << " " << perm[a] << " " << perm[b] << endl;

// 		}
// int q = my_rand(1, 100);
// cout << q << endl;
// while (q--) {
// 	int u, v;
// 	int type = my_rand(0, 1);
// 	u = my_rand(0, n - 1);
// 	v = my_rand(0, n - 1);
// 	cout << type << " " << u << " " << v << endl;
// 		// }
// 	}


// 	return 0;
// }
