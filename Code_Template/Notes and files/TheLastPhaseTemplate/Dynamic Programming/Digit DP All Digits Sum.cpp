ll dp[15][2][400][2];
const ll mpos=11;
char ch[40];
void convert(ll n){
 for(ll i=0; i<mpos; i++){
  ch[i]=(n%10)+'0';
  n/=10;
 }
 reverse(ch,ch+mpos);
 ch[mpos]=0;
}
ll func(ll pos,ll smallornot,ll digitvalcnt,ll startornot){
 if(pos==mpos)
  return digitvalcnt;
 if(dp[pos][smallornot][digitvalcnt][startornot]!=-1)
  return dp[pos][smallornot][digitvalcnt][startornot];
 ll be=0, en=9,re=0;
 if(!smallornot)
  en=ch[pos]-'0';
 for(ll i=be; i<=en; i++)
 {
  ll ismallornot= smallornot | (i<en);
  ll idigitvalcnt=digitvalcnt+ i;
  ll istartornot= startornot | (i!=0);
  re+=func(pos+1,ismallornot,idigitvalcnt,istartornot);
 }
 return dp[pos][smallornot][digitvalcnt][startornot]=re;
}
func(0,0,0,0);