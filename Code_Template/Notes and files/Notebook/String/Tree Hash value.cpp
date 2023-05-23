string ch[2];#define PI pair<ll,ll>
vector<int>g[mx][2];int sub[mx][2];ll H[mx][2];
ll Base[]={1040160883,1066517951};
ll mod[]={1072857881,1000004249};
ll mul(ll a,ll b,int ty){
 a*=b;if(a>=mod[ty])a%=mod[ty];return a;
}
ll add(ll a,ll b,int ty){
 a+=b;if(a>=mod[ty])a-=mod[ty];return a;
}
PI get_hash(int u,int l,int ty){
 sub[u][ty]=1;PI re={0,0};
 for(int v:g[u][ty]){
  pair<ll,ll>tem=get_hash(v,l+1,ty);
  re.first=add(re.first,tem.first,0);
  re.second=add(re.second,tem.second,1);
  sub[u][ty]+=sub[v][ty];
 }
 re.first = add(re.first, mul(add(H[l][0],sub[u][ty],0), sub[u][ty],0),0);
 re.second = add(re.second, mul(add(H[l][1],sub[u][ty],1), sub[u][ty],1),1);
 return re;
}
H[0][0]=H[0][1]=1;
for(int i=1;i<mx;i++)
 for(int j=0;j<1;j++) H[i][j]=mul(H[i-1][j],Base[j],j);
