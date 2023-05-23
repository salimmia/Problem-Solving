De - arrangement: d(0) = 1; d(1) = 0;
d(n) = (n−1)⋅(d(n−1) + d(n−2));
inner circle radius, r = area * s;
outer circle area, A = (abc) / 4R;
N point Polygon's Regions, R = (E – V + 2)
V = (n + nC4) E = (n * (n – 1) + nC4 * 4) / 2

0*nC0+1*nC1+2*nC2+3*nC3+..+n*nCn=n*2^(n-1)
0Cr+1Cr+2Cr+3Cr+4Cr+5Cr+6Cr+..+nCr=(n+1)C(r+1)
(nC0)^2+(nC1)^2+(nC2)^2+..+(nCn)^2=(2*n)Cn
Stars and Bars when stars >= 0 (n+k-1)C(k-1)

Ash Explanation per bucket condition 0<=k_i<x_i
for 0<=k_i, RESULT1 =(n+k-1)C(k-1)
for k_i>=x_i, val_i=kCi*(n-i*x_i+k-1)C(k-1)
RESULT2 = ((-k)^1)*val_1+((-k)^2)*val_2+((-k)^1)*val_3+.....((-k)^k)*val_k
[But some time we have not calculated overall val1 to valk ,Because (n-(x*kth)+k-1) will be <0]
Final result=RESULT1-RESULT2
///catalan number Cn=(1/(n+1))*((2*n)Cn)
In other form Cn=((2*n)C(n))-((2*n)C(n+1))