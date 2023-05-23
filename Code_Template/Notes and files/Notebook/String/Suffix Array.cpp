int wa[mx],wb[mx],wv[mx],Ws[mx];
int sa[mx],Rank[mx],LCP[mx];
int cmp(int *r,int a,int b,int l){return r[a]==r[b] && r[a+l]==r[b+l];}
void buildSA(string s,int* sa,int n,int m){
int i,j,p,*x=wa,*y=wb,*t;
for(i=0; i<m; i++)Ws[i]=0;
for(i=0; i<n; i++)Ws[x[i]=s[i]]++;
for(i=1; i<m; i++) Ws[i]+=Ws[i-1];
for(i=n-1; i>=0; i--) sa[--Ws[x[i]]]=i;
for(j=1,p=1; p<n; j<<=1,m=p){
 for(p=0,i=n-j; i<n; i++)y[p++]=i;
 for(i=0; i<n; i++) if(sa[i]>=j) y[p++]=sa[i]-j;
 for(i=0; i<n; i++) wv[i]=x[y[i]];
 for(i=0; i<m; i++) Ws[i]=0;
 for(i=0; i<n; i++) Ws[wv[i]]++;
 for(i=1; i<m; i++) Ws[i]+=Ws[i-1];
 for(i=n-1; i>=0; i--) sa[--Ws[wv[i]]]=y[i];
 for(t=x,x=y,y=t,p=1,x[sa[0]]=0,i=1; i<n; i++)
  x[sa[i]]=cmp(y,sa[i-1],sa[i],j) ? p-1 : p++;
 }
}
//Kasai's LCP algorithm (O(n))
void buildLCP(string s,int *sa,int n){
int i,j,k=0;
for(i=1; i<=n; i++) Rank[sa[i]]=i;
for(i=0; i<n; LCP[Rank[i++]]=k)
for(k?k--:0, j=sa[Rank[i]-1]; s[i+k]==s[j+k]; k++);
}
pair<int,int> Patterntern_occurence(string Text,string Pattern){
 int n=Text.size();
 int m=Pattern.size();
 int be=1,en=n;
 while(be<en){
 int mid = (en+be)/2;
 int ok=0;
 for(int i=0;i<m;i++){
 if(Text[i+sa[mid]]>Pattern[i]){ok=1;break;}
 if(Text[i+sa[mid]]<Pattern[i]){ok=-1;break;}
 }
 if(ok+1) en=mid;
 else be=mid+1;
 }
 bool ok = 1;
 for(int i=0;i<m;i++) if(Text[i+sa[be]]!=Pattern[i]){ok=0;break;}
 if(!ok) return {-1,-1};
 pair<int,int> re;
 re.first=be;
 be=1,en=n;
 while(be<en){
 int mid = (en+be)/2;
 int ok=0;
 for(int i=0;i<m;i++){
 if(Text[i+sa[mid]]>Pattern[i]){ok=1;break;}
 if(Text[i+sa[mid]]<Pattern[i]){ok=-1;break;}
 }
 if(ok>0) en=mid;
 else be=mid+1;
 }
 ok = 1;
 for(int i=0;i<m;i++) if(Text[i+sa[en]]!=Pattern[i]){ok=0;break;}
 if(!ok) en--;
 re.second=en;
 return re;
}
/*for LCP from index i to index j. Set ST[i][0]=LCP[i] in sparse table
just run a query from min(Rank[i-1],Rank[j-1])+1 to max(Rank[i-1],Rank[j-1])*/
int n=s.size();
buildSA(s,sa,n+1,130);
buildLCP(s,sa,n);
sa[i] 1 base index;
Rank[i] 0 base index;
LCP[i] 1 base index;
