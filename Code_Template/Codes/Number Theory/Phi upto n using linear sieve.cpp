#include<bits/stdc++.h>
using namespace std;

#define MAXN 1000000

vector <int> prime;
bool is_composite[MAXN];
int phi[MAXN];

void linear_sieve (int n) {
	fill (is_composite, is_composite + n, false);
	phi[1] = 1;
	for (int i = 2; i < n; ++i) {
		if (!is_composite[i]) {
			prime.push_back (i);
			phi[i] = i - 1;					//i is prime
		}
		for (int j = 0; j < prime.size () && i * prime[j] < n; ++j) {
			is_composite[i * prime[j]] = true;
			if (i % prime[j] == 0) {
				phi[i * prime[j]] = phi[i] * prime[j];	//prime[j] divides i
				break;
			} else {
				phi[i * prime[j]] = phi[i] * phi[prime[j]];	//prime[j] does not divide i
			}
		}
	}
}

int main()
{
    int n=11;
    //cin>>n;
    linear_sieve(n);
    for(int i=0;i<n;i++)
        cout<<phi[i]<<" ";
    cout<<endl;

}

/** for more on linear sieve and multiplicative function :
https://codeforces.com/blog/entry/54090?fbclid=IwAR1c_ypXeQmEr3Iu_e128I2pb4hsFZZXK5oaCmvFSruBDicMTmMjz9GT1As
*/

