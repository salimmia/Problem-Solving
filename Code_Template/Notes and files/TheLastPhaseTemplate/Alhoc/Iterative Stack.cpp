template<typename T, typename Container = std::deque<T>>
class iterable_stack
: public std::stack<T, Container>
{
 using std::stack<T, Container>::c;
public:
 auto begin() { return std::begin(c); }
 auto end() { return std::end(c); }

 auto begin() const { return std::begin(c); }
 auto end() const { return std::end(c); }
};
iterable_stack<int> st;
st.push(2);
for(auto i: st)
 std::cout << i << ' ';