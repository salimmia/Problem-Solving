long long CRT_weak(vector<long long>A, vector<long long>B) {
    long long X=0;
    long long N=1;
    long long y,z;
    for(int i=0; i<B.size(); i++)
        N*=B[i];
    for(int i=0; i<A.size(); i++) {
        y=N/B[i];
        z=modInv(y,B[i]);
        X+=(A[i]*y*z);
        X%=N;
    }
    return (X+N)%N;
}
