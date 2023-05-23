#define MAX 105
#define ll long long int
const ll MOD = 1e9 + 7;
const ll MOD2 = MOD * MOD * 3;
/* 1 base row columun index */
struct Matrix{
 int row, col;
 ll m[MAX][MAX];
 Matrix() {memset(m,0,sizeof(m));}
 void Set(int r,int c) {row = r; col = c;}
 Matrix(int r,int c)
 {memset(m,0,sizeof(m)); Set(r,c);}
 void normalize(){
  for(int i=1; i<=row; i++){
   for(int j=1; j<=col; j++){
    m[i][j] %= MOD;
    if(m[i][j] < 0) m[i][j] += MOD;
   }
  }
 }
};
Matrix Multiply(Matrix A,Matrix B){
 Matrix ans(A.row,B.col);
 for(int i=1;i<=A.row;i++){
  for(int j=1;j<=B.col;j++){
   ans.m[i][j]=0;
   ll sm = 0;
   for(int k=1;k<=A.col;k++){
    sm+=(A.m[i][k]*B.m[k][j]);
    if(sm >= MOD2) sm -= MOD2;
   }
   ans.m[i][j] = sm % MOD;
  }
 }
 return ans;
}
Matrix Power(Matrix mat,ll p){
 Matrix res(mat.row , mat.col);
 Matrix ans(mat.row , mat.col);
 int n = ans.row;
 for(int i=1;i<=n;i++){
  for(int j=1;j<=n;j++){
   ans.m[i][j]=0;
   res.m[i][j]=mat.m[i][j];
  }
  ans.m[i][i]=1;
 }
 while(p){
  if(p&1) ans=Multiply(ans,res);
  res=Multiply(res,res);
  p=p/2;
 }
 return ans;
}
