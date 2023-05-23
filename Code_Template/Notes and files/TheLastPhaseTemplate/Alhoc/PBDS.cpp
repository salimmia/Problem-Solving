#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
solve(){
 ordered_set os;
  // 10. how many numbers are smaller than a given value(7)
 cout << os.order_of_key(7);
  // 12. how many numbers are greater than a given value(7)
 cout << os.size() - os.order_of_key(8) << "\n";
  // 14. if the given numbers are sorted in ascending order, what is the k'th number
 cout << *os.find_by_order(2) << "\n";
  // 16. delete the k'th smallest number
 os.erase(os.find_by_order(k));
  // 22. what is the smallest number which is greater than or equal to a given number(7) 
 cout << *os.lower_bound(7) << "\n";
  // 23. what is the smallest number which is greater than to a given number(7)
 cout << *os.upper_bound(7) << "\n";
}