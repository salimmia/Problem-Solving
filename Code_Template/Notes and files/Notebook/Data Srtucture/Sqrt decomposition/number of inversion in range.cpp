// MO's template
// For segment Tree update
if(be==en)Tree[node]+=val;
Tree[node]=Tree[node*2]+Tree[node*2+1];
using namespace Segment_Tree;
/* at first compress the value of arrat=y*/
int left=que[1].l;
int right=left-1;
for(int i=1;i<=q;i++){
 node Now=que[i];
 while(left<Now.l){
  re-=query(1,1,n,1,ar[left]-1);
  update(1,1,n,ar[left++],-1);
 }
 while(left>Now.l){
  re+=query(1,1,n,1,ar[--left]-1);
  update(1,1,n,ar[left],1);    
 }
 while(right<Now.r){
  re+=query(1,1,n,ar[++right]+1,n);
  update(1,1,n,ar[right],1);
 }
 while(right>Now.r){
  re-=query(1,1,n,ar[right]+1,n);
  update(1,1,n,ar[right--],-1);
 }
 ans[Now.id]=re;
}
