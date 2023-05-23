int ST[mx][mx][MAX_logN][MAX_logN]; 
int Jump_LOG[505];
void Build_2D_Sparse(){
 for(int i=1;i<=n;i++){
  for(int j=1;j<=m;j++)
   ST[i][j][0][0]=ar[i][j];
  for(int l=1;(1<<l)<=m;l++){
   int pre=1<<(l-1);
   for(int j=1;j+pre<=m;j++){
    ST[i][j][0][l]=max(ST[i][j][0][l-1], ST[i][j+pre][0][l-1]);
   }}
 }
 for(int l=1;(1<<l)<=n;l++){
  int pre=1<<(l-1);
  for(int i=1;i+pre<=n;i++){
   for(int k=0;(1<<k)<=m;k++){
    for(int j=1;j<=m;j++){
     ST[i][j][l][k]=max(ST[i][j][l-1][k], ST[i+pre][j][l-1][k]);
    }}}}
}
int query(int i,int j,int p,int q){
 int boro_jum1=Jump_LOG[p-i+1], re1, re2;
 int boro_jum2=Jump_LOG[q-j+1];
 int pre1=1<<boro_jum1,pre2=1<<boro_jum2;
 re1=max(ST[i][j][boro_jum1][boro_jum2],
     ST[i][q-pre2+1][boro_jum1][boro_jum2]);
 re2=max(ST[p-pre1+1][j][boro_jum1][boro_jum2],
  ST[p-pre1+1][q-pre2+1][boro_jum1][boro_jum2]);
 return max(re1,re2);
}
