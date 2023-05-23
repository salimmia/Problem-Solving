#include<bits/stdc++.h>
using namespace std;

#define MAXN 1000000


vector <int> prime;
bitset<mxn>is_composite;
void linearSieve (int n) {
    for (int i = 2; i < n; ++i) {
        if (!is_composite[i]) prime.push_back (i);
        for (int j = 0; j < prime.size () && i * prime[j] < n; ++j) {
            is_composite[i * prime[j]] = true;
            if (i % prime[j] == 0) break;
        }
    }
}
linearSieve(mxn - 1);


int main()
{
    int n;
    cin >> n;
    linearSieve(n);
    int prime_cnt = 0;
    for (auto it = prime.begin(); it != prime.end(); it++)
    {
        cout << *it << " ";
        prime_cnt++;
    }
    cout << endl << "Num of Prime : " << prime_cnt << endl;
    cout << "Composite Checked : " << composite_cnt << endl;
    return 0;
}
