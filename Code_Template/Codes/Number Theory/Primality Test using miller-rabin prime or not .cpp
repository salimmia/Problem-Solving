#include <cstdio>
#include <cstdlib>

using namespace std;

typedef unsigned long long ull;

ull mulmod(ull a, ull b, ull c){
	ull x = 0,y = a%c;

	while(b>0){
		if(b&1) x = (x+y)%c;
		y = (y<<1)%c;
		b >>= 1;
	}

	return x;
}

ull pow(ull a, ull b, ull c){
	ull x = 1, y = a;

	while(b>0){
		if(b&1) x = mulmod(x,y,c);
		y = mulmod(y,y,c);
		b >>= 1;
	}

	return x;
}

bool miller_rabin(ull p, int it){
	if(p<2) return false;
	if(p==2) return true;
	if((p&1)==0) return false;

	ull s = p-1;
	while(s%2==0) s >>= 1;

	while(it--){
		ull a = rand()%(p-1)+1,temp = s;
		ull mod = pow(a,temp,p);

		if(mod==-1 || mod==1) continue;

		while(temp!=p-1 && mod!=p-1){
			mod = mulmod(mod,mod,p);
			temp <<= 1;
		}

		if(mod!=p-1) return false;
	}

	return true;
}

int main(){
	int test;
	ull N;
	scanf("%d",&test);

	while(test--){
		scanf("%llu",&N);
		printf("%s\n",miller_rabin(N,18)? "YES" : "NO");
	}

	return 0;
}
