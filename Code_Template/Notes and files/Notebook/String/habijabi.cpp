ll Set(ll N, ll pos)  return N = N | (1LL << pos);
ll Reset(ll N, ll pos)  return N = N & ~(1LL << pos);
bool chk(ll N, ll pos) return (bool)(N & (1LL << pos));
__builtin_ctz(); __builtin_popcount();
/*bitset<mx>bt;
bt.set(); bt.reset();
bt.count() ; bt._Find_first() // first 1 idx
bt._Find_next() // next one bit
for (int i = bt._Find_first(); i < mx; i = bt._Find_next())*/
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
ios_base::sync_with_stdio(0); cin.tie(0);
#define watch2(x,y) cout<< _LINE_ << "says:" 
<<#x<<" = "<<x<<" "<<#y<<" = "<<y <<endl;
/*Linux: s.sh + gen.cpp:
for ((i = 1; i < 100; i++)); do
 . / gen $i > int
 . / a<int>out1
 . / brute<int>out2
 diff out1 out2 || break
 Done*/
mt19937_64 rng(chrono::steady_clock::now().
time_since_epoch().count());
ll my_rand(ll l, ll r)
return uniform_int_distribution<ll>(l, r)(rng);
/*#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int,null_type, less<int>,rb_tree_tag
,tree_order_statistics_node_update> ordered_set;
how many numbers are smaller than a given num
 order_of_key(num)
kth value *os.find_by_order(kth) 0 base*/
