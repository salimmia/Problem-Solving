int ar[mx][mx],ST[mx][mx][LOG],Jump_LOG[mx];
void Build_sparse_square(int N){
 for(int l=0;(1<<l)<=N;l++){
  for(int i=1;i+(1<<l)<N;i++){
   for(int j=1;j+(1<<l)<N;j++){
    if(l==0)ST[i][j][l]=dp[i][j];
    else{
     int val1=max(ST[i][j][l-1], ST[i+(1<<(l-1))][j][l-1]);
     int val2=max(ST[i][j+(1<<(l-1))][l-1], ST[i+(1<<(l-1))][j+(1<<(l-1))][l-1]);
     ST[i][j][l]=max(val1,val2);
    }}}}
}
int query(int i,int j,int l){
 int lg=Jump_LOG[l],add=1<<lg,re1,re2;
 re1=max(ST[i][j][lg],ST[i+l-add][j][lg]);
 re2=max(ST[i][j+l-add][lg], ST[i+l-add][j+l-add][lg]);
 return max(re1,re2);
}
