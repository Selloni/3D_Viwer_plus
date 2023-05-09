#include  <sstream>
#include <iostream>

int main () {
  std::stringstream os;
  os << "v 1.000000 -1.000000 -1.000000";
  double i, j, k = 0;
  std::string ss {};
  os >> i >> k >> j;
  std::cout << i << k << j ;

}