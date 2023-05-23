
/// 1 indexed
/// can be used for min max gcd lcm etc. where if we taking one element multiple times ans doesn't changes 
///example gcd(2,3,4) == gcd(2, 2, 3, 3, 4) 
const int logmxn = 21;

int n;
int A[mxn];
int Log[mxn];
int M[mxn][logmxn];

void buildSparse(){
    for(int i=1;i<=n;i++) M[i][0]=A[i];
    for(int i=2;i<=n;i++) Log[i]=Log[i-1] + !(i&(i-1));
    
    for(int j=1; (1<<j)<=n ;j++){
        for(int i=1; (i+ (1<<j)-1) <=n; i++)
            M[i][j]=max(M[i][j-1],M[i + (1<<(j-1))][j - 1]);
    }
}

int query(int i,int j){
    int k=Log[j-i+1];
    return max(M[i][k],M[j-(1<<k)+1][k]);
}
