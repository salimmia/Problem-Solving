ll dp[15][2][400][2];
const ll mpos=11; char ch[40];
void convert(ll n){
 for(ll i=0; i<mpos; i++){
  ch[i]=(n%10)+'0'; n/=10;
 }
 reverse(ch,ch+mpos); ch[mpos]=0;
}
ll func(ll pos,ll Smlornot, ll dcnt,ll Strt){
 if(pos==mpos) return dcnt;
 ll &val=dp[pos][Smlornot][dcnt][Strt];
 if(val!=-1) return val;
 ll be=0, en=9,re=0;
 if(!Smlornot) en=ch[pos]-'0';
 for(ll i=be; i<=en; i++){
  ll iSml= Smlornot | (i<en);
  ll idigitvalcnt=dcnt+ i;
  ll isStrt= Strt | (i!=0);
  re+=func(pos+1,iSml,idigitvalcnt,isStrt);
 }
 return val=re;
}
func(0,0,0,0);
