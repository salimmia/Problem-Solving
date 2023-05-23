struct line {
 PT a, b; //goes through points a and b
 PT v; double c; //lineForm:directionVec[cross](x,y) =c
 line() { }
 //direction vector v and offset c
 line(PT v, double c) : v(v) , c(c) {
  auto p = get_points();
  a = p.first; b = p.second;
 }
 //equation ax+by+c=0
 line(double _a, double _b, double _c) : v( { _b, -_a}) , c(-_c) {
  auto p = get_points();
  a = p.first; b = p.second;
 }
 //goes through points p and q
 line(PT p, PT q) : v(q - p) , c(cross(v, p)) , a(p) , b(q) {}
 //extract any two points from this line
 pair<PT, PT>get_points() {
  PT p, q; double a = -v.y, b = v.x; //ax+by=c
  if (sign(a) == 0) {
   p = PT(0, c / b);
   q = PT(1, c / b);
  }
  else if (sign(b) == 0) {
   p = PT(c / a, 0);
   q = PT(c / a, 1);
  }
  else {
   p = PT(0, c / b);
   q = PT(1, (c - a) / b);
  }
  return{ p, q};
 }
 //ax+by+c=0
 array<double, 3>get_abc() {
  double a = -v.y, b = v.x;
  return{ a, b, c};
 }
 //1 if on the left,-1 if on the right,0 if on the line
 int side(PT p) { return sign(cross(v, p) - c);}
 //line that is perpendicular to this and goes through point p
 line perpendicular_through(PT p) { return{ p, p + perp(v) };}
 //translate the line by vector t i.e. shifting it by vector t
 line translate(PT t) { return{ v, c + cross(v, t) };}
 //compare two points by their orthogonal projection on this line
 //a projection point comes before another if it comes first according to vector v
 bool cmp_by_projection(PT p, PT q) { return dot(v, p) < dot(v, q);}
 line shift_left(double d) {
  PT z = v.perp().truncate(d);
  return line(a + z, b + z);
 }
};
//find a point from a through b with distance d
PT point_along_line(PT a, PT b, double d) {
 return a + (((b - a) / (b - a).norm()) * d);
}
//projection point c onto line through a and b  assuming a !=b
PT project_from_point_to_line(PT a, PT b, PT c) {
 return a + (b - a) * dot(c - a, b - a) / (b - a).norm2();
}
//reflection point c onto line through a and b  assuming a !=b
PT reflection_from_point_to_line(PT a, PT b, PT c) {
 PT p = project_from_point_to_line(a, b, c);
 return point_along_line(c, p, 2.0 * dist(c, p));
}
//minimum distance from point c to line through a and b
double dist_from_point_to_line(PT a, PT b, PT c) {
 return fabs(cross(b - a, c - a) / (b - a).norm());
}
//returns true if  point p is on line segment ab
bool is_point_on_seg(PT a, PT b, PT p) {
 if (fabs(cross(p - b, a - b)) < eps) {
  if (p.x < min(a.x, b.x) || p.x > max(a.x, b.x)) return false;
  if (p.y < min(a.y, b.y) || p.y > max(a.y, b.y)) return false;
  return true;
 }
 return false;
}
//minimum distance point from point c to segment ab that lies on segment ab
PT project_from_point_to_seg(PT a, PT b, PT c) {
 double r = dist2(a, b);
 if (fabs(r) < eps) return a;
 r = dot(c - a, b - a) / r;
 if (r < 0) return a;
 if (r > 1) return b;
 return a + (b - a) * r;
}
//minimum distance from point c to segment ab
double dist_from_point_to_seg(PT a, PT b, PT c) {
 return dist(c, project_from_point_to_seg(a, b, c));
}
//0 if not parallel,1 if parallel,2 if collinear
bool is_parallel(PT a, PT b, PT c, PT d) {
 double k = fabs(cross(b - a, d - c));
 if (k < eps) {
  if (fabs(cross(a - b, a - c)) < eps && fabs(cross(c - d, c - a)) < eps) return 2;
  else return 1;
 }
 else return 0;
}
//check if two lines are same
bool are_lines_same(PT a, PT b, PT c, PT d) {
 if (fabs(cross(a - c, c - d)) < eps && fabs(cross(b - c, c - d)) < eps) return true;
 return false;
}
//bisector vector of<abc
PT angle_bisector(PT&a, PT&b, PT&c) {
 PT p = a - b, q = c - b;
 return p + q * sqrt(dot(p, p) / dot(q, q));
}
//1 if point is ccw to the line,2 if point is cw to the line,3 if point is on the line
int point_line_relation(PT a, PT b, PT p) {
 int c = sign(cross(p - a, b - a));
 if (c < 0) return 1;
 if (c > 0) return 2;
 return 3;
}
//intersection point between ab and cd assuming unique intersection exists
bool line_line_intersection(PT a, PT b, PT c, PT d, PT&ans) {
 double a1 = a.y - b.y, b1 = b.x - a.x, c1 = cross(a, b);
 double a2 = c.y - d.y, b2 = d.x - c.x, c2 = cross(c, d);
 double det = a1 * b2 - a2 * b1;
 if (det == 0) return 0;
 ans = PT((b1 * c2 - b2 * c1) / det, (c1 * a2 - a1 * c2) / det);
 return 1;
}
//intersection point between segment ab and segment cd assuming unique intersection exists
bool seg_seg_intersection(PT a, PT b, PT c, PT d, PT&ans) {
 double oa = cross2(c, d, a) , ob = cross2(c, d, b);
 double oc = cross2(a, b, c) , od = cross2(a, b, d);
 if (oa * ob < 0 && oc * od < 0) {
  ans = (a * ob - b * oa) / (ob - oa);
  return 1;
 }
 else return 0;
}
/*intersection point between segment ab and segment
cd assuming unique intersection may not exists*/
//se.size() ==0 means no intersection
//se.size() ==1 means one intersection
//se.size() ==2 means range intersection
set<PT>seg_seg_intersection_inside(PT a, PT b, PT c, PT d) {
 PT ans;
 if (seg_seg_intersection(a, b, c, d, ans)) return{ ans};
 set<PT>se;
 if (is_point_on_seg(c, d, a)) se.insert(a);
 if (is_point_on_seg(c, d, b)) se.insert(b);
 if (is_point_on_seg(a, b, c)) se.insert(c);
 if (is_point_on_seg(a, b, d)) se.insert(d);
 return se;
}
//intersection  between segment ab and line cd
//0 if do not intersect,1 if proper intersect,2 if segment intersect
int seg_line_relation(PT a, PT b, PT c, PT d) {
 double p = cross2(c, d, a);
 double q = cross2(c, d, b);
 if (sign(p) == 0 && sign(q) == 0) return 2;
 else if (p * q <= 0) return 1;
 else return 0;
}
//intersection between segament ab and line cd assuming unique intersection exists
bool seg_line_intersection(PT a, PT b, PT c, PT d, PT&ans) {
 bool k = seg_line_relation(a, b, c, d);
 assert(k != 2);
 if (k) line_line_intersection(a, b, c, d, ans);
 return k;
}
//minimum distance from segment ab to segment cd
double dist_from_seg_to_seg(PT a, PT b, PT c, PT d) {
 PT dummy;
 if (seg_seg_intersection(a, b, c, d, dummy)) return 0.0;
 else return min({ dist_from_point_to_seg(a, b, c) , dist_from_point_to_seg(a, b, d) ,
  dist_from_point_to_seg(c, d, a) , dist_from_point_to_seg(c, d, b)
 });
}
//minimum distance from point c to ray(starting point a and direction vector b)
double dist_from_point_to_ray(PT a, PT b, PT c) {
 b = a + b;
 double r = dot(c - a, b - a);
 if (r < 0.0) return dist(c, a);
 return dist_from_point_to_line(a, b, c);
}
//starting point as and direction vector ad
bool ray_ray_intersection(PT as, PT ad, PT bs, PT bd) {
 double dx = bs.x - as.x, dy = bs.y - as.y;
 double det = bd.x * ad.y - bd.y * ad.x;
 if (fabs(det) < eps) return 0;
 double u = (dy * bd.x - dx * bd.y) / det;
 double v = (dy * ad.x - dx * ad.y) / det;
 if (sign(u) >= 0 && sign(v) >= 0) return 1;
 else return 0;
}
double ray_ray_distance(PT as, PT ad, PT bs, PT bd) {
 if (ray_ray_intersection(as, ad, bs, bd)) return 0.0;
 double ans = dist_from_point_to_ray(as, ad, bs);
 ans = min(ans, dist_from_point_to_ray(bs, bd, as));
 return ans;
}