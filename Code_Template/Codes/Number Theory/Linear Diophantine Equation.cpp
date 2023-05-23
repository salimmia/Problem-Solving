bool linearDiophantine ( long long A, long long B, long long C, long long &x, long long &y ) {
    int g = gcd ( A, B );
    if ( C % g != 0 ) return false; //No Solution
    int a = A / g, b = B / g, c = C / g;
    if ( g < 0 ) { //Make Sure gcd(a,b) = 1
        a *= -1;
        b *= -1;
        c *= -1;
    }
    ext_gcd( a, b, x, y ); //Solve ax + by = 1
    x *= c;
    y *= c; //ax + by = c
    return true; //Solution Exists
//more solution {x+k*(b/g), y-k*(a/g)}
}
