struct node {
 bool endmark; node *next[26+1];
 node(){
  endmark=false;
  for(int i=0;i<26;i++)next[i]=NULL;
 }
}*root;
void insert(char ch[],int len){
 node* curr=root;
 for(int i=0;i<len;i++){
  int id=ch[i]-'a';
  if(curr->next[id]==NULL)
      curr->next[id]=new node();
  curr=curr->next[id];
 }
 curr->endmark=true;
}
bool search(char ch[],int len){
 node* curr=root;
 for(int i=0;i<len;i++){
  int id=ch[i]-'a';
  if(curr->next[id]==NULL)return false;
  curr=curr->next[id];
 }
 return curr->endmark;
}
bool prefix_search(char ch[],int len){
 node* curr=root;
 for(int i=0;i<len;i++){
  int id=ch[i]-'a';
  if(curr->next[id]==NULL)return false;
  curr=curr->next[id];
 }
 return true;
}
bool is_Empty(node* curr){
 for(int i=0;i<26;i++)
 {
     if(curr->next[i])return false;
 }
 return true;
}
// remove a string from trie that is inserted
node* remove(node* curr,char ch[],int dep=0){
 if(curr==NULL)return NULL;
 if(dep==strlen(ch)){
     if(curr->endmark)curr->endmark=false;
     if(is_Empty(curr)){
         delete(curr);curr=NULL;
     }
     return curr;
 }
 int id=ch[dep]-'a';
 curr->next[id]=remove(curr->next[id],ch,dep+1);
 if(is_Empty(curr) && curr->endmark==false){
  delete(curr); curr=NULL;
 }
 return curr;
}
// destroy the trie
void del(node* curr){
 for(int i=0;i<26;i++)
  if(curr->next[i])del(curr->next[i]);
 delete(curr);
}
root=new node();
