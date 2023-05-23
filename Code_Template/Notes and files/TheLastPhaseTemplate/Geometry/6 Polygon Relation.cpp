//given n points,find the minimum enclosing circle of the points
//call convex_hull() before this for faster solution
//expected O(n) 
circle minimum_enclosing_circle(vector<PT>p){ ///vector<PT>&p
 random_shuffle(p.begin() ,p.end());
 int n=p.size();
 circle c(p[0],0);
 for(int i=1;i<n;i++){ 
  if(sign(dist(c.p,p[i]) -c.r) >0){ 
   c=circle(p[i],0);
   for(int j=0;j<i;j++){ 
    if(sign(dist(c.p,p[j]) -c.r) >0){ 
     c=circle((p[i]+p[j]) /2,dist(p[i],p[j]) /2);
     for(int k=0;k<j;k++){ 
      if(sign(dist(c.p,p[k]) -c.r) >0){ 
       c=circle(p[i],p[j],p[k]);
      }
     }
    }
   }
  }
 }
 return c;
}
//returns a vector with the vertices of a polygon with everything
//to the left of the line going from a to b cut away.
vector<PT>cut(vector<PT>&p,PT a,PT b){ ////may remove from notebook
 vector<PT>ans;
 int n=(int) p.size();
 for(int i=0;i<n;i++){ 
  double c1=cross(b-a,p[i]-a);
  double c2=cross(b-a,p[(i+1) % n]-a);
  if(sign(c1) >=0) ans.push_back(p[i]);
  if(sign(c1*c2) <0){ 
   if(!is_parallel(p[i],p[(i+1) % n],a,b)){ 
    PT tmp;line_line_intersection(p[i],p[(i+1) % n],a,b,tmp);
    ans.push_back(tmp);
   }
  }
 }
 return ans;
}
//not necessarily convex,boundary is included in the intersection
//returns total intersected length
double polygon_line_intersection(vector<PT>p,PT a,PT b){ 
 int n=p.size();
 p.push_back(p[0]);
 line l=line(a,b);
 double ans=0.0;
 vector<pair<double,int>>vec;
 for(int i=0;i<n;i++){ 
  int s1=sign(cross(b-a,p[i]-a));
  int s2=sign(cross(b-a,p[i+1]-a));
  if(s1==s2) continue;
  line t=line(p[i],p[i+1]);
  PT inter=(t.v*l.c-l.v*t.c) /cross(l.v,t.v);
  double tmp=dot(inter,l.v);
  int f;
  if(s1>s2) f=s1&&s2?2:1;
  else f=s1&&s2?-2:-1;
  vec.push_back(make_pair(tmp,f));
 }
 sort(vec.begin() ,vec.end());
 for(int i=0,j=0;i+1<(int) vec.size();i++){ 
  j+=vec[i].second;
  if(j) ans+=vec[i+1].first-vec[i].first;
 }
 ans=ans/sqrt(dot(l.v,l.v));
 p.pop_back();
 return ans;
}
pair<PT,PT>convex_line_intersection(vector<PT>&p,PT a,PT b){ 
 return{{ 0,0},{ 0,0}};
}
//minimum distance from a point to a convex polygon
//it assumes point does not lie strictly inside the polygon
double dist_from_point_to_polygon(vector<PT>&v,PT p){ //O(log n) 
 int n=(int) v.size();
 if(n<=3){ 
  double ans=inf;
  for(int i=0;i<n;i++) ans=min(ans,dist_from_point_to_seg(v[i],v[(i+1) % n],p));
   return ans;
 }
 PT bscur,bs=angle_bisector(v[n-1],v[0],v[1]);
 int ok,i,pw=1,ans=0,sgncur,sgn=sign(cross(bs,p-v[0]));
 while(pw<=n) pw<<=1;
 while((pw>>=1)){ 
  if((i=ans+pw) <n){ 
   bscur=angle_bisector(v[i-1],v[i],v[(i+1) % n]);
   sgncur=sign(cross(bscur,p-v[i]));
   ok=sign(cross(bs,bscur)) >=0?(sgn>=0 || sgncur<=0) :(sgn>=0&&sgncur<=0);
   if(ok) ans=i,bs=bscur,sgn=sgncur;
  }
 }
 return dist_from_point_to_seg(v[ans],v[(ans+1) % n],p);
}
//minimum distance from convex polygon p to line ab
//returns 0 is it intersects with the polygon
//top-upper right vertex
double dist_from_polygon_to_line(vector<PT>&p,PT a,PT b,int top){ //O(log n) ///NOT TESTED
 PT orth=(b-a).perp();
 if(orientation(a,b,p[0]) >0) orth=(a-b).perp();
 int id=extreme_vertex(p,orth,top);
if(dot(p[id]-a,orth) >0) return 0.0;//if orth and a are in the same half of the line,then poly and line intersects
return dist_from_point_to_line(a,b,p[id]);//does not intersect
}
//minimum distance from a convex polygon to another convex polygon
double dist_from_polygon_to_polygon(vector<PT>&p1,vector<PT>&p2){ //O(n log n) 
 double ans=inf;
 for(int i=0;i<p1.size();i++){ 
  ans=min(ans,dist_from_point_to_polygon(p2,p1[i]));
 }
 for(int i=0;i<p2.size();i++){ 
  ans=min(ans,dist_from_point_to_polygon(p1,p2[i]));
 }
 return ans;
}
//maximum distance from a convex polygon to another convex polygon
double maximum_dist_from_polygon_to_polygon(vector<PT>&u,vector<PT>&v){ //O(n) 
 int n=(int) u.size() ,m=(int) v.size();
 double ans=0;
 if(n<3 || m<3){ 
  for(int i=0;i<n;i++){ 
   for(int j=0;j<m;j++) ans=max(ans,dist2(u[i],v[j]));
  }
 return sqrt(ans);
}
if(u[0].x>v[0].x) swap(n,m) ,swap(u,v);
int i=0,j=0,step=n+m+10;
while(j+1<m&&v[j].x<v[j+1].x) j++;
while(step--){ 
 if(cross(u[(i+1) % n]-u[i],v[(j+1) % m]-v[j]) >=0) j=(j+1) % m;
 else i=(i+1) % n;
 ans=max(ans,dist2(u[i],v[j]));
}
return sqrt(ans);
}
pair<PT,int>point_poly_tangent(vector<PT>&p,PT Q,int dir,int l,int r){ 
 while(r-l>1){ 
  int mid=(l+r) >>1;
  bool pvs=orientation(Q,p[mid],p[mid-1]) !=-dir;
  bool nxt=orientation(Q,p[mid],p[mid+1]) !=-dir;
  if(pvs&&nxt) return{ p[mid],mid};
  if(!(pvs || nxt)){ 
   auto p1=point_poly_tangent(p,Q,dir,mid+1,r);
   auto p2=point_poly_tangent(p,Q,dir,l,mid-1);
   return orientation(Q,p1.first,p2.first) ==dir?p1:p2;
  }
  if(!pvs){ 
   if(orientation(Q,p[mid],p[l]) ==dir) r=mid-1;
   else if(orientation(Q,p[l],p[r]) ==dir) r=mid-1;
   else l=mid+1;
  }
  if(!nxt){ 
   if(orientation(Q,p[mid],p[l]) ==dir) l=mid+1;
   else if(orientation(Q,p[l],p[r]) ==dir) r=mid-1;
   else l=mid+1;
  }
 }
 pair<PT,int>ret={ p[l],l};
 for(int i=l+1;i<=r;i++) ret=orientation(Q,ret.first,p[i]) !=dir?make_pair(p[i],i) :ret;
  return ret;
}
//(cw,ccw) tangents from a point that is outside this convex polygon
//returns indexes of the points
pair<int,int>tangents_from_point_to_polygon(vector<PT>&p,PT Q){ 
 int cw=point_poly_tangent(p,Q,1,0,(int) p.size() -1).second;
 int ccw=point_poly_tangent(p,Q,-1,0,(int) p.size() -1).second;
 return make_pair(cw,ccw);
}
//calculates the area of the union of n polygons(not necessarily convex).
//the points within each polygon must be given in CCW order.
//complexity:O(N^2) ,where N is the total number of points
double rat(PT a,PT b,PT p){ 
 return !sign(a.x-b.x) ?(p.y-a.y) /(b.y-a.y) :(p.x-a.x) /(b.x-a.x);
};
double polygon_union(vector<vector<PT>>&p){ 
 int n=p.size();
 double ans=0;
 for(int i=0;i<n;++i){ 
  for(int v=0;v<(int) p[i].size();++v){ 
   PT a=p[i][v],b=p[i][(v+1) % p[i].size() ];
   vector<pair<double,int>>segs;
   segs.emplace_back(0,0) ,segs.emplace_back(1,0);
   for(int j=0;j<n;++j){ 
    if(i !=j){ 
     for(size_t u=0;u<p[j].size();++u){ 
      PT c=p[j][u],d=p[j][(u+1) % p[j].size() ];
      int sc=sign(cross(b-a,c-a)) ,sd=sign(cross(b-a,d-a));
      if(!sc&&!sd){ 
       if(sign(dot(b-a,d-c)) >0&&i>j){ 
        segs.emplace_back(rat(a,b,c) ,1) ,segs.emplace_back(rat(a,b,d) ,-1);
       }
      }
      else{ 
       double sa=cross(d-c,a-c) ,sb=cross(d-c,b-c);
       if(sc>=0&&sd<0) segs.emplace_back(sa/(sa-sb) ,1);
       else if(sc<0&&sd>=0) segs.emplace_back(sa/(sa-sb) ,-1);
      }
     }
    }
   }
   sort(segs.begin() ,segs.end());
   double pre=min(max(segs[0].first,0.0) ,1.0) ,now,sum=0;
   int cnt=segs[0].second;
   for(int j=1;j<segs.size();++j){ 
    now=min(max(segs[j].first,0.0) ,1.0);
    if(!cnt) sum+=now-pre;
    cnt+=segs[j].second;
    pre=now;
   }
   ans+=cross(a,b) *sum;
  }
 }
 return ans*0.5;
}