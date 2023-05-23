ll Set(ll N, ll pos)  return N = N | (1LL << pos);
ll Reset(ll N, ll pos)  return N = N & ~(1LL << pos);
bool chk(ll N, ll pos) return (bool)(N & (1LL << pos));
__builtin_ctz(); __builtin_popcount();