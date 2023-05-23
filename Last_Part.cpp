//contains all points p such that:cross(b-a,p-a) >=0
struct HP{ 
 PT a,b;
 HP(){ }
 HP(PT a,PT b) :a(a) ,b(b){ }
 HP(const HP&rhs) :a(rhs.a) ,b(rhs.b){ }
 int operator<(const HP&rhs) const{ 
  PT p=b-a;
  PT q=rhs.b-rhs.a;
  int fp=(p.y<0 ||(p.y==0&&p.x<0));
  int fq=(q.y<0 ||(q.y==0&&q.x<0));
  if(fp !=fq) return fp==0;
  if(cross(p,q)) return cross(p,q) >0;
  return cross(p,rhs.b-a) <0;
 }
 PT line_line_intersection(PT a,PT b,PT c,PT d){ 
  b=b-a;d=c-d;c=c-a;
  return a+b*cross(c,d) /cross(b,d);
 }
 PT intersection(const HP&v){ 
  return line_line_intersection(a,b,v.a,v.b);
 }
};
int check(HP a,HP b,HP c){ 
return cross(a.b-a.a,b.intersection(c) -a.a) >-eps;//-eps to include polygons of zero area(straight lines,points) 
}
//consider half-plane of counter-clockwise side of each line
//if lines are not bounded add infinity rectangle
//returns a convex polygon,a point can occur multiple times though
//complexity:O(n log(n)) 
vector<PT>half_plane_intersection(vector<HP>h){ 
 sort(h.begin() ,h.end());
 vector<HP>tmp;
 for(int i=0;i<h.size();i++){ 
  if(!i || cross(h[i].b-h[i].a,h[i-1].b-h[i-1].a)){ 
   tmp.push_back(h[i]);
  }
 }
 h=tmp;
 vector<HP>q(h.size() +10);
 int qh=0,qe=0;
 for(int i=0;i<h.size();i++){ 
  while(qe-qh>1&&!check(h[i],q[qe-2],q[qe-1])) qe--;
  while(qe-qh>1&&!check(h[i],q[qh],q[qh+1])) qh++;
  q[qe++]=h[i];
 }
 while(qe-qh>2&&!check(q[qh],q[qe-2],q[qe-1])) qe--;
 while(qe-qh>2&&!check(q[qe-1],q[qh],q[qh+1])) qh++;
 vector<HP>res;
 for(int i=qh;i<qe;i++) res.push_back(q[i]);
  vector<PT>hull;
 if(res.size() >2){ 
  for(int i=0;i<res.size();i++){ 
   hull.push_back(res[i].intersection(res[(i+1) %((int) res.size()) ]));
  }
 }
 return hull;
}
//a and b are strictly convex polygons of DISTINCT points
//returns a convex hull of their minkowski sum with distinct points
vector<PT>minkowski_sum(vector<PT>&a,vector<PT>&b){ 
 int n=(int) a.size() ,m=(int) b.size();
int i=0,j=0;//assuming a[i] and b[j] both are(left,bottom) -most points
vector<PT>c;
c.push_back(a[i]+b[j]);
while(i+1<n || j+1<m){ 
 PT p1=a[i]+b[(j+1) % m];
 PT p2=a[(i+1) % n]+b[j];
 int t=orientation(c.back() ,p1,p2);
 if(t>=0) j=(j+1) % m;
 if(t<=0) i=(i+1) % n,p1=p2;
 if(t==0) p1=a[i]+b[j];
 if(p1==c[0]) break;
 c.push_back(p1);
}
return c;
}
//system should be translated from circle center
double triangle_circle_intersection(PT c,double r,PT a,PT b){ 
 double sd1=dist2(c,a) ,sd2=dist2(c,b);
 if(sd1>sd2) swap(a,b) ,swap(sd1,sd2);
 double sd=dist2(a,b);
 double d1=sqrtl(sd1) ,d2=sqrtl(sd2) ,d=sqrt(sd);
 double x=abs(sd2-sd-sd1) /(2*d);
 double h=sqrtl(sd1-x*x);
 if(r>=d2) return h*d/2;
 double area=0;
 if(sd+sd1<sd2){ 
  if(r<d1) area=r*r*(acos(h/d2) -acos(h/d1)) /2;
  else{ 
   area=r*r*(acos(h/d2) -acos(h/r)) /2;
   double y=sqrtl(r*r-h*h);
   area+=h*(y-x) /2;
  }
 }
 else{ 
  if(r<h) area=r*r*(acos(h/d2) +acos(h/d1)) /2;
  else{ 
   area+=r*r*(acos(h/d2) -acos(h/r)) /2;
   double y=sqrtl(r*r-h*h);
   area+=h*y/2;
   if(r<d1){ 
    area+=r*r*(acos(h/d1) -acos(h/r)) /2;
    area+=h*y/2;
   }
   else area+=h*x/2;
  }
 }
 return area;
}
//intersection between a simple polygon and a circle
double polygon_circle_intersection(vector<PT>&v,PT p,double r){ 
 int n=v.size();
 double ans=0.00;
 PT org={ 0,0};
 for(int i=0;i<n;i++){ 
  int x=orientation(p,v[i],v[(i+1) % n]);
  if(x==0) continue;
  double area=triangle_circle_intersection(org,r,v[i]-p,v[(i+1) % n]-p);
  if(x<0) ans-=area;
  else ans+=area;
 }
 return ans*0.5;
}
//find a circle of radius r that contains as many points as possible
//O(n^2 log n);
double maximum_circle_cover(vector<PT>p,double r,circle&c){ 
 int n=p.size();
 int ans=0;
 int id=0;double th=0;
 for(int i=0;i<n;++i){ 
//maximum circle cover when the circle goes through this point
  vector<pair<double,int>>events={{ -PI,+1},{ PI,-1}};
  for(int j=0;j<n;++j){ 
   if(j==i) continue;
   double d=dist(p[i],p[j]);
   if(d>r*2) continue;
   double dir=(p[j]-p[i]).arg();
   double ang=acos(d/2/r);
   double st=dir-ang,ed=dir+ang;
   if(st>PI) st-=PI*2;
   if(st<=-PI) st+=PI*2;
   if(ed>PI) ed-=PI*2;
   if(ed<=-PI) ed+=PI*2;
   events.push_back({ st,+1});
   events.push_back({ ed,-1});
   if(st>ed){ events.push_back({ -PI,+1});
   events.push_back({ +PI,-1});}
  }
  sort(events.begin() ,events.end());
  int cnt=0;
  for(auto&&e:events){ 
   cnt+=e.second;
   if(cnt>ans){ ans=cnt;id=i;th=e.first;}
  }
 }
 PT w=PT(p[id].x+r*cos(th) ,p[id].y+r*sin(th));
c=circle(w,r);//best_circle
return ans;
}
//radius of the maximum inscribed circle in a convex polygon
double maximum_inscribed_circle(vector<PT>p){ 
 int n=p.size();
 if(n<=2) return 0;
 double l=0,r=20000;
 while(r-l>eps){ 
  double mid=(l+r) *0.5;
  vector<HP>h;
  const int L=1e9;
  h.push_back(HP(PT(-L,-L) ,PT(L,-L)));
  h.push_back(HP(PT(L,-L) ,PT(L,L)));
  h.push_back(HP(PT(L,L) ,PT(-L,L)));
  h.push_back(HP(PT(-L,L) ,PT(-L,-L)));
  for(int i=0;i<n;i++){ 
   PT z=(p[(i+1) % n]-p[i]).perp();
   z=z.truncate(mid);
   PT y=p[i]+z,q=p[(i+1) % n]+z;
   h.push_back(HP(p[i]+z,p[(i+1) % n]+z));
  }
  vector<PT>nw=half_plane_intersection(h);
  if(!nw.empty()) l=mid;
  else r=mid;
 }
 return l;
}