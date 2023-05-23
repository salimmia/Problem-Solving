double area_of_triangle(PT a,PT b,PT c){ 
 return fabs(cross(b-a,c-a) *0.5);
}
//-1 if strictly inside,0 if on the polygon,1 if strictly outside
int is_point_in_triangle(PT a,PT b,PT c,PT p){ 
 if(sign(cross(b-a,c-a)) <0) swap(b,c);
 int c1=sign(cross(b-a,p-a));
 int c2=sign(cross(c-b,p-b));
 int c3=sign(cross(a-c,p-c));
 if(c1<0 || c2<0 || c3<0) return 1;
 if(c1+c2+c3 !=3) return 0;
 return-1;
}
double perimeter(vector<PT>&p){ 
 double ans=0;int n=p.size();
 for(int i=0;i<n;i++) ans+=dist(p[i],p[(i+1) % n]);
  return ans;
}
double area(vector<PT>&p){ 
 double ans=0;int n=p.size();
 for(int i=0;i<n;i++) ans+=cross(p[i],p[(i+1) % n]);
  return fabs(ans) *0.5;
}
//centroid of a(possibly non-convex) polygon,
//assuming that the coordinates are listed in a clockwise or
//counterclockwise fashion.  Note that the centroid is often known as
//the "center of gravity" or "center of mass".
PT centroid(vector<PT>&p){ 
 int n=p.size();PT c(0,0);
 double sum=0;
 for(int i=0;i<n;i++) sum+=cross(p[i],p[(i+1) % n]);
  double scale=3.0*sum;
 for(int i=0;i<n;i++){ 
  int j=(i+1) % n;
  c=c+(p[i]+p[j]) *cross(p[i],p[j]);
 }
 return c/scale;
}
//0 if cw,1 if ccw
bool get_direction(vector<PT>&p){ 
 double ans=0;int n=p.size();
 for(int i=0;i<n;i++) ans+=cross(p[i],p[(i+1) % n]);
  if(sign(ans) >0) return 1;
 return 0;
}
//it returns a point such that the sum of distances
//from that point to all points in p  is minimum//O(n log^2 MX) 
PT geometric_median(vector<PT>p){ 
 auto tot_dist=[&](PT z){ 
  double res=0;
  for(int i=0;i<p.size();i++) res+=dist(p[i],z);
   return res;
 };
 auto findY=[&](double x){ 
  double yl=-1e5,yr=1e5;
  for(int i=0;i<60;i++){ 
   double ym1=yl+(yr-yl) /3;
   double ym2=yr-(yr-yl) /3;
   double d1=tot_dist(PT(x,ym1));
   double d2=tot_dist(PT(x,ym2));
   if(d1<d2) yr=ym2;
   else yl=ym1;
  }
  return pair<double,double>(yl,tot_dist(PT(x,yl)));
 };
 double xl=-1e5,xr=1e5;
 for(int i=0;i<60;i++){ 
  double xm1=xl+(xr-xl) /3;
  double xm2=xr-(xr-xl) /3;
  double y1,d1,y2,d2;
  auto z=findY(xm1);y1=z.first;d1=z.second;
  z=findY(xm2);y2=z.first;d2=z.second;
  if(d1<d2) xr=xm2;
  else xl=xm1;
 }
 return{ xl,findY(xl).first};
}
vector<PT>convex_hull(vector<PT>&p){ 
 if(p.size() <=1) return p;
 vector<PT>v=p;
 sort(v.begin() ,v.end());
 vector<PT>up,dn;
 for(auto&p:v){ 
  while(up.size() >1&&orientation(up[up.size() -2],up.back() ,p) >=0){ 
   up.pop_back();
  }
  while(dn.size() >1&&orientation(dn[dn.size() -2],dn.back() ,p) <=0){ 
   dn.pop_back();
  }
  up.push_back(p);
  dn.push_back(p);
 }
 v=dn;
 if(v.size() >1) v.pop_back();
 reverse(up.begin() ,up.end());
 up.pop_back();
 for(auto&p:up){ 
  v.push_back(p);
 }
 if(v.size() ==2&&v[0]==v[1]) v.pop_back();
 return v;
}
//checks if convex or not
bool is_convex(vector<PT>&p){ 
 bool s[3];s[0]=s[1]=s[2]=0;
 int n=p.size();
 for(int i=0;i<n;i++){ 
  int j=(i+1) % n;
  int k=(j+1) % n;
  s[sign(cross(p[j]-p[i],p[k]-p[i])) +1]=1;
  if(s[0]&&s[2]) return 0;
 }
 return 1;
}
//-1 if strictly inside,0 if on the polygon,1 if strictly outside
//it must be strictly convex,otherwise make it strictly convex first
int is_point_in_convex(vector<PT>&p,const PT&x){ //O(log n) 
 int n=p.size();assert(n>=3);
 int a=orientation(p[0],p[1],x) ,b=orientation(p[0],p[n-1],x);
 if(a<0 || b>0) return 1;
 int l=1,r=n-1;
 while(l+1<r){ 
  int mid=l+r>>1;
  if(orientation(p[0],p[mid],x) >=0) l=mid;
  else r=mid;
 }
 int k=orientation(p[l],p[r],x);
 if(k<=0) return-k;
 if(l==1&&a==0) return 0;
 if(r==n-1&&b==0) return 0;
 return-1;
}
bool is_point_on_polygon(vector<PT>&p,const PT&z){ 
 int n=p.size();
 for(int i=0;i<n;i++){ 
  if(is_point_on_seg(p[i],p[(i+1) % n],z)) return 1;
 }
 return 0;
}
//returns 1e9 if the point is on the polygon
int winding_number(vector<PT>&p,const PT&z){ //O(n) 
 if(is_point_on_polygon(p,z)) return 1e9;
 int n=p.size() ,ans=0;
 for(int i=0;i<n;++i){ 
  int j=(i+1) % n;
  bool below=p[i].y<z.y;
  if(below !=(p[j].y<z.y)){ 
   auto orient=orientation(z,p[j],p[i]);
   if(orient==0) return 0;
   if(below==(orient>0)) ans+=below?1:-1;
  }
 }
 return ans;
}
//-1 if strictly inside,0 if on the polygon,1 if strictly outside
int is_point_in_polygon(vector<PT>&p,const PT&z){ //O(n) 
 int k=winding_number(p,z);
 return k==1e9?0:k==0?1:-1;
}
//id of the vertex having maximum dot product with z
//polygon must need to be convex
//top-upper right vertex
//for minimum dot prouct negate z and return-dot(z,p[id]) 
int extreme_vertex(vector<PT>&p,const PT&z,const int top){ //O(log n) ///not tested
 int n=p.size();
 if(n==1) return 0;
 double ans=dot(p[0],z);int id=0;
 if(dot(p[top],z) >ans) ans=dot(p[top],z) ,id=top;
 int l=1,r=top-1;
 while(l<r){ 
  int mid=l+r>>1;
  if(dot(p[mid+1],z) >=dot(p[mid],z)) l=mid+1;
  else r=mid;
 }
 if(dot(p[l],z) >ans) ans=dot(p[l],z) ,id=l;
 l=top+1,r=n-1;
 while(l<r){ 
  int mid=l+r>>1;
  if(dot(p[(mid+1) % n],z) >=dot(p[mid],z)) l=mid+1;
  else r=mid;
 }
 l %=n;
 if(dot(p[l],z) >ans) ans=dot(p[l],z) ,id=l;
 return id;
}
double diameter(vector<PT>&p){ 
 int n=(int) p.size();
 if(n==1) return 0;
 if(n==2) return dist(p[0],p[1]);
 double ans=0;
 int i=0,j=1;
 while(i<n){ 
  while(cross(p[(i+1) % n]-p[i],p[(j+1) % n]-p[j]) >=0){ 
   ans=max(ans,dist2(p[i],p[j]));
   j=(j+1) % n;
  }
  ans=max(ans,dist2(p[i],p[j]));
  i++;
 }
 return sqrt(ans);
}
double width(vector<PT>&p){ 
 int n=(int) p.size();
 if(n<=2) return 0;
 double ans=inf;
 int i=0,j=1;
 while(i<n){ 
  while(cross(p[(i+1) % n]-p[i],p[(j+1) % n]-p[j]) >=0) j=(j+1) % n;
  ans=min(ans,dist_from_point_to_line(p[i],p[(i+1) % n],p[j]));
  i++;
 }
 return ans;
}
//minimum perimeter
double minimum_enclosing_rectangle(vector<PT>&p){ 
 int n=p.size();
 if(n<=2) return perimeter(p);
 int mndot=0;double tmp=dot(p[1]-p[0],p[0]);
 for(int i=1;i<n;i++){ 
  if(dot(p[1]-p[0],p[i]) <=tmp){ 
   tmp=dot(p[1]-p[0],p[i]);
   mndot=i;
  }
 }
 double ans=inf;
 int i=0,j=1,mxdot=1;
 while(i<n){ 
  PT cur=p[(i+1) % n]-p[i];
  while(cross(cur,p[(j+1) % n]-p[j]) >=0) j=(j+1) % n;
  while(dot(p[(mxdot+1) % n],cur) >=dot(p[mxdot],cur)) mxdot=(mxdot+1) % n;
  while(dot(p[(mndot+1) % n],cur) <=dot(p[mndot],cur)) mndot=(mndot+1) % n;
  ans=min(ans,2.0*((dot(p[mxdot],cur) /cur.norm() -dot(p[mndot],cur) /cur.norm()) +dist_from_point_to_line(p[i],p[(i+1) % n],p[j])));
  i++;
 }
 return ans;
}