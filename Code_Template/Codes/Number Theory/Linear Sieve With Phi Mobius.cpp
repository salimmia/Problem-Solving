bitset<mxn>is_composite;
vector<int>prime;
int phi[mxn], mobius[mxn];
void linearSieve(int n) {
    phi[1] = mobius[1] = 1;
    for (int i = 2; i <= n; i++) {
        mobius[i] = 1;
        if (!is_composite[i]) {
            prime.push_back(i);
            phi[i] = i - 1;          ///i is prime
        }
        for (int j = 0; j < prime.size() && i * prime[j] <= n; j++)  {
            is_composite[i * prime[j]] = true;
            if (i % prime[j] == 0) {
                phi[i * prime[j]] = phi[i] * prime[j]; ///prime[j] divides i
                break;
            }
            else {
                phi[i * prime[j]] = phi[i] * phi[prime[j]]; ///prime[j] do not divide i
            }
        }
    }
    for (int val : prime) {
        int temp = val * val;
        if (temp > n)break;
        for (int j = temp; j <= n; j += temp) mobius[j] = 0;
    }
    for (int val : prime) {
        for (int j = val; j <= n; j += val) mobius[j] *= -1;
    }
}


linearSieve(mxn - 1);