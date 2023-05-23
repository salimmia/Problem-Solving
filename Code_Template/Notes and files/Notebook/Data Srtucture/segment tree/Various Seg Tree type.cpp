/*Bracket Sequence */
struct info{
 int open,close,ans;
};
info Merge(info a,info b){
 info re;
 int valid=min(a.open,b.close);
 re.open=a.open+b.open-valid;
 re.close=a.close+b.close-valid;
 re.ans=a.ans+b.ans+valid;
 /* works for maximum length of correct bracket sequence in l to r range*/
 return re;
}
/* Kth element merge sort tree */
int query(int node,int be,int en,int l,int r,int k){
 if(be==en)return seg[node][0];
 int pos = upper_bound(seg[node*2+1].begin(), seg[node*2+1].end(),r)
 -lower_bound(seg[node*2+1].begin(), seg[node*2+1].end(),l);
 int mid=(be+en)/2;
 if(pos>=k) {
  return query(node*2+1,be,mid,l,r,k);
 }
 else return query(node*2+2,mid+1,en,l,r,k-pos);
}
/* Delete Type Id Found */
int id_query(int node,int be,int en,int pos){
 if(be==en)return be;
 int mid=(be+en)/2;
 if(Present[node*2]>=pos){
  return id_query(node*2,be,mid,pos);
 }
 else return id_query(node*2+1,mid+1,en, posPresent[node*2]);
}
/* Range max subarray / suffix-prefix sum*/
struct info{
 ll max_pref,max_suf,ans,sum;
 void Merge(info p1,info p2){
  sum=p1.sum+p2.sum;
  max_pref=max(p1.max_pref,p1.sum+p2.max_pref);
  max_suf=max(p2.max_suf,p2.sum+p1.max_suf);
  ans=max(max(p1.ans,p2.ans), p1.max_suf+p2.max_pref);
 }
};
void Relax(int node,int be,int en){
 if(!cur[node])return;
 Tree[node].sum=Lazy[node]*(en-be+1);
 Tree[node].max_pref=max(0LL,Tree[node].sum);
 Tree[node].max_suf=max(0LL,Tree[node].sum);
 Tree[node].ans=max(0LL,Tree[node].sum);
 if(be!=en){
  Lazy[node*2]=Lazy[node];
  Lazy[node*2+1]=Lazy[node];
  cur[node*2]=true;
  cur[node*2+1]=true;
 }
 cur[node]=false;
 Lazy[node]=0;
}
