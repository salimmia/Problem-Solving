ll a[MAX], n; //0 base index
ll maxxor(){
 int r = 0; ll ret = 0;
 for(int c = 63; c >= 0; c--){
  int idx = -1;
  for(int i = r; i < n && idx < 0; i++)
   if(a[i] >> c & 1) idx = i;
  if(idx == -1) continue;
  swap(a[r], a[idx]);
  for(int i = 0; i < n; i++) if(i != r)
   if(a[i] >> c & 1) a[i] ^= a[r];
  r++;
 }
 for(int i = 0; i < n; i++) 
  ret = max(ret, ret ^ a[i]);
 return ret;
}