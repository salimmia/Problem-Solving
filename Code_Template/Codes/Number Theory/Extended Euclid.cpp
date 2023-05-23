
int Extended_Euclidean(int a, int b, int &x, int &y)
{
    if (b == 0) {
        x = 1; y = 0;
        return a;
    }
    int d = Extended_Euclidean(b, a % b, y, x);
    y = y - (a / b) * x;
    return d;
}

//*** for infinite other solution:
///xi = x + k * b / (__gcd(a, b))
///yi = y - k * a / (__gcd(a, b))
int Inverse_Modulo(int a, int m) {
    int x, y, d;
    d = Extended_Euclidean(a, m, x, y);
    if (d == 1) return (x + m) % m;
    return -1; //No Solution
}



long long ext_gcd (long long A, long long B, long long &X, long long &Y) {
    long long x2, y2, x1, y1, x, y, r2, r1, q, r;
    x2 = 1, y2 = 0;
    x1 = 0, y1 = 1;
    for (r2 = A, r1 = B; r1 != 0; r2 = r1, r1 = r, x2 = x1, y2 = y1, x1 = x, y1 = y ) {
        q = r2 / r1;
        r = r2 % r1;
        x = x2 - (q * x1);
        y = y2 - (q * y1);
    } X
        = x2;
    Y = y2;
    return r2;
}
