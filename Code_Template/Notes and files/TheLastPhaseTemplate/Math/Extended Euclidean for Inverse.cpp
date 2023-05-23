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
int Inverse_Modulo(int a, int m) {
	int x, y, d;
	d = Extended_Euclidean(a, m, x, y);
	if (d == 1) return (x + m) % m;
	return -1; //No Solution
}