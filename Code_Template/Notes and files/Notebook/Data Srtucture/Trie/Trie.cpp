/* Max xor and Min xor subarray */
int Trie[mx*30][2],End[mx*30],ar[mx],st=1;
void Insert(int val){
 int cur=1;
 for(int i=29;i>=0;i--){
  int bit=0;
  if(((1<<i) & val))bit=1;
  if(Trie[cur][bit]==0)Trie[cur][bit]=++st;
  cur=Trie[cur][bit];
 }
 End[cur]=val;
}
// for max query just go to opposite bit
int query_min(int val){
 int cur=1;
 for(int i=29;i>=0;i--){
  int bit=0;
  if(((1<<i) & val))bit=1;
  if(Trie[cur][bit])cur=Trie[cur][bit];
  else if(Trie[cur][bit^1])cur=Trie[cur][bit^1];
 }
 return End[cur]^val;
}
void solve(){
 st=1; memset(End,0,sizeof(End));
 int re; memset(Trie,0,sizeof(Trie));
 re_min=INT_MAX,re_max=0,suffix=0;Insert(0);
 for(int i=1;i<=n;i++){
  suffix^=ar[i];
  re_min=min(re_min,query_min(suffix));
  re_max=max(re_max,query_max(suffix));
  Insert(suffix);
 }
}
