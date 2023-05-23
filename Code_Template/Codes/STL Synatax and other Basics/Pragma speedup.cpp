///cf blog post
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

///cf blog comment
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

///cf blog comment
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

///cf blog comment
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("avx,avx2,tune=native")


///better speed up
///ashraful - shamim
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

///best speed up
///All of Them Together!
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma comment(linker, "/stack:200000000")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")



///https://codeforces.com/contest/911/problem/G
/// O(n*q) accepted in 1903 ms  ( here n<=2*10^5 and q <=2*10^5 )
/// But without pragma 3000 ms in test and GOT TLE
///good speed up
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//# include <iostream>
//# include <stdio.h>
//using namespace std;
//
//unsigned char a[200000];
//
//int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(nullptr);
//    int n;
//    scanf("%d", &n);
//    for (int i = 0; i < n; ++i) {
//        scanf("%hhu", &a[i]);
//    }
//    int q;
//    scanf("%d", &q);
//    while (q--) {
//        int l, r;
//        unsigned char x, y;
//        scanf("%d%d%hhu%hhu", &l, &r, &x, &y);
//        for (int i = l-1; i < r; i++) {
//            a[i] = a[i] == x ? y : a[i];
//        }
//    }
//    for (int i = 0; i < n; ++i) {
//        printf("%hhu ", a[i]);
//    }
//}
////O(n^2) test... it seems possible for this... but it shoudnt...


