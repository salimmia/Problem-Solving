#define M 40000000
int marked[M/64 + 2];
vector<int>prime;

#define on(x) (marked[x/64] & (1<<((x%64)/2)))
#define mark(x) marked[x/64] |= (1<<((x%64)/2))

bool isPrime(int num) {
    return num > 1 && (num == 2 || ((num & 1) && !on(num)));
}

void sieve(int n) {
    for (int i = 3; i * i < n; i += 2) {
        if (!on(i)) {
            for (int j = i * i; j <= n; j += i + i) {
                mark(j);
            }
        }
    }
    prime.push_back(2);
    for(int i=3; i<M; i+=2) {
        if(isPrime(i))
            prime.pb(i);
    }
}
