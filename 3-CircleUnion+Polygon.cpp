//O(n^2 log n)
struct CircleUnion{///OK
 int n, covered[2020];Tf x[2020],y[2020],r[2020];
 vector<pair<double,double>>seg,cover;Tf arc,pol;
 inline int sign(Tf x){return x<-eps ?-1:x>eps;}
 inline int sign(Tf x,Tf y){return sign(x-y);}
 inline Tf SQ(const Tf x){return x*x;}
 inline Tf dist(Tf x1,Tf y1,Tf x2,Tf y2){return sqrt(SQ(x1-x2)+SQ(y1-y2));}
 inline Tf angle(Tf A,Tf B,Tf C){
  Tf val=(SQ(A)+SQ(B)-SQ(C))/(2*A*B);
  if(val<-1)val =-1;if(val >+1)val =+1;
  return acos(val);}CircleUnion(){
  n=0; seg.clear(),cover.clear(); arc=pol=0;}
 void init(){n=0;seg.clear(),cover.clear();
  arc=pol=0;}void add(Tf xx,Tf yy,Tf rr){
  x[n]=xx,y[n]=yy,r[n]=rr,covered[n]=0,n++;}
 void getarea(int i,Tf lef,Tf rig){
  arc+= 0.5*r[i]*r[i]*(rig-lef-sin(rig-lef));
  Tf x1=x[i]+r[i]*cos(lef),y1=y[i]+r[i]*sin(lef);
  Tf x2=x[i]+r[i]*cos(rig),y2=y[i]+r[i]*sin(rig);
  pol+= x1*y2-x2*y1;}
 Tf circle_solve(){
  for(int i=0; i<n; i++){for(int j=0; j<i; j++){
    if(!sign(x[i]-x[j])&& !sign(y[i]-y[j])&& !sign(r[i]-r[j])){
     r[i]=0.0;break;}}}
  for(int i=0; i<n; i++){for(int j=0; j<n; j++){
    if(i != j && sign(r[j]-r[i])>= 0 && sign(dist(x[i],y[i],x[j],y[j])-(r[j]-r[i]))<= 0){
     covered[i]=1;break;}}}for(int i=0; i<n; i++){
   if(sign(r[i])&& !covered[i]){seg.clear();
    for(int j=0; j<n; j++){if(i != j){
      Tf d=dist(x[i],y[i],x[j],y[j]);
      if(sign(d-(r[j]+r[i]))>= 0||
       sign(d-abs(r[j]-r[i]))<= 0){continue;}
      Tf alpha=atan2(y[j]-y[i],x[j]-x[i]);
      Tf beta=angle(r[i],d,r[j]);
      pair<double,double>tmp(alpha-beta,alpha+beta);
      if(sign(tmp.first)<= 0 && sign(tmp.second)<= 0){
       seg.push_back(pair<double,double> (2*PI+tmp.first,2*PI+tmp.second));}
      else if(sign(tmp.first)<0){
       seg.push_back(pair<double,double>(2*PI+tmp.first,2*PI));
       seg.push_back(pair<double,double>(0,tmp.second));}
      else seg.push_back(tmp);}}
    sort(seg.begin(),seg.end());Tf rig=0;
    for(vector<pair<double,double>>::iterator iter=seg.begin(); iter != seg.end(); iter++){
     if(sign(rig-iter->first)>= 0){
      rig=max(rig,iter->second);}else{
      getarea(i,rig,iter->first);rig=iter->second;}}
    if(!sign(rig)) arc+= r[i]*r[i]*PI;
    else getarea(i,rig,2*PI);}}return pol/2.0+arc;}
}CU;

Tf area_of_triangle(PT a,PT b,PT c){
 return fabs(cross(b-a,c-a)*0.5);}
//-1 if strictly inside,0 if on the polygon,1 if strictly outside
int is_point_in_triangle(PT a,PT b,PT c,PT p){
 if(sign(cross(b-a,c-a))<0)swap(b,c);
 int c1=sign(cross(b-a,p-a));
 int c2=sign(cross(c-b,p-b));
 int c3=sign(cross(a-c,p-c));
 if(c1<0||c2<0||c3<0)return 1;
 if(c1+c2+c3 != 3)return 0;return-1;
}
Tf perimeter(vector<PT>&p){
 Tf ans=0; int n=p.size();
 for(int i=0; i<n; i++)ans+= dist(p[i],p[(i+1)% n]);
  return ans;}
Tf area(vector<PT>&p){
 Tf ans=0; int n=p.size();
 for(int i=0; i<n; i++)ans+= cross(p[i],p[(i+1)% n]);
  return fabs(ans)*0.5;}
//centroid of a(possibly non-convex)polygon,
//assuming that the coordinates are listed in a clockwise or
//counterclockwise fashion.  Note that the centroid is often known as
//the "center of gravity" or "center of mass".
PT centroid(vector<PT>&p){
 int n=p.size(); PT c(0,0);Tf sum=0;
 for(int i=0; i<n; i++)sum+= cross(p[i],p[(i+1)% n]);
  Tf scale=3.0*sum;for(int i=0; i<n; i++){
  int j=(i+1)% n;c=c+(p[i]+p[j])*cross(p[i],p[j]);}
 return c/scale;
}
//0 if cw,1 if ccw
bool get_direction(vector<PT>&p){
 Tf ans=0; int n=p.size();
 for(int i=0; i<n; i++)ans+= cross(p[i],p[(i+1)% n]);
  if(sign(ans)>0)return 1;return 0;
}
//it returns a point such that the sum of distances
//from that point to all points in p  is minimum//O(n log^2 MX)
PT geometric_median(vector<PT>p){
 auto tot_dist=[&](PT z){Tf res=0;
  for(int i=0; i<p.size(); i++)res+= dist(p[i],z);
   return res;
};
 auto findY=[&](Tf x){
  Tf yl =-1e5,yr=1e5;for(int i=0; i<60; i++){
   Tf ym1=yl+(yr-yl)/3;Tf ym2=yr-(yr-yl)/3;
   Tf d1=tot_dist(PT(x,ym1)), d2=tot_dist(PT(x,ym2));
   if(d1<d2)yr=ym2;else yl=ym1;}
  return pair<double,double>(yl,tot_dist(PT(x,yl)));
};
 Tf xl =-1e5,xr=1e5;
 for(int i=0; i<60; i++){
  Tf xm1=xl+(xr-xl)/3, xm2=xr-(xr-xl)/3;
  Tf y1,d1,y2,d2;auto z=findY(xm1);
  y1=z.first; d1=z.second;z=findY(xm2);
  y2=z.first; d2=z.second;if(d1<d2)xr=xm2;else xl=xm1;
 }return{xl,findY(xl).first};
}
vector<PT>convex_hull(vector<PT>&p){
 if(p.size()<= 1)return p;vector<PT>v=p;
 sort(v.begin(),v.end());vector<PT>up,dn;for(auto&p:v){
  while(up.size()>1 && orientation(up[up.size()-2],up.back(),p)>= 0){
   up.pop_back();}
  while(dn.size()>1 && orientation(dn[dn.size()-2],dn.back(),p)<= 0){
   dn.pop_back();}up.push_back(p);dn.push_back(p);}
 v=dn;if(v.size()>1)v.pop_back();
 reverse(up.begin(),up.end());up.pop_back();
 for(auto&p:up){v.push_back(p);}
 if(v.size()==2 && v[0]==v[1])v.pop_back();return v;
}
//checks if convex or not
bool is_convex(vector<PT>&p){
 bool s[3]; s[0]=s[1]=s[2]=0;
 int n=p.size();for(int i=0; i<n; i++){int j=(i+1)% n;
  int k=(j+1)% n;s[sign(cross(p[j]-p[i],p[k]-p[i]))+1]=1;
  if(s[0] && s[2])return 0;}return 1;
}
//-1 if strictly inside,0 if on the polygon,1 if strictly outside
//it must be strictly convex,otherwise make it strictly convex first
int is_point_in_convex(vector<PT>&p,const PT&x){//O(log n)
 int n=p.size(); assert(n >= 3);
 int a=orientation(p[0],p[1],x);
 int b=orientation(p[0],p[n-1],x);if(a<0||b>0)return 1;
 int l=1,r=n-1;while(l+1<r){int mid=l+r >> 1;
  if(orientation(p[0],p[mid],x)>= 0)l=mid;else r=mid;
}
 int k=orientation(p[l],p[r],x);if(k<= 0)return-k;
 if(l==1 && a==0)return 0;if(r==n-1 && b==0)return 0;
 return-1;
}
bool is_point_on_polygon(vector<PT>&p,const PT&z){
 int n=p.size();for(int i=0; i<n; i++){
  if(is_point_on_seg(p[i],p[(i+1)% n],z))return 1;
 }return 0;
}
//returns 1e9 if the point is on the polygon
int winding_number(vector<PT>&p,const PT&z){//O(n)
 if(is_point_on_polygon(p,z))return 1e9;
 int n=p.size(),ans=0;for(int i=0; i<n;++i){
  int j=(i+1)% n;bool below=p[i].y<z.y;
  if(below !=(p[j].y<z.y)){
   auto orient=orientation(z,p[j],p[i]);
   if(orient==0)return 0;
   if(below==(orient>0))ans+= below?1 :-1;}
 }return ans;
}
//-1 if strictly inside,0 if on the polygon,1 if strictly outside
int is_point_in_polygon(vector<PT>&p,const PT&z){//O(n)
 int k=winding_number(p,z);return k==1e9?0:k==0?1 :-1;
}
//id of the vertex having maximum dot product with z
//polygon must need to be convex
//top-upper right vertex
//for minimum dot prouct negate z and return-dot(z,p[id])
int extreme_vertex(vector<PT>&p,const PT&z,const int top){//O(log n)///not tested
 int n=p.size();if(n==1)return 0;
 Tf ans=dot(p[0],z); int id=0;
 if(dot(p[top],z)>ans)ans=dot(p[top],z),id=top;
 int l=1,r=top-1;while(l<r){
  int mid=l+r >> 1;
  if(dot(p[mid+1],z)>= dot(p[mid],z))l=mid+1;
  else r=mid;
}
 if(dot(p[l],z)>ans)ans=dot(p[l],z),id=l;
 l=top+1,r=n-1;while(l<r){
  int mid=l+r >> 1;
  if(dot(p[(mid+1)% n],z)>= dot(p[mid],z))l=mid+1;
  else r=mid;
}l %= n;
 if(dot(p[l],z)>ans)ans=dot(p[l],z),id=l;return id;
}
Tf diameter(vector<PT>&p){
 int n=(int)p.size();if(n==1)return 0;
 if(n==2)return dist(p[0],p[1]);Tf ans=0;
 int i=0,j=1;while(i<n){
  while(cross(p[(i+1)% n]-p[i],p[(j+1)% n]-p[j])>= 0){
   ans=max(ans,dist2(p[i],p[j]));j=(j+1)% n;}
  ans=max(ans,dist2(p[i],p[j]));i++;}
 return sqrt(ans);
}
Tf width(vector<PT>&p){
 int n=(int)p.size();if(n<= 2)return 0;
 Tf ans=inf;int i=0,j=1;
 while(i<n){
  while(cross(p[(i+1)% n]-p[i],p[(j+1)% n]-p[j])>= 0)j=(j+1)% n;
  ans=min(ans,dist_from_point_to_line(p[i],p[(i+1)% n],p[j]));
  i++;}return ans;
}
//minimum perimeter
Tf minimum_enclosing_rectangle(vector<PT>&p){
 int n=p.size();if(n<= 2)return perimeter(p);
 int mndot=0; Tf tmp=dot(p[1]-p[0],p[0]);
 for(int i=1; i<n; i++){if(dot(p[1]-p[0],p[i])<= tmp){
   tmp=dot(p[1]-p[0],p[i]);mndot=i;}}
 Tf ans=inf;int i=0,j=1,mxdot=1;while(i<n){
  PT cur=p[(i+1)% n]-p[i];
  while(cross(cur,p[(j+1)% n]-p[j])>= 0)j=(j+1)% n;
  while(dot(p[(mxdot+1)% n],cur)>= dot(p[mxdot],cur))mxdot=(mxdot+1)% n;
  while(dot(p[(mndot+1)% n],cur)<= dot(p[mndot],cur))mndot=(mndot+1)% n;
  ans=min(ans,2.0*((dot(p[mxdot],cur)/cur.norm()-
   dot(p[mndot],cur)/ cur.norm())+
  dist_from_point_to_line(p[i],p[(i+1)% n],p[j])));i++;}
 return ans;
}
//given n points,find the minimum enclosing circle of the points
//call convex_hull()before this for faster solution
//expected O(n)
circle minimum_enclosing_circle(vector<PT>p){///vector<PT>&p
 random_shuffle(p.begin(),p.end());
 int n=p.size();circle c(p[0],0);
 for(int i=1; i<n; i++){
  if(sign(dist(c.p,p[i])-c.r)>0){c=circle(p[i],0);
   for(int j=0; j<i; j++){
    if(sign(dist(c.p,p[j])-c.r)>0){
     c=circle((p[i]+p[j])/2,dist(p[i],p[j])/2);
     for(int k=0; k<j; k++){
      if(sign(dist(c.p,p[k])-c.r)>0){
       c=circle(p[i],p[j],p[k]);}}}}}}return c;
}
//not necessarily convex,boundary is included in the intersection
//returns total intersected length
Tf polygon_line_intersection(vector<PT>p,PT a,PT b){
 int n=p.size();p.push_back(p[0]);line l=line(a,b);
 Tf ans=0.0;vector<pair<double,int>>vec;
 for(int i=0; i<n; i++){int s1=sign(cross(b-a,p[i]-a));
  int s2=sign(cross(b-a,p[i+1]-a));
  if(s1==s2)continue;line t=line(p[i],p[i+1]);
  PT inter=(t.v*l.c-l.v*t.c)/cross(l.v,t.v);
  Tf tmp=dot(inter,l.v);int f;
  if(s1>s2)f=s1 && s2?2:1;else f=s1 && s2 ?-2 :-1;
  vec.push_back(make_pair(tmp,f));}
 sort(vec.begin(),vec.end());
 for(int i=0,j=0; i+1<(int)vec.size(); i++){
  j+= vec[i].second;
  if(j)ans+= vec[i+1].first-vec[i].first;}
 ans=ans/sqrt(dot(l.v,l.v));p.pop_back();return ans;
}
//minimum distance from a point to a convex polygon
//it assumes point does not lie strictly inside the polygon
Tf dist_from_point_to_polygon(vector<PT>&v,PT p){//O(log n)
 int n=(int)v.size();if(n<= 3){Tf ans=inf;
  for(int i=0; i<n; i++)ans=min(ans,
   dist_from_point_to_seg(v[i],v[(i+1)% n],p));
   return ans;
}
 PT bscur,bs=angle_bisector(v[n-1],v[0],v[1]);
 int ok,i,pw=1,ans=0,sgncur,sgn=sign(cross(bs,p-v[0]));
 while(pw<= n)pw<<= 1;while((pw >>= 1)){
  if((i=ans+pw)<n){
   bscur=angle_bisector(v[i-1],v[i],v[(i+1)% n]);
   sgncur=sign(cross(bscur,p-v[i]));
   ok=sign(cross(bs,bscur))>= 0?(sgn >= 0||
    sgncur<= 0):(sgn >= 0 && sgncur<= 0);
   if(ok)ans=i,bs=bscur,sgn=sgncur;}}
 return dist_from_point_to_seg(v[ans],v[(ans+1)% n],p);
}
//minimum distance from convex polygon p to line ab
//returns 0 is it intersects with the polygon
//top-upper right vertex
Tf dist_from_polygon_to_line(vector<PT>&p,PT a,PT b,
int top){/*O(log n)*/PT orth=(b-a).perp();
 if(orientation(a,b,p[0])>0)orth=(a-b).perp();
 int id=extreme_vertex(p,orth,top);
if(dot(p[id]-a,orth)>0)return 0.0;/*if orth and a are in the same half of the line,then poly and line intersects*/
return dist_from_point_to_line(a,b,p[id]);//does not intersect
}
//minimum distance from a convex polygon to another convex polygon
Tf dist_from_polygon_to_polygon(vector<PT>&p1,vector<PT>&p2){//O(n log n)
 Tf ans=inf;for(int i=0; i<p1.size(); i++){
  ans=min(ans,dist_from_point_to_polygon(p2,p1[i]));}
 for(int i=0; i<p2.size(); i++){
  ans=min(ans,dist_from_point_to_polygon(p1,p2[i]));}
 return ans;
}
//maximum distance from a convex polygon to another convex polygon
Tf maximum_dist_from_polygon_to_polygon(vector<PT>&u,vector<PT>&v){//O(n)
 int n=(int)u.size(),m=(int)v.size();Tf ans=0;
 if(n<3||m<3){for(int i=0; i<n; i++){
   for(int j=0;j<m;j++)ans=max(ans,dist2(u[i],v[j]));}
 return sqrt(ans);}
if(u[0].x>v[0].x)swap(n,m),swap(u,v);
int i=0,j=0,step=n+m+10;
while(j+1<m && v[j].x<v[j+1].x)j++;while(step--){
 if(cross(u[(i+1)% n]-u[i],v[(j+1)% m]-v[j])>= 0)j=(j+1)% m;
 else i=(i+1)% n;ans=max(ans,dist2(u[i],v[j]));}
return sqrt(ans);
}
pair<PT,int>point_poly_tangent(vector<PT>&p,PT Q,int dir,int l,int r){
 while(r-l>1){int mid=(l+r)>> 1;
  bool pvs=orientation(Q,p[mid],p[mid-1])!=-dir;
  bool nxt=orientation(Q,p[mid],p[mid+1])!=-dir;
  if(pvs && nxt)return{p[mid],mid};
  if(!(pvs||nxt)){
   auto p1=point_poly_tangent(p,Q,dir,mid+1,r);
   auto p2=point_poly_tangent(p,Q,dir,l,mid-1);
   return orientation(Q,p1.first,p2.first)==dir?p1:p2;
  }
  if(!pvs){if(orientation(Q,p[mid],p[l])==dir)r=mid-1;
   else if(orientation(Q,p[l],p[r])==dir)r=mid-1;
   else l=mid+1;}if(!nxt){
   if(orientation(Q,p[mid],p[l])==dir)l=mid+1;
   else if(orientation(Q,p[l],p[r])==dir)r=mid-1;
   else l=mid+1;}
 }
 pair<PT,int>ret={p[l],l};
 for(int i=l+1; i<= r; i++)
  ret=orientation(Q,ret.first,p[i])!= dir?
 make_pair(p[i],i):ret;return ret;
}
//(cw,ccw)tangents from a point that is outside this convex polygon
//returns indexes of the points
pair<int,int>tangents_from_point_to_polygon(vector<PT>&p,PT Q){
 int cw=point_poly_tangent(p,Q,1,0,(int)p.size()-1).second;
 int ccw=point_poly_tangent(p,Q,-1,0,(int)p.size()-1).second;
 return make_pair(cw,ccw); 
}
//a and b are strictly convex polygons of DISTINCT points
//returns a convex hull of their minkowski sum with distinct points
vector<PT>minkowski_sum(vector<PT>&a,vector<PT>&b){
 int n=(int)a.size(),m=(int)b.size();
int i=0,j=0;//assuming a[i] and b[j] both are(left,bottom)-most points
vector<PT>c;c.push_back(a[i]+b[j]);
while(i+1<n||j+1<m){PT p1=a[i]+b[(j+1)% m];
 PT p2=a[(i+1)% n]+b[j];
 int t=orientation(c.back(),p1,p2);
 if(t >= 0)j=(j+1)% m;if(t<= 0)i=(i+1)% n,p1=p2;
 if(t==0)p1=a[i]+b[j];if(p1==c[0])break;
 c.push_back(p1);}
return c;
}