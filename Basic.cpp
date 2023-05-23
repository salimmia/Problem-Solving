const double inf = 1e100;
const double eps = 1e-9;
const double PI = acos((double) - 1.0);
int sign(double x) { return (x > eps) - (x < -eps);}
struct PT {
    double x, y;
    void read() { scanf("%lf%lf", &x, &y);}
    void write() { printf("%lf %lf\n", x, y);}
    PT() { x = 0, y = 0;}
    PT(double x, double y) : x(x) , y(y) { }
    PT(const PT&p) : x(p.x) , y(p.y) { }
    PT operator+(const PT&a) const { return PT(x + a.x, y + a.y);}
    PT operator-(const PT&a) const { return PT(x - a.x, y - a.y);}
    PT operator*(const double a) const { return PT(x * a, y * a);}
    friend PT operator*(const double&a, const PT&b) { return PT(a * b.x, a * b.y);}
    PT operator/(const double a) const { return PT(x / a, y / a);}
    bool operator==(PT a) const { return sign(a.x - x) == 0 && sign(a.y - y) == 0;}
    bool operator!=(PT a) const { return !(*this == a);}
    bool operator<(PT a) const { return sign(a.x - x) == 0 ? y < a.y : x < a.x;}
    bool operator>(PT a) const { return sign(a.x - x) == 0 ? y > a.y : x > a.x;}
    double norm() { return sqrt(x * x + y * y);}
    double norm2() { return x * x + y * y;}
    PT perp() { return PT(-y, x);}
    double arg() { double x = atan2(y, x); return x;}
    PT truncate(double r) {
        double k = norm(); if (!sign(k)) return*this; r /= k;
        return PT(x * r, y * r);
    }
    friend istream&operator>>(istream&is, PT&p) { return is >> p.x >> p.y;}
    friend ostream&operator<<(ostream&os, const PT&p) {return os << p.x << " " << p.y;}
};//returns a vector with norm r and having same direction
inline double dot(PT a, PT b) { return a.x * b.x + a.y * b.y;}
inline double dist2(PT a, PT b) { return dot(a - b, a - b);}
inline double dist(PT a, PT b) { return sqrt(dot(a - b, a - b));}
inline double cross(PT a, PT b) { return a.x * b.y - a.y * b.x;}
inline double cross2(PT a, PT b, PT c) { return cross(b - a, c - a);}
inline int orientation(PT a, PT b, PT c) { return sign(cross(b - a, c - a));}
PT perp(PT a) { return PT(-a.y, a.x);}
PT rotateccw90(PT a) { return PT(-a.y, a.x);}
PT rotatecw90(PT a) { return PT(a.y, -a.x);}
PT rotateccw(PT a, double t) { return PT(a.x * cos(t) - a.y * sin(t) , a.x * sin(t) + a.y * cos(t));}
PT rotatecw(PT a, double t) { return PT(a.x * cos(t) + a.y * sin(t) , -a.x * sin(t) + a.y * cos(t));}
double SQ(double x) { return x * x;}
double rad_to_deg(double r) { return (r * 180.0 / PI);}
double deg_to_rad(double d) { return (d * PI / 180.0);}
double get_angle(PT a, PT b) {
    double costheta = dot(a, b) / a.norm() / b.norm();
    return acos(max((double) - 1.0, min((double) 1.0, costheta)));
}
bool is_point_in_angle(PT b, PT a, PT c, PT p) { //<bac
    assert(orientation(a, b, c) != 0);
    if (orientation(a, c, b) < 0) swap(b, c);
    return orientation(a, c, p) >= 0 && orientation(a, b, p) <= 0;
}
bool half(PT p) {
    return p.y > 0.0 || (p.y == 0.0 && p.x < 0.0);
}
void polar_sort(vector<PT>&v) {
    sort(v.begin() , v.end() , [](PT a, PT b) {
        return make_tuple(half(a) , 0.0, a.norm2()) < make_tuple(half(b) , cross(a, b), b.norm2());
    });
}