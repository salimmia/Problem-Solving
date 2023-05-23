typedef double Tf;const Tf inf=1e100;
const Tf eps=1e-9;const Tf PI=acos((double)-1.0);
int sign(Tf x){return(x>eps)-(x<-eps);}
struct PT{Tf x,y;
 PT(){x=0,y=0;}PT(Tf x,Tf y):x(x),y(y){}
 PT(const PT&p):x(p.x),y(p.y){}
 PT operator+(const PT&a)const{return PT(x+a.x,y+a.y);}
 PT operator-(const PT&a)const{return PT(x-a.x,y-a.y);}
 PT operator*(const Tf a)const{return PT(x*a,y*a);}
 friend PT operator*(const double&a,const PT&b){return PT(a*b.x,a*b.y);}
 PT operator/(const Tf a)const{return PT(x/a,y/a);}
 bool operator==(PT a)const{return sign(a.x-x)==0 && sign(a.y-y)==0;}
 bool operator!=(PT a)const{return !(*this==a);}
 bool operator<(PT a)const{return sign(a.x-x)==0?y<a.y:x<a.x;}
 bool operator>(PT a)const{return sign(a.x-x)==0?y>a.y:x>a.x;}
 Tf norm(){return sqrt(x*x+y*y);}
 Tf norm2(){return x*x+y*y;}PT perp(){return PT(-y,x);}
 Tf arg(){Tf x=atan2(y,x); return x;}
 PT truncate(Tf r){Tf k=norm();//returns a vector with norm r and having same direction
  if(!sign(k))return*this;r/=k;return PT(x*r,y*r);}
 friend istream&operator>>(istream&is,PT&p){return is >> p.x >> p.y;}
 friend ostream&operator<<(ostream&os,const PT&p){return os<< p.x<< " "<< p.y;}
}; /// I = inline hbe
Tf dot(PT a,PT b){return a.x*b.x+a.y*b.y;} //I
Tf dist2(PT a,PT b){return dot(a-b,a-b);}//I
Tf dist(PT a,PT b){return sqrt(dot(a-b,a-b));}//I
Tf cross(PT a,PT b){return a.x*b.y-a.y*b.x;}//I
Tf cross2(PT a,PT b,PT c){return cross(b-a,c-a);}//I
int orientation(PT a,PT b,PT c){return sign(cross(b-a,c-a));}//I
PT perp(PT a){return PT(-a.y,a.x);}
PT rotateccw90(PT a){return PT(-a.y,a.x);}
PT rotatecw90(PT a){return PT(a.y,-a.x);}
PT rotateccw(PT a,Tf t){return PT(a.x*cos(t)-a.y*sin(t),a.x*sin(t)+a.y*cos(t));}
PT rotatecw(PT a,Tf t){return PT(a.x*cos(t)+a.y*sin(t),-a.x*sin(t)+a.y*cos(t));}
Tf SQ(Tf x){return x*x;}
Tf rad_to_deg(Tf r){return(r*180.0/PI);}Tf deg_to_rad
(Tf d){return(d*PI/180.0);} Tf get_angle(PT a,PT b){
 Tf costheta=dot(a,b)/a.norm()/b.norm();
 return acos(max((double)-1.0,min((double)1.0,costheta)));}
bool is_point_in_angle(PT b,PT a,PT c,PT p){//<bac
 assert(orientation(a,b,c)!= 0);
 if(orientation(a,c,b)<0)swap(b,c);
 return orientation(a,c,p)>= 0 && orientation(a,b,p)<= 0;}
bool half(PT p){return p.y>0.0||(p.y==0.0&&p.x<0.0);}
void polar_sort(vector<PT>&v){
 sort(v.begin(),v.end(),[](PT a,PT b){
  return make_tuple(half(a),0.0,a.norm2())<make_tuple
  (half(b),cross(a,b),b.norm2());});}
struct line{
PT a,b;//goes through points a and b
PT v; Tf c;line(){}//direction vector v and offset c
line(PT v,Tf c):v(v),c(c){auto p=get_points();
 a=p.first; b=p.second;}
line(Tf _a,Tf _b,Tf _c):v({_b,-_a}),c(-_c){
 auto p=get_points();a=p.first; b=p.second;}
line(PT p,PT q):v(q-p),c(cross(v,p)),a(p),b(q){}
//extract any two points from this line
pair<PT,PT>get_points(){PT p,q; Tf a =-v.y,b=v.x;
if(sign(a)==0){p=PT(0,c/b);q=PT(1,c/b);}
else if(sign(b)==0){p=PT(c/a,0);q=PT(c/a,1);}
else{p=PT(0,c/b);q=PT(1,(c-a)/b);}return{p,q};}
//ax+by+c=0
array<double,3>get_abc(){
 Tf a =-v.y,b=v.x;return{a,b,c};}
//1 if on the left,-1 if on the right,0 if on the line
int side(PT p){return sign(cross(v,p)-c);}//+1L,-1R,o0
line perpendicular_through(PT p){return{p,p+perp(v)};}
line translate(PT t){return{v,c+cross(v,t)};}
//compare two points by their orthogonal projection on this line
//a projection point comes before another if it comes first according to vector v
bool cmp_by_projection(PT p,PT q){return dot(v,p)<dot(v,q);}
line shift_left(Tf d){PT z=v.perp().truncate(d);
 return line(a+z,b+z);}};
PT point_along_line(PT a,PT b,Tf d){
 return a+(((b-a)/(b-a).norm())*d);}
PT project_from_point_to_line(PT a,PT b,PT c){//lineAB
 return a+(b-a)*dot(c-a,b-a)/(b-a).norm2();}
PT reflection_from_point_to_line(PT a,PT b,PT c){
 PT p=project_from_point_to_line(a,b,c);
 return point_along_line(c,p,2.0*dist(c,p));}
Tf dist_from_point_to_line(PT a,PT b,PT c){//lineAB
 return fabs(cross(b-a,c-a)/(b-a).norm());}
bool is_point_on_seg(PT a,PT b,PT p){//lineAB
 if(fabs(cross(p-b,a-b))<eps){
  if(p.x<min(a.x,b.x)||p.x>max(a.x,b.x))return false;
  if(p.y<min(a.y,b.y)||p.y>max(a.y,b.y))return false;
  return true;}return false;}
PT project_from_point_to_seg(PT a,PT b,PT c){//segAB
 Tf r=dist2(a,b);if(fabs(r)<eps)return a;
 r=dot(c-a,b-a)/r;if(r<0)return a;if(r>1)return b;
 return a+(b-a)*r;}
Tf dist_from_point_to_seg(PT a,PT b,PT c){//segAB
 return dist(c,project_from_point_to_seg(a,b,c));}
bool is_parallel(PT a,PT b,PT c,PT d){//1Y,0N
 Tf k=fabs(cross(b-a,d-c));//2 collinear
 if(k<eps){if(fabs(cross(a-b,a-c))<eps && 
  fabs(cross(c-d,c-a))<eps)return 2;else return 1;}
 else return 0;}
bool are_lines_same(PT a,PT b,PT c,PT d){
 if(fabs(cross(a-c,c-d))<eps && fabs
  (cross(b-c,c-d))<eps)return true;return false;}
PT angle_bisector(PT&a,PT&b,PT&c){///<abc
 PT p=a-b,q=c-b;return p+q*sqrt(dot(p,p)/dot(q,q));}
bool line_line_intersection(PT a,PT b,PT c,PT d,PT&ans){
 Tf a1=a.y-b.y,b1=b.x-a.x,c1=cross(a,b);
 Tf a2=c.y-d.y,b2=d.x-c.x,c2=cross(c,d);
 Tf det=a1*b2-a2*b1;if(det==0)return 0;
 ans=PT((b1*c2-b2*c1)/det,(c1*a2-a1*c2)/det);
 return 1;}
bool seg_seg_intersection(PT a,PT b,PT c,PT d,PT&ans){
 Tf oa=cross2(c,d,a),ob=cross2(c,d,b);
 Tf oc=cross2(a,b,c),od=cross2(a,b,d);
 if(oa*ob<0 && oc*od<0){ans=(a*ob-b*oa)/(ob-oa);
  return 1;}else return 0;}
set<PT>seg_seg_intersection_inside(PT a,PT b,PT c,PT d){
 PT ans;//se.size()== 0 = no, 1 = one, 2 = two;
 if(seg_seg_intersection(a,b,c,d,ans))return{ans};
 set<PT>se;if(is_point_on_seg(c,d,a))se.insert(a);
 if(is_point_on_seg(c,d,b))se.insert(b);
 if(is_point_on_seg(a,b,c))se.insert(c);
 if(is_point_on_seg(a,b,d))se.insert(d);return se;}
int seg_line_relation(PT a,PT b,PT c,PT d){//lineAB
 Tf p=cross2(c,d,a);Tf q=cross2(c,d,b);//segCD
 if(sign(p)==0 && sign(q)==0)return 2;
 else if(p*q<= 0)return 1;else return 0;}
//intersection between segament ab and line cd assuming unique intersection exists
bool seg_line_intersection(PT a,PT b,PT c,PT d,PT&ans){
 bool k=seg_line_relation(a,b,c,d);assert(k != 2);
 if(k)line_line_intersection(a,b,c,d,ans);return k;}
//minimum distance from segment ab to segment cd
Tf dist_from_seg_to_seg(PT a,PT b,PT c,PT d){
 PT dummy;
 if(seg_seg_intersection(a,b,c,d,dummy))return 0.0;
 else return min({dist_from_point_to_seg(a,b,c),dist_from_point_to_seg(a,b,d),
  dist_from_point_to_seg(c,d,a),dist_from_point_to_seg(c,d,b)
});}
Tf dist_from_point_to_ray(PT a,PT b,PT c){//rayAB>B
 b=a+b;Tf r=dot(c-a,b-a);if(r<0.0)return dist(c,a);
 return dist_from_point_to_line(a,b,c);}
//starting point as and direction vector ad
bool ray_ray_intersection(PT as,PT ad,PT bs,PT bd){
 Tf dx=bs.x-as.x,dy=bs.y-as.y;
 Tf det=bd.x*ad.y-bd.y*ad.x;if(fabs(det)<eps)
 return 0;Tf u=(dy*bd.x-dx*bd.y)/det;
 Tf v=(dy*ad.x-dx*ad.y)/det;
 if(sign(u)>=0&&sign(v)>= 0)return 1;return 0;}
Tf ray_ray_distance(PT as,PT ad,PT bs,PT bd){
 if(ray_ray_intersection(as,ad,bs,bd))return 0.0;
 Tf ans=dist_from_point_to_ray(as,ad,bs);
 ans=min(ans,dist_from_point_to_ray(bs,bd,as));
 return ans;}
