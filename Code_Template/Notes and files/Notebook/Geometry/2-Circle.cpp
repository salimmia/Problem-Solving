struct circle{
 PT p; Tf r;circle(){}circle(PT _p,Tf _r):p(_p),r(_r){};
 circle(Tf x,Tf y,Tf _r):p(PT(x,y)),r(_r){};
 circle(PT a,PT b,PT c){//circumcircle of a triangle
  b=(a+b)*0.5;c=(a+c)*0.5;
  line_line_intersection(b,b+rotatecw90(a-b),c,
   c+rotatecw90(a-c),p);r=dist(a,p);}
 circle(PT a,PT b,PT c,bool t){
  line u,v;//inscribed circle of a triangle
  Tf m=atan2(b.y-a.y,b.x-a.x), n=atan2(c.y-a.y,c.x-a.x);
  u.a=a;u.b=u.a+(PT(cos((n+m)/2.0), sin((n+m)/2.0)));
  v.a=b;m=atan2(a.y-b.y,a.x-b.x), n=atan2(c.y-b.y,c.x-b.x);
  v.b=v.a+(PT(cos((n+m)/2.0),sin((n+m)/2.0)));
  line_line_intersection(u.a,u.b,v.a,v.b,p);
  r=dist_from_point_to_seg(a,b,p);}
 bool operator==(circle v){return p==v.p && sign(r-v.r)==0;}
 Tf area(){return PI*r*r;}
 Tf circumference(){return 2.0*PI*r;}
};
int circle_point_relation(PT p,Tf r,PT b){
 Tf d=dist(p,b);if(sign(d-r)<0)return 2;
 if(sign(d-r)==0)return 1;return 0;}
//0 if outside,1 if on circumference,2 if inside circle
int circle_line_relation(PT p,Tf r,PT a,PT b){
 Tf d=dist_from_point_to_line(a,b,p);
 if(sign(d-r)<0)return 2;if(sign(d-r)==0)return 1;
 return 0;}
vector<PT>circle_line_intersection (PT c,Tf r,PT a,PT b){
 vector<PT>ret;b=b-a; a=a-c;Tf A=dot(b,b),B=dot(a,b);
 Tf C=dot(a,a)-r*r,D=B*B-A*C;if(D<-eps)return ret;
 ret.push_back(c+a+b*(-B+sqrt(D+eps))/A);
 if(D>eps)ret.push_back(c+a+b*(-B-sqrt(D))/A);
 return ret;}
int circle_circle_relation(PT a,Tf r,PT b,Tf R){
 Tf d=dist(a,b);//4-intersect outside in one point
 if(sign(d-r-R)>0)return 5;//3-intersect in 2 points
 if(sign(d-r-R)==0)return 4;// 5 no intersect
 Tf l=fabs(r-R);//2-intersect inside in one point
 if(sign(d-r-R)<0 && sign(d-l)>0)return 3;
 if(sign(d-l)==0)return 2;if(sign(d-l)<0)return 1;
 assert(0); return-1;}//1-inside and do not intersect
vector<PT>circle_circle_intersection (PT a,Tf r,PT b,Tf R){
 if(a==b && sign(r-R)==0)return{PT(1e18,1e18)};
 vector<PT>ret;Tf d=sqrt(dist2(a,b));
 if(d>r+R||d+min(r,R)<max(r,R))return ret;
 Tf x=(d*d-R*R+r*r)/(2*d);Tf y=sqrt(r*r-x*x);
 PT v=(b-a)/d;ret.push_back(a+v*x+rotateccw90(v)*y);
 if(y>0)ret.push_back(a+v*x-rotateccw90(v)*y);
 return ret;
}
int get_circle(PT a,PT b,Tf r,circle&c1,circle&c2){
 vector<PT>v=circle_circle_intersection(a,r,b,r);
 int t=v.size();if(!t)return 0;c1.p=v[0],c1.r=r;
 if(t==2)c2.p=v[1],c2.r=r;return t;
}
//returns two circle c1,c2 which is tangent to line u,goes through
//point q and has radius r1;0 for no circle,1 if c1=c2 ,2 if c1 !=c2
int get_circle(line u,PT q,Tf r1, circle&c1,circle&c2){
 Tf d=dist_from_point_to_line(u.a,u.b,q);
 if(sign(d-r1*2.0)>0)return 0;
 if(sign(d)==0){cout<< u.v.x<< ' '<< u.v.y<< '\n';
  c1.p=q+rotateccw90(u.v).truncate(r1);
  c2.p=q+rotatecw90(u.v).truncate(r1);
  c1.r=c2.r=r1;return 2;
}
 line u1=line(u.a+rotateccw90(u.v).truncate(r1), u.b+rotateccw90(u.v).truncate(r1));
 line u2=line(u.a+rotatecw90(u.v).truncate(r1), u.b+rotatecw90(u.v).truncate(r1));
 circle cc=circle(q,r1);PT p1,p2; vector<PT>v;
 v=circle_line_intersection(q,r1,u1.a,u1.b);
 if(!v.size()) v = circle_line_intersection(q,r1,u2.a,u2.b);
 v.push_back(v[0]);p1=v[0],p2=v[1];c1=circle(p1,r1);
 if(p1==p2){c2=c1;return 1;}c2=circle(p2,r1);
 return 2;
}
Tf circle_circle_area(PT a,Tf r1,PT b,Tf r2){
 Tf d=(a-b).norm();if(r1+r2<d+eps)return 0;
 if(r1+d<r2+eps)return PI*r1*r1;
 if(r2+d<r1+eps)return PI*r2*r2;
 Tf theta_1=acos((r1*r1+d*d-r2*r2)/(2*r1*d)),
 theta_2=acos((r2*r2+d*d-r1*r1)/(2*r2*d));
 return r1*r1*(theta_1-sin(2*theta_1)/2.)+ r2*r2*(theta_2-sin(2*theta_2)/2.);
}
//tangent lines from point q to the circle
int tangent_lines_from_point(PT p,Tf r,PT q,line&u,line&v){
 int x=sign(dist2(p,q)-r*r);
 if(x<0)return 0;//point in cricle
 if(x==0){//point on circle
 u=line(q,q+rotateccw90(q-p));v=u;return 1;
}Tf d=dist(p,q);Tf l=r*r/d;Tf h=sqrt(r*r-l*l);
u=line(q,p+((q-p).truncate(l)+ (rotateccw90(q-p).truncate(h))));
v=line(q,p+((q-p).truncate(l)+ (rotatecw90(q-p).truncate(h))));
return 2;
}
//returns outer tangents line of two circles
//if inner==1 it returns inner tangent lines
int tangents_lines_from_circle(PT c1,Tf r1,PT c2,Tf r2,bool inner,line&u,line&v){
 if(inner)r2 =-r2;PT d=c2-c1;Tf dr=r1-r2,d2=d.norm(),
 h2=d2-dr*dr;if(d2==0||h2<0){assert(h2 != 0);return 0;
}vector<pair<PT,PT>>out;for(int tmp :{-1,1}){
  PT v=(d*dr+rotateccw90(d)*sqrt(h2)*tmp)/d2;
  out.push_back({c1+v*r1,c2+v*r2});}
 u=line(out[0].first,out[0].second);
 if(out.size()==2)v=line(out[1].first,out[1].second);
 return 1+(h2>0);
}
