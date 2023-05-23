/*Complexity : O(n log n)
dp[i][j]=min(dp[i-1][k-1]+Cost(k,j)[k<=j]
Condition for D&C:
Cost(L+1,j+1)-Cost(L+1,j)<=Cost(k+1,j+1)- Cost(k+1,j) for any(L<k<j)For Max Query
Cost(L+1,j+1)-Cost(L+1,j)>=Cost(k+1,j+1)- Cost(k+1,j) for any(L<k<j)For Min Query*/
ll dp[2][MAX];
void compute(int K,int L,int R,int OptL,
 int OptR){ if(L > R) return;
 int mid = (L + R)/2,optNow = -1;
 dp[K & 1][mid] = 0;
 for(int i=OptL;i<=min(OptR,mid);i++){
  ll tmp =dp[(K & 1)^1][i-1]+Cost(i,mid);
  if(tmp >= dp[K & 1][mid]){
    dp[K & 1][mid] = tmp;optNow = i;
  }
 }
 compute(K, L, mid - 1, OptL, optNow);
 compute(K, mid + 1, R, optNow, OptR);
}
for(int i=1;i<=n;i++)dp[1][i]=Cost(1,i);
for(int i=2;i<=K;i++)compute(i,1,n,1,n);
printf("%lld\n", dp[K & 1][n]);
