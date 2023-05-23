#define bitwiseXOR
//#define bitwiseAND
//#define bitwiseOR
void FWHT(vector <ll> &p, bool inverse){
 int n = p.size();
 while(n&(n-1)) {p.push_back(0);n++;}
 for(int len = 1; 2*len <= n; len <<= 1){
  for(int i = 0; i < n; i += len+len) {
   for(int j = 0; j < len; j++) {
    ll u = p[i+j],v = p[i+len+j];
     #ifdef bitwiseXOR
     p[i+j] = u+v; p[i+len+j] = u-v;
     #endif // bitwiseXOR
     #ifdef bitwiseAND
     if(!inverse){p[i+j]=v;p[i+len+j]=u+v;}
     else{p[i+j]=v-u;p[i+len+j] = u;}
     #endif // bitwiseAND
     #ifdef bitwiseOR
     if(!inverse){p[i+j]=u+v;p[i+len+j]=u;}
     else{p[i+j]=v;p[i+len+j]=u-v;}
     #endif // bitwiseOR
   }
  }
 }
 #ifdef bitwiseXOR
 if(inverse) {
  for(int i = 0; i < n; i++)p[i] /= n;
 }
 #endif // bitwiseXOR
}
//FWHT(A,0);for i A[i]*=A[i];FWHT(A,1)
