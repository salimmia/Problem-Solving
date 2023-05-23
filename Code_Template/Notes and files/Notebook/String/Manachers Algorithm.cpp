int oddPlen[mx],evenPlen[mx];
void Manachers(){
 int l=0,r=-1;
 for(int i=0;i<n;i++){
 int k=(i>r)?1:min(oddPlen[l+r-i],r-i+1);
 while(k<=i && i+k<n && ch[i-k]==ch[i+k])k++;
 oddPlen[i]=k--;
 if(i+k>r){l=i-k;r=i+k;}
 }
 l=0,r=-1;
 for(int i=0;i<n;i++){
 int k=(i>r)?0:min(evenPlen[l+r-i+1],r-i+1);
 while(k+1<=i && i+k<n && ch[i-k-1]==ch[i+k])k++;
 evenPlen[i]=k--;
 if(i+k>r){l=i-k-1;r=i+k;}
 }
}
for index i
oddPlen[i]*2-1,evenPlen[i]*2
