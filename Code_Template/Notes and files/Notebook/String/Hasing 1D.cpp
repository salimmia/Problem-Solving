/*backup prime
307,367,1040160883,1066517951,1e9+7,1e9+9, 1072857881,1000004249
*/
struct Hash_dui{
 ll base,mod;int sz;
 vector<int>Rev,Forw,P;
 Hash_dui(){}
 Hash_dui(const char* s,ll b,ll m){
 sz=strlen(s),base=b,mod=m;
 Rev.resize(sz+2,0), Forw.resize(sz+2,0), P.resize(sz+2,1);
 for(int i=1;i<=sz;i++) P[i]=(base*P[i-1])%mod;
 for(int i=1;i<=sz;i++) Forw[i]=(Forw[i-1]*base+ (s[i-1]-'a'+1))%mod;
 for(int i=sz;i>=1;i--) Rev[i]=(Rev[i+1]*base+ (s[i-1]-'a'+1))%mod;
 }
 void Single_char_ad(char cc){
 P.push_back((P.back()*base)% mod);
 Forw.push_back((Forw.back()*base+ (cc-'a'+1))% mod);
 }
 inline int Range_Hash(int l,int r){
 int re_hash = Forw[r+1]-((ll)P[r-l+1]*Forw[l]%mod);
 if(re_hash<0)re_hash+=mod;
 return re_hash;
 }
 inline int Reverse_Hash(int l,int r){
 int re_hash = Rev[l+1]-((ll)P[r-l+1]*Rev[r+2]%mod);
 if(re_hash<0)re_hash+=mod;
 return re_hash;
 }
};
struct Hash_Main{
 Hash_dui h1,h2;
 Hash_Main(){}
 Hash_Main(const char* s){
 h1=Hash_dui(s,1949313259, 2091573227);
 h2=Hash_dui(s,1997293877, 2117566807);
 }
 void Char_Add(char cc){
 h1.Single_char_ad(cc);
 h2.Single_char_ad(cc);
 }
 /// 0 base index
 inline ll Range_Hash(int l,int r){
  return ((ll)h1.Range_Hash(l,r)<<32) ^ h2.Range_Hash(l,r);
 }
 inline ll Reverse_Hash(int l,int r){
  return ((ll)h1.Reverse_Hash(l,r)<<32) ^ h2.Reverse_Hash(l,r);
 }
};
Hash_Main h_ek(ch);

