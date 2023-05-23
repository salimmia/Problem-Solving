#include<bits/stdc++.h>
using namespace std;
#define mx 1000005
#define ll long long
#define md 1000000007

typedef long double T;
typedef double Tf;
typedef Tf Ti;
const T PI = acos(-1), EPS = 1e-9;
int dcmp(T x) { return abs(x) < EPS ? 0 : (x < 0 ? -1 : 1);}

struct Point {
	T x, y;
	Point(T x = 0, T y = 0) : x(x), y(y) {}

	void read () { scanf("%lf%lf", &x, &y); }
	void write () { printf("%lf %lf\n", x, y); }

	Point operator + (const Point& u) const { return Point(x + u.x, y + u.y); }
	Point operator - (const Point& u) const { return Point(x - u.x, y - u.y); }
	Point operator * (const long long u) const { return Point(x * u, y * u); }
	Point operator*(T d) {return {x * d, y * d};}
	Point operator/(T d) {return {x / d, y / d};} // only for floatingpoint

	bool operator == (const Point& u) const { return dcmp(x - u.x) == 0 && dcmp(y - u.y) == 0; }
	bool operator != (const Point& u) const { return !(*this == u); }
	bool operator < (const Point& u) const { return dcmp(x - u.x) < 0 || (dcmp(x - u.x) == 0 && dcmp(y - u.y) < 0); }

	friend ostream& operator<<(ostream& os, Point p) {
		return os << "(" << p.x << "," << p.y << ")"; /// Some example usage: Point a{3, 4}, b{2, -1};
	}
	friend istream &operator >> (istream &is, Point &p) { return is >> p.x >> p.y; }
};
/// It returns -1 for negative numbers, 0 for zero, and 1 for positive numbers.
template <typename T> int sgn(T x) {
	return (T(0) < x) - (x < T(0));
}

T radian(T a) {return a * PI / 180.0;}
T degree(T a) {return a * 180.0 / PI;}

T sq(Point p) {return p.x * p.x + p.y * p.y;}
double abs(Point p) {return sqrt(sq(p));} /// length

/*To translate an object by a vector #»v , we simply need to add #»v to every point in the object of vector p*/
Point translate(Point v, Point p) {return p + v;}

/*To scale an object by a certain ratio α around a center c, we need to shorten
or lengthen the vector from c to every point by a factor α, while conserving
the direction.*/
Point scale(Point c, double factor, Point p) {
	return c + (p - c) * factor;
}

/*Rotation   In particular, we will often use the (counter-clockwise) rotation centered
on the origin. where theta = a*/
Point rot(Point p, double a) {
	return {p.x * cos(a) - p.y * sin(a), p.x * sin(a) + p.y * cos(a)};
}

/* 90 Degree rotation */
Point perp(Point p) {return { -p.y, p.x};}

T dot(Point v, Point w) {return v.x * w.x + v.y * w.y;}
T cross(Point v, Point w) {return v.x * w.y - v.y * w.x;}

/*f(r) = f(p) + ((r − p) ∗ f(q) − f(p) / (q − p))*/
Point linearTransfo(Point p, Point q, Point r, Point fp, Point fq) {
	Point pq = q - p, num{cross(pq, fq - fp), dot(pq, fq - fp)};
	Point fr;
	return fr = fp + Point{cross(r - p, num), dot(r - p, num)} / sq(pq);
}

/// return true if two vectors v and w are perpendicular
bool isPerp(Point v, Point w) {return dot(v, w) == 0;}

/// angle between vector v and vector w
double angle(Point v, Point w) {
	double cosTheta = dot(v, w) / abs(v) / abs(w);
	return acos(max(-1.0, min(1.0, cosTheta)));
}
double angle(Point v, Point w, bool bk) {
	return atan2(cross(v, w), dot(v, w));
}

/// return 1 if c is left of ab, 0 if on ab && -1 if right of ab
int orient(Point a, Point b, Point c) {return dcmp(cross(b - a, c - a));} /// OK

/// return 1 if point p is in angle CAB
bool inAngle(Point a, Point b, Point c, Point p) {
	assert(orient(a, b, c) != 0);
	if (orient(a, b, c) < 0) swap(b, c);
	return orient(a, b, p) >= 0 && orient(a, c, p) <= 0;
}

/// angle between Orient AB and point C
double orientedAngle(Point a, Point b, Point c) {
	if (orient(a, b, c) >= 0)
		return angle(b - a, c - a);
	else
		return 2 * PI - angle(b - a, c - a);
}

/// return 1 if given point is convex polygon
bool isConvex(vector<Point> p) {
	bool hasPos = false, hasNeg = false;
	for (int i = 0, n = p.size(); i < n; i++) {
		int o = orient(p[i], p[(i + 1) % n], p[(i + 2) % n]);
		if (o > 0) hasPos = true;
		if (o < 0) hasNeg = true;
	}
	return !(hasPos && hasNeg);
}

/// return 1 if point p
// bool inDisk(Point a, Point b, Point p) {
//     return dcmp(dot(a - p, b - p)) <= 0;
// }

// bool onSegment(Point a, Point b, Point p) {
//     return dcmp(orient(a, b, p)) == 0 && inDisk(a, b, p);
// }

// /// return 1 if two lines are intersected;
// bool LineLineIntersection(Point a, Point b, Point c, Point d) /// OK /*https://cses.fi/problemset/task/2190*/
// {
//     return (orient(a, b, c) != orient(a, b, d) && orient(c, d, a) != orient(c, d, b)) ||
//            onSegment(a, b, c) || onSegment(a, b, d) ||
//            onSegment(c, d, a) || onSegment(c, d, b);
// }

// bool half(Point p) {
// 	return cross(v, p) < 0 || (cross(v, p) == 0 && dot(v, p) <
// 	                           0);
// }
// void polarSortAround(Point o, vector<Point> &v) {
// 	sort(v.begin(), v.end(), [](Point v, Point w) {
// 		return make_tuple(half(v - o), 0) <
// 		       make_tuple(half(w - o), cross(v - o, w - o));
// 	});
// }

struct line {
	Point tem1, tem2;
	Point v; T c;
// From direction vector v and offset c
	line(Point v, T c) : v(v), c(c) {}
// From equation ax+by=c
	line(T a, T b, T c) : v( {b, -a}), c(c) {}
// From points P and Q
	line(Point p, Point q) : v(q - p), tem1(p), tem2(q), c(cross(v, p)) {}
// Will be defined later:
// - these work with T = int

	/// return 1 for p is ccw side, 0 for p is in line, -1 for p is in cw
	T side(Point p) {return cross(v, p) - c;}

	/// distance from point p to line l
	T dist(Point p) {return abs(side(p)) / abs(v);}

	/// squared distance from point p to lone l
	T sqDist(Point p) {return side(p) * side(p) / (double)sq(v);}

	/// To find a line perpendicular to line l and which goes through a certain point P
	line perPointhrough(Point p) {return {p, p + perp(v)};}

	/*given points on a line l, to sort them in the order they appear on the line,
	following the direction of #»v .*/

	/*In fact, this comparator is more powerful than we need: it is not limited to
	points on l and can compare two points by their orthogonal projection3 on l.*/
	bool cmpProj(Point p, Point q) {
		return dot(v, p) < dot(v, q);
	}

	/*If we want to translate a line l by vector #»t , the direction vector #»v remains
	the same but we have to adaPoint c.*/
	line translate(Point t) {return {v, c + cross(v, t)};}

	/*A closely related task is shifting line l to the left by a certain distance δ
	(or to the right by −δ).*/
	line shiftLeft(double dist) {return {v, c + dist * abs(v)};}

	/*The orthogonal projection of a point P on a line l is the point on l that is
	closest to P. The reflection of point P by line l is the point on the other side
	of l that is at the same distance and has the same orthogonal projection*/
	Point proj(Point p) {return p - perp(v) * side(p) / sq(v);}

	/*To find the reflection, we need to move P in the same direction but twice
	the distance:*/
	Point refl(Point p) {return p - perp(v) * 2 * side(p) / sq(v);}
};

// lines are represented as a ray from a point: (point, vector)
// returns false if two lines (p, v) && (q, w) are parallel or collinear
// true otherwise, intersection point is stored at o via reference
bool lineLineIntersection(Point p, Point v, Point q, Point w, Point& o) {
	static_assert(is_same<Tf, Ti>::value);
	if (dcmp(cross(v, w)) == 0) return false;
	Point u = p - q;
	o = p + v * (cross(w, u) / cross(v, w));
	return true;
}
// returns false if two lines p && q are parallel or collinear
// true otherwise, intersection point is stored at o via reference
// bool lineLineIntersection(line p, line q, Point& o) {
// 	return lineLineIntersection(p.a, p.b - p.a, q.a, q.b - q.a, o);
// }

/// distance between two parallal line l1, l2
T Dist(line l2, line l1) {return (l2.c - l1.c) / abs(l1.v);}

/// There is a unique intersection point between two lines l1 and l2 if and only if # »vl1 != »vl2
bool inter(line l1, line l2, Point &out) {
	T d = cross(l1.v, l2.v);
	if (d == 0) return false;
	out = (l2.v * l1.c - l1.v * l2.c) / d; // requires floating-point coordinates
	return true;
}

/*An important property of bisectors is that their points are at equal distances from the original lines l1 and l2. In fact, if we give a sign to the
	distance depending on which side of the line we are on, we can say that
	lint(l1, l2) is the line whose points are at opposite distances from l1 and l2
	while lext(l1, l2) is the line whose points are at equal distances from l1 and
	l2.*/
/// angle bisector line, if iteratior is 1 then return internal line otherwise external line...
line bisector(line l1, line l2, bool interior) {
	assert(cross(l1.v, l2.v) != 0); // l1 and l2 cannot be parallel!
	double sign = interior ? 1 : -1;
	return {l2.v / abs(l2.v) + l1.v / abs(l1.v) * sign,
	        l2.c / abs(l2.v) + l1.c / abs(l1.v) * sign};
}

/*For this we will first define a useful subroutine inDisk() that checks if
a point P lies on the disk of diameter [AB]. */
bool inDisk(Point a, Point b, Point p) {
	return dot(a - p, b - p) <= 0;
}

/// return true if point p is on segment AB
bool onSegment(Point a, Point b, Point p) {
	return orient(a, b, p) == 0 && inDisk(a, b, p);
}

/// segment segment intersection
bool properInter(Point a, Point b, Point c, Point d, Point &out) {
	double oa = orient(c, d, a),
	       ob = orient(c, d, b),
	       oc = orient(a, b, c),
	       od = orient(a, b, d);
	// Proper intersection exists iff opposite signs
	if (oa * ob < 0 && oc * od < 0) {
		out = (a * ob - b * oa) / (ob - oa);
		return true;
	}
	return false;
}

// To create sets of points we need a comparison function
struct cmpX {
	bool operator()(Point a, Point b) const {
		return make_pair(a.x, a.y) < make_pair(b.x, b.y);
	}
};

/// return all segment segment intersection point
set<Point, cmpX> inters(Point a, Point b, Point c, Point d) {
	Point out;
	if (properInter(a, b, c, d, out)) return {out};
	set<Point, cmpX> s;
	if (onSegment(c, d, a)) s.insert(a);
	if (onSegment(c, d, b)) s.insert(b);
	if (onSegment(a, b, c)) s.insert(c);
	if (onSegment(a, b, d)) s.insert(d);
	return s;
}

/// segment Point Distance from point p to segment AB
double segPoint(Point a, Point b, Point p) {
	if (a != b) {
		line l(a, b);
		if (l.cmpProj(a, p) && l.cmpProj(p, b)) // if closest to projection
			return l.dist(p); // output distance to line
	}
	return min(abs(p - a), abs(p - b)); // otherwise distance to A or B
}

/// Distance between to segment
double segSeg(Point a, Point b, Point c, Point d) {
	Point dummy;
	if (properInter(a, b, c, d, dummy))
		return 0;
	return min({segPoint(a, b, c), segPoint(a, b, d),
	            segPoint(c, d, a), segPoint(c, d, b)
	           });
}

/// area of a triangle
T areaTriangle(Point a, Point b, Point c) {
	return abs(cross(b - a, c - a)) / 2.0;
}

/* It
is good practice to always put your polygons in counter-clockwise order,
by reversing the array of vertices if necessary, because some algorithms on
polygons use this property.
picks theorem Area = (I + (B / 2) - 1);
*/
/// area of polygon... input is taken by vector
T areaPolygon(vector<Point> p) {
	T area = 0.0;
	for (int i = 0, n = p.size(); i < n; i++) {
		area += cross(p[i], p[(i + 1) % n]); // wrap back to 0 if i == n-1
	}
	return abs(area) / 2.0;
}

// true if P at least as high as Ray A (blue part)
bool above(Point a, Point p) {
	return p.y >= a.y;
}

// check if [PQ] crosses ray from A
bool crossesRay(Point a, Point p, Point q) {
	return (above(a, q) - above(a, p)) * orient(a, p, q) > 0;
}

// if strict, returns false when A is on the boundary
/// strict means Consider him inside if he is on the boundary of the polygon.
bool inPolygon(vector<Point> p, Point a, bool strict = true) {
	int numCrossings = 0;
	for (int i = 0, n = p.size(); i < n; i++) {
		if (onSegment(p[i], p[(i + 1) % n], a))
			return !strict;
		numCrossings += crossesRay(a, p[i], p[(i + 1) % n]);
	}
	return numCrossings & 1; // inside if odd number of crossings
}

struct Circle {
	Point o;
	T r;
	Circle(Point o = Point(0, 0), T r = 0) : o(o), r(r) {}

	// returns true if point p is in || on the circle
	bool contains(Point p) {
		return dcmp(sq(p - o) - r * r) <= 0;
	}

	// returns a point on the circle rad radians away from +X CCW
	Point point(Tf rad) {
		static_assert(is_same<Tf, Ti>::value);
		return Point(o.x + cos(rad) * r, o.y + sin(rad) * r);
	}

	// area of a circular sector with central angle rad
	T area(T rad = PI + PI) { return rad * r * r / 2; }

	/// area of the circular sector cut by a chord with central angle alpha
	/// https://math.libretexts.org/Bookshelves/Precalculus/Book%3A_Elementary_Trigonometry_(Corral)/04%3A_Radian_Measure/4.03%3A_Area_of_a_Sector
	T sector(T alpha) { return r * r * 0.5 * (alpha - sin(alpha)); }

	/// retrun the perameter of the circle
	T Perimeter() const {
		return 2 * PI * r;
	}
	bool operator==(const Circle& c) const {
		return o == c.o && abs(r - c.r) < EPS;
	}
};

/// given 3 points and return the center of of the new CircumCircle
Point circumCenter(Point a, Point b, Point c) { /// OK
	b = b - a, c = c - a; // consider coordinates relative to A
	assert(cross(b, c) != 0); // no circumcircle if A,B,C aligned
	return a + perp(b * sq(c) - c * sq(b)) / cross(b, c) / 2;
}

/// return the intersection point of circle and a line
int circleLine(Circle C, line l, pair<Point, Point> &out) {
	double h2 = C.r * C.r - l.sqDist(C.o);
	if (h2 >= 0) { // the line touches the circle
		Point p = l.proj(C.o); // point P
		Point h = l.v * sqrt(h2) / abs(l.v); // vector parallel to l, of length h
		out = {p - h, p + h};
	}
	return 1 + sgn(h2);
}

/*two circles (O1, r1) and (O2, r2) can have
either 0, 1, 2 or an infinity of intersection points (in case the circles are
identical).*/
int circleCircle(Point o1, double r1, Point o2, double r2, pair<Point, Point> &out) {
	Point d = o2 - o1; double d2 = sq(d);
	if (d2 == 0) {assert(r1 != r2); return 0;} // concentric circles
	double pd = (d2 + r1 * r1 - r2 * r2) / 2; // = |O_1P| * d
	double h2 = r1 * r1 - pd * pd / d2; // = hˆ2
	if (h2 >= 0) {
		Point p = o1 + d * pd / d2, h = perp(d) * sqrt(h2 / d2);
		out = {p - h, p + h};
	}
	return 1 + sgn(h2);
}

/*We say that a line is tangent to a circle if the intersection between them is
a single point. In this case, the ray going from the center to the intersection
point is perpendicular to the line.*/
int tangents(Point o1, double r1, Point o2, double r2, bool inner, vector <pair<Point, Point >> &out) {
	if (inner) r2 = -r2;
	Point d = o2 - o1;
	double dr = r1 - r2, d2 = sq(d), h2 = d2 - dr * dr;
	if (d2 == 0 || h2 < 0) {assert(h2 != 0); return 0;}
	for (double sign : { -1, 1}) {
		Point v = (d * dr + perp(d) * sqrt(h2) * sign) / d2;
		out.push_back({o1 + v * r1, o2 + v * r2});
	}
	return 1 + (h2 > 0);
}

int tangents(Circle C1, Circle C2, bool inner, vector <pair<Point, Point >> &out) {
	return tangents(C1.o, C1.r, C2.o, C2.r, inner, out);
}

typedef vector<Point> Polygon;
int convexHull(Polygon p, Polygon &ch) { /// OK
	sort(p.begin(), p.end());
	int n = p.size();
	ch.resize(n + n);
	int m = 0;    // preparing lower hull
	for (int i = 0; i < n; i++) {
		while (m > 1 && dcmp(cross(ch[m - 1] - ch[m - 2], p[i] - ch[m - 1])) <= 0) m--; /// sometime <
		ch[m++] = p[i];
	}
	int k = m;    // preparing upper hull
	for (int i = n - 2; i >= 0; i--) {
		while (m > k && dcmp(cross(ch[m - 1] - ch[m - 2], p[i] - ch[m - 2])) <= 0) m--; /// sometime <
		ch[m++] = p[i];
	}
	if (n > 1) m--;
	ch.resize(m);
	return m;
}

int main()
{
	Point a{3, 7}, b{13, 7}, c{8, 2}, d{9, 8}, xx;

	ll ans = 0;
	cout << a << " " << b << " " << c << endl; /// 1
	cout << abs(a) << endl; /// 2 Length

	cout << sgn(b.y) << endl; /// 3 Sign of b.y

	cout << translate(b, a) << endl; /// 4 Transation of vector a for every point of b

	cout << scale(c, 2, a) << endl; /// 5 Salling
	T alpha = radian(90);
	Point p = {3, 0};

	cout << rot(a, alpha) << endl; /// 6 Rotation vector v of angle alpha radian

	cout << perp(a) << endl; /// 7 Rotation 90* of vector a

	cout << linearTransfo(a, b, c, a, b) << endl; /// 8 Find last point of linearTransfo

	cout << isPerp(a, b) << endl; /// 9 Is vector a is perpendicular to vector b

	cout << angle(a, b) << endl; /// 10 angle between vector v and vector w

	cout << angle(a, b, 1) << endl; /// 11 sign angle between vector v and vector w

	cout << orient(a, b, c) << endl; /// 12 returns 1 if c is left of ab, 0 if on ab && -1 if right of ab

	cout << inAngle(a, b, c, p) << endl; /// 13 return 1 if point p is in angle CAB

	cout << degree(orientedAngle(a, b, c)) << endl; /// 14 angle between Orient AB and point C

	cout << isConvex({a, b, c}) << endl; /// 15 return 1 if given point is convex polygon

	line l1 = line({a, b});

	Point e{18, 2};

	cout << l1.side(e) << endl; /// 16

	cout << l1.dist(e) << endl; /// 17

	cout << l1.sqDist(e) << endl; /// 18

	line l2 = l1.perPointhrough(c);


	cout << l2.side(e) << endl; /// 19

	line paral2 = l2.translate(e - c); /// (e - c) because of line l2 is in c point, so c works at axix, so line in point(18, 0) to (18, inf)

	cout << paral2.side({18, 6}) << endl; /// 20

	line distt = paral2.shiftLeft(10);
	cout << l2.v << " " << distt.v << endl; /// 21 after shifting horil2 in left in 10 unit

	cout << Dist(paral2, l2) << endl; /// 22 line line distance

	Point intersention_point;

	cout << inter(l1, l2, intersention_point) << endl; /// 23 is line l1 and l2 intersected?
	cout << intersention_point << endl; /// 24 intersection point of line l1 and l2

	cout << l1.proj(c) << endl; /// 25 projection point from point c to line l1
	cout << l1.refl(c) << endl; /// 26 reflection point of point p with line l1

	cout << bisector(l1, l2, 1).v << endl; /// 27 internal or external Line of line l1 and l2
	cout << onSegment(a, b, intersention_point) << endl; /// 28 is point intersection on segment AB
	set<Point, cmpX> st = inters(a, b, intersention_point, b);
	for (auto it : st) cout << (it) << " ";
	cout << endl; /// 29 all SegmentSegment intersection point if(onSegment())
	cout << segPoint(a, b, p) << endl; /// 30 minimum distance from point p to segment ab
	cout << segSeg(a, b, c, e) << endl; /// 31 distance between two segment ab and ce

	cout << areaTriangle(a, b, c) << endl; /// 32 area of triangle

	cout << areaPolygon({a, b, c}) << endl; /// 33 area of polygon
	cout << inPolygon({a, b, c}, p, 0) << endl; /// 34 is point p inside the polygon

	Circle C({0, 0}, 2);

	cout << C.area(PI) << endl; /// 35 area of circle C with angle PI radian;
	cout << C.contains(p) << endl; /// 36 return 1 if poiint p is in || on circle C
	cout << C.point(PI) << endl; /// 37 returns a point on the circle rad radians away from +X CCW
	cout << C.sector(1.696) << endl; /// 38 area of the circular sector cut by a chord with central angle alpha

	Point center = circumCenter(a, b, c);
	cout << circumCenter(a, b, c) << endl; /// 39 center of new circle on point A, B, C
	T radius = abs(center - a);
	cout << radius << endl; /// 40 radius of new circle on ABC

	pair<Point, Point>in;

	Circle C1(c, 5 * sqrt(2.0));
	int numberof_intersection = circleLine(C1, l1, in); /// circle line intersection

	cout << in.first << " " << in.second << endl; /// 41 intersected points of line l in cirlce

	Polygon cv;
	int m = convexHull({a, b, c}, cv);

	for (auto x : cv) cout << x << endl; /// 42 - 44 generate convexhull

	Circle C2(a, 5);

	vector<pair<Point, Point>> inner_tangents, outter_tangents;

	tangents(C1, C2, 1, inner_tangents);
	tangents(C1, C2, 0, outter_tangents);

	for (auto x : inner_tangents) cout << x.first << " " << x.second << endl; /// 45 inner tangents points
	for (auto x : outter_tangents) cout << x.first << " " << x.second << endl; /// 46 outter tangents points

	return 0;
}