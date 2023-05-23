

auto cmp = [](int a, int b) { return ... };
std::set<int, decltype(cmp)> s;


next use equal in custom comparator like a <= b
it will give you run time error

